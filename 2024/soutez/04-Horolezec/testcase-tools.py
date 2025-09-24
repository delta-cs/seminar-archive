#!/usr/bin/env python3
import argparse
import os
import glob
import chardet
import subprocess
import zipfile

class tcol:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

VERBOSE = False # global variable holding whether do verbose prints or not
verb_print = lambda message, col=tcol.ENDC: print(col+message+tcol.ENDC) if VERBOSE else None
cprint = lambda message, col=tcol.ENDC: print(col+message+tcol.ENDC)


#============================================================
# GENERAL
#============================================================

def get_out_files(root_dir):
    out_files = glob.glob(f"*ans*", root_dir=root_dir) + glob.glob(f"*out*", root_dir=root_dir)
    return out_files




#============================================================
# FIX ENCODING
#============================================================

def fix_encoding_file(file_path):
    '''
    Change file's encoding to UTF-8 LE (the UNIX standard)
    '''
    verb_print(f"  fixing encoding of {file_path}")

    with open(file_path, "rb") as file:
        raw_data = file.read()
        detected_encoding = chardet.detect(raw_data)["encoding"]

    # Read the file with the detected encoding
    try:
        with open(file_path, "r", encoding=detected_encoding) as file:
            content = file.read()
    except:
        verb_print(f"ERROR: skipping \"{file_path}\", the file could not be processed!")
        return 1
    
    # Normalize line endings to LF and prepare UTF-8 content
    normalized_content = content.replace("\r\n", "\n").replace("\r", "\n")

    if len(normalized_content) > 0 and normalized_content[-1] != '\n': normalized_content += '\n' # ensure the file always ends with \n
    
    # Write the file back with UTF-8 encoding
    with open(file_path, "w", encoding="utf-8", newline="\n") as file:
        file.write(normalized_content)



def fix_encoding_dir(path, recursive=False):
    '''
    Change all contained files encoding to UTF-8 LE (the UNIX standard)
    '''

    for f in glob.glob(f"{path}/**", recursive=recursive):
        if(os.path.isfile(f) and any(x not in f for x in ('in', 'ans', 'out'))): # if is file and has in/out/ans in name
            fix_encoding_file(f)



def fix_encoding(args :argparse.Namespace):
    verb_print(f"TASK: fix encoding of {args.path}", tcol.HEADER)

    
    if os.path.isdir(args.path):
        verb_print(f"  directory detected, processing")
        fix_encoding_dir(args.path, args.recursive)


    elif os.path.isfile(args.path):
        fix_encoding_file(args.path)

    else:
        cprint(f"Error: {args.path} is not a valid file or directory!", tcol.FAIL)
        return 1


    verb_print("TASK DONE", tcol.HEADER)



#============================================================
# GENERATE / CHECK
#============================================================

def gen_check_res(args :argparse.Namespace, gen=True):
    '''
    Run command on all in files, write output to ans or verify if ans is matching
    '''
    verb_print(f"TASK: {(lambda: "generating" if gen else "verifying")()} results", tcol.HEADER)

    test_i = 1
    for in_file in glob.glob(f"**/*in*", root_dir=args.path, recursive=args.recursive):

        in_file_path = f"{args.path}/{in_file}"

        dir_path = f"{args.path}/{os.path.dirname(in_file)}"
        dir_name = os.path.basename(dir_path)

        with open(in_file_path, "r") as f:
            in_txt = f.read()


        if(gen): cmd = args.generate_answers
        else: cmd = args.verify_answers

        verb_print(f"  running {cmd} on {dir_path}")

        process = subprocess.run(
            cmd,
            input=in_txt,
            text=True, # Treat input and output as strings
            capture_output=True, # Capture stdout and stderr
            shell=True
        )
        if process.returncode != 0:
            cprint(f"Error: '{cmd}' failed on '{in_file_path}' with exit code {process.returncode}", tcol.FAIL)


        ans_txt = process.stdout
        

        if gen:
            verb_print("  writing ans.txt")
            with open(f"{dir_path}/ans.txt", "w") as f:
                f.write(ans_txt)

        else:
            verb_print("  searching for ans/out file to compare")

            out_files = get_out_files(dir_path)

            if len(out_files) != 1:
                cprint(f"Error: missing .out/.ans file in {dir_path}", tcol.FAIL)
                continue

            with open(f"{dir_path}/{out_files[0]}", "r") as f:
                orig_ans_txt = f.read()
            
            if ans_txt != orig_ans_txt:
                cprint(f"VERIFICATION WARNING: answer in \"{dir_name}\" does NOT Match answer generated with \"{cmd}\"", tcol.WARNING + tcol.BOLD)
            else:
                verb_print(f"  answer in {dir_name} matching", tcol.OKGREEN)
        
        test_i += 1

    verb_print("TASK DONE", tcol.HEADER)

#============================================================
# ZIP
#============================================================



def make_import_zip(args :argparse.Namespace):
    verb_print(f"TASK: generate {args.name}.zip", tcol.HEADER)

    zipf = zipfile.PyZipFile(f"{args.name}.zip", "w")
    zipf.mkdir("data")
    zipf.mkdir("data/secret")

    zipf.writestr("problem.yaml", f"# autogenerated by testcase-tools.py\nname: '{args.name}'")
    if args.timelimit is not None: zipf.writestr("domjudge-problem.ini", f"# autogenerated by testcase-tools.py\ntimelimit='{args.timelimit}'")
    if args.problem_pdf is not None: zipf.write(args.problem_pdf, "problem.pdf")


    test_i = 1
    for in_file in glob.glob(f"**/*in*", root_dir=args.path, recursive=args.recursive):

        dir_path = f"{args.path}/{os.path.dirname(in_file)}"
        dir_name = os.path.basename(dir_path)

        verb_print(f"  writing problem #{test_i} ({dir_path}) .in and .desc to archive")

        zipf.write(f"{args.path}/{in_file}", f"data/secret/{test_i}.in")
        zipf.writestr(f"data/secret/{test_i}.desc", dir_name)

        verb_print(f"  searching for matching ans/out file")

        out_files = get_out_files(dir_path)

        if len(out_files) != 1:
            cprint(f"Error: missing .out/.ans file in {dir_path}", tcol.FAIL)

        else:
            verb_print(f"  ans/out file found, writing to archive")
            zipf.write(f"{dir_path}/{out_files[0]}", f"data/secret/{test_i}.ans")
        
        test_i += 1

    zipf.close()
    verb_print("TASK DONE", tcol.HEADER)




def main():
    global VERBOSE
    arg_parser = argparse.ArgumentParser()
    # Basic ===============================
    arg_parser.add_argument(
        "path",
        metavar="PATH",
        help="Path to a file or directory containing tests"
    )
    arg_parser.add_argument(
        "-V", "--verbose",
        action="store_true",
        help="enable verbose output"
    )
    arg_parser.add_argument(
        "-r", "--recursive",
        action="store_true",
        help="process directories recursively"
    )
    # Encoding ============================
    arg_parser.add_argument(
        "-f", "--fix-encoding",
        action="store_true",
        help="fix encoding of file(s) to UTF-8 LF"
    )
    # Answers =============================
    arg_parser.add_argument(
        "-g", "--generate-answers",
        metavar="CMD",
        help="run CMD on every in.txt and generate out.txt"
    )
    arg_parser.add_argument(
        "-v", "--verify-answers",
        metavar="CMD",
        help="run CMD for in.txt and verify correctness of out.txt"
    )
    # Zip =================================
    arg_parser.add_argument(
        "-z", "--make-zip",
        action="store_true",
        help="create problem upload zip from directory"
    )
    arg_parser.add_argument(
        "-n", "--name",
        default="unnamed",
        help="specify problem name"
    )
    arg_parser.add_argument(
        "-tl", "--timelimit",
        help="specify problem timelimit (optional)"
    )
    arg_parser.add_argument(
        "-pdf", "--problem-pdf",
        help="specify problem pdf (optional)"
    )

    args = arg_parser.parse_args()
    VERBOSE = args.verbose # set global VERBOSE (used by verbose print)


    if args.fix_encoding: # fix encodingss
        if fix_encoding(args) == 1: return 1


    if args.generate_answers is not None:
        gen_check_res(args)

    if args.verify_answers is not None:
        gen_check_res(args, False)

    
    if args.make_zip:
        make_import_zip(args)




if __name__ == "__main__":
    exit(main())
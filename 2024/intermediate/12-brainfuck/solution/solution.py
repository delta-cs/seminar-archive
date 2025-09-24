import sys

MEM_SIZE = 3000

def read_until(stop_character='') -> str:
    '''
    Read stdin until stop_character is encountered
    '''
    out = ""
    while True:
        c = sys.stdin.read(1)
        if c == stop_character:
            break
        out += c
    return out




def evaluate():
    global code, code_ptr, mem, mem_ptr # using global variables because passing int by reference in python does not really work
    
    starting_code_ptr = code_ptr
    while code_ptr < len(code):
        instruction = code[code_ptr]

        if instruction == '+':
            mem[mem_ptr] += 1
            mem[mem_ptr] %= 256 # emulate 8-bit uint overflow

        elif instruction == '-':
            mem[mem_ptr] -= 1
            mem[mem_ptr] %= 256 # emulate 8-bit uint overflow


        elif instruction == '>':
            mem_ptr += 1
            mem_ptr %= MEM_SIZE
            
        elif instruction == '<':
            mem_ptr -= 1
            mem_ptr %= MEM_SIZE

        
        elif instruction == '[':
            code_ptr += 1
            evaluate() # looping done with recursion
        
        elif instruction == ']':
            if mem[mem_ptr] == 0: # break out of the loop -> exit function
                break
            else: # do the loop all again
                code_ptr = starting_code_ptr
                continue # continue to avoid code_ptr incrementing
        

        elif instruction == '.':
            c = chr(mem[mem_ptr])
            sys.stdout.write(c)
        
        elif instruction == ',':
            c = sys.stdin.read(1)
            mem[mem_ptr] = ord(c)


        code_ptr += 1



if __name__ == "__main__":

    code = read_until('|')
    mem = [0] * MEM_SIZE

    code_ptr = 0
    mem_ptr = 0


    evaluate()


    sys.stdout.write('\n') # write the required trailing newline
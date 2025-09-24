import sys

BRACKETS = {
    '(':')',
    '[':']',
    '{':'}'
}


def getc():
    c = sys.stdin.read(1)
    if c == '': raise EOFError
    return c



def evaluate(end_bracket_type :str):
    try:
        c = getc()
        while True:
            if c in BRACKETS.keys():
                if not evaluate(BRACKETS[c]): return False
                
            if c in BRACKETS.values():
                if end_bracket_type == c: return True
                else: return False
            
            c = getc()

    except EOFError:
        if end_bracket_type == 'EOF':
            return True
        else:
            return False





if __name__ == "__main__":
    if evaluate('EOF'): print("VALID")
    else: print("INVALID")
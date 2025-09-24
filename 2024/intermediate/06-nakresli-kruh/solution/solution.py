import math

paper_size = [int(input()),int(input())]
center = [int(input()),int(input())]
r = int(input())

for y in range(paper_size[1]):
    line = ""
    for x in range(paper_size[0]):
        if(math.sqrt((x-center[0])**2 + (y-center[1])**2) <= r):
            line += "#"
        else:
            line += "."
    print(line)
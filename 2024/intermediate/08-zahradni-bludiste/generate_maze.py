import random

size = [37, 59]


output = []
for y in range(size[1]):
    output_line = []
    for x in range(size[0]):
        # character = random.choice([".", "#"])
        character = '.'
        if(y%2 == 0 and x%2 == 0): character = '#'
        output_line.append(character)

    output.append(output_line)

for i in range((sum(size)**2)//18):
    output[random.randint(0, size[1]-1)][random.randint(0, size[0])-1] = '#'


rand_pos = (lambda : [random.randint(0, size[0]-1), random.randint(0, size[1]-1)])

start_pos = rand_pos()
end_pos = rand_pos()


output[start_pos[1]][start_pos[0]] = "S"
output[end_pos[1]][end_pos[0]] = "E"


print(size[0], size[1])
for line in output:
    line_str = " ".join(line)
    print(line_str)
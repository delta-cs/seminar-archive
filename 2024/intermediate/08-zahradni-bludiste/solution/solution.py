
# finds the end by recursively "flooding" the maze (similar to how pain bucket works in graphical programs)
def flood_fill(maze, start, maze_dimensions):
    maze[start[1]][start[0]] = '#' # we set the current square to wall, so that we don't accidentally try it again

    found = False

    for y in range(-1, 2):
        for x in range(-1, 2):

            if abs(x) == abs(y): # avoid going diagonally
                continue

            next_pos = [start[0]+x, start[1]+y]

            if(next_pos[0] not in range(0, maze_dimensions[0]) or next_pos[1] not in range(0, maze_dimensions[1])): # avoid going out of the maze
                continue

            match maze[next_pos[1]][next_pos[0]]:
                case '.':
                    found = found or flood_fill(maze, next_pos, maze_dimensions) # run recursively untill end is found or entire maze is filled out with walls
                    # found is false by default, if the recursion found end, it will result to False or True, which means the True will get locked in the variable
                case 'E':
                    return True

    return found

            
dimensions = list(map(lambda x: int(x), input().split(" ")))

maze = []
start_position = [-1, -1]
for y in range(dimensions[1]):
    line = input().split(" ")
    if line.count('S') == 1: # if there is Start on the current line
        start_position = [line.index('S'), y] # find position of S on the x axis using .index and save start position
    maze.append(line)
# now we have the input maze in 2D array

if(flood_fill(maze, start_position, dimensions)):
    print("Pruchozi")
else:
    print("Opravit")
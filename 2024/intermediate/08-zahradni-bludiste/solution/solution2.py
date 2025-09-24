import sys
from collections import deque

def main():
    try:
        # Read the first line for dimensions
        first_line = sys.stdin.readline()
        if not first_line:
            print("Opravit")
            return
        tokens = first_line.strip().split()
        if len(tokens) < 2:
            print("Opravit")
            return
        try:
            X = int(tokens[0])
            Y = int(tokens[1])
        except ValueError:
            # If dimensions are not integers
            print("Opravit")
            return

        maze = []
        start = None
        end_present = False

        for row in range(Y):
            line = sys.stdin.readline()
            if not line:
                # Not enough lines for the maze
                print("Opravit")
                return
            cells = line.strip().split()
            if len(cells) != X:
                # Not enough cells in this row
                print("Opravit")
                return
            maze.append(cells)
            if 'S' in cells and start is None:
                start_x = cells.index('S')
                start_y = row
                start = (start_x, start_y)
                # Debug: Print start position
                # print(f"Start found at: ({start_x}, {start_y})")
            if 'E' in cells:
                end_present = True  # At least one 'E' is present
                # Debug: Print end positions
                # print(f"End found in row {row}")

        if not start or not end_present:
            # Start or End position not found
            print("Opravit")
            return

        # Initialize BFS
        queue = deque()
        queue.append(start)
        visited = [[False for _ in range(X)] for _ in range(Y)]
        visited[start_y][start_x] = True

        # Define movement directions: left, right, up, down
        directions = [(-1,0), (1,0), (0,-1), (0,1)]

        while queue:
            x, y = queue.popleft()

            # If the current cell is 'E', maze is passable
            if maze[y][x] == 'E':
                print("Pruchozi")
                return

            # Explore all four directions
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                # Check boundaries
                if 0 <= nx < X and 0 <= ny < Y:
                    if not visited[ny][nx]:
                        if maze[ny][nx] in {'.', 'E'}:
                            visited[ny][nx] = True
                            queue.append((nx, ny))
                            # Debug: Print movement
                            # print(f"Moving to: ({nx}, {ny})")

        # If BFS completes without finding 'E'
        print("Opravit")

    except Exception as e:
        # Any unexpected error results in "Opravit"
        # For debugging purposes, you can uncomment the next line
        # print(f"An error occurred: {e}")
        print("Opravit")

if __name__ == "__main__":
    main()

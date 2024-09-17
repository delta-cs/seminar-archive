import java.util.Scanner;

class Main {
    static final int LEFT = 0;
    static final int UP = 1;
    static final int RIGHT = 2;
    static final int DOWN = 3;

    static final int NONE = 0;
    static final int ROBOT = 1;
    static final int PILLAR = 2;
    static final int BOX = 3;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int w = scanner.nextInt();
        int h = scanner.nextInt();

        int robotX = scanner.nextInt() - 1;
        int robotY = scanner.nextInt() - 1;
        int robotOrientation = LEFT;

        int[][] warehouse = new int[w][h];
        warehouse[robotX][robotY] = ROBOT;

        int p = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < p; i++) {
            warehouse[scanner.nextInt() - 1][scanner.nextInt() - 1] = PILLAR;
        }

        int b = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < b; i++) {
            warehouse[scanner.nextInt() - 1][scanner.nextInt() - 1] = BOX;
        }

        int c = scanner.nextInt();
        for (int i = 0; i < c; i++) {
            char command = scanner.next().charAt(0);

            switch (command) {
                case 'L':
                case 'R':
                    robotOrientation = rotate(robotOrientation, command == 'R');
                    break;

                case 'F':
                    int[] newPosition = moveForward(warehouse, robotX, robotY, robotOrientation);
                    robotX = newPosition[0];
                    robotY = newPosition[1];
                    break;
            }
        }

        printWarehouse(warehouse);
    }

    static int rotate(int currentOrientation, boolean clockwise) {
        if (clockwise) {
            return (currentOrientation + 1) % 4;
        } else {
            return (currentOrientation - 1 + 4) % 4;
        }
    }

    static int[] moveForward(int[][] warehouse, int robotX, int robotY, int orientation) {
        switch (orientation) {
            case LEFT:
                for (int col = robotX - 1; col >= 0; col--) {
                    if (warehouse[col][robotY] == PILLAR) {
                        break;
                    }

                    if (warehouse[col][robotY] == BOX) {
                        continue;
                    }

                    for (int col2 = col + 1; col2 <= robotX; col2++) {
                        warehouse[col2 - 1][robotY] = warehouse[col2][robotY];
                    }

                    warehouse[robotX][robotY] = NONE;
                    return new int[]{robotX - 1, robotY};
                }

                break;

            case RIGHT:
                for (int col = robotX + 1; col < warehouse.length; col++) {
                    if (warehouse[col][robotY] == PILLAR) {
                        break;
                    }

                    if (warehouse[col][robotY] == BOX) {
                        continue;
                    }

                    for (int col2 = col - 1; col2 >= robotX; col2--) {
                        warehouse[col2 + 1][robotY] = warehouse[col2][robotY];
                    }

                    warehouse[robotX][robotY] = NONE;
                    return new int[]{robotX + 1, robotY};
                }

                break;

            case UP:
                for (int row = robotY - 1; row >= 0; row--) {
                    if (warehouse[robotX][row] == PILLAR) {
                        break;
                    }

                    if (warehouse[robotX][row] == BOX) {
                        continue;
                    }

                    for (int row2 = row + 1; row2 <= robotY; row2++) {
                        warehouse[robotX][row2 - 1] = warehouse[robotX][row2];
                    }

                    warehouse[robotX][robotY] = NONE;
                    return new int[]{robotX, robotY - 1};
                }

                break;

            case DOWN:
                for (int row = robotY + 1; row < warehouse[0].length; row++) {
                    if (warehouse[robotX][row] == PILLAR) {
                        break;
                    }

                    if (warehouse[robotX][row] == BOX) {
                        continue;
                    }

                    for (int row2 = row - 1; row2 >= robotY; row2--) {
                        warehouse[robotX][row2 + 1] = warehouse[robotX][row2];
                    }

                    warehouse[robotX][robotY] = NONE;
                    return new int[]{robotX, robotY + 1};
                }

                break;
        }

        return new int[]{robotX, robotY};
    }

    static void printWarehouse(int[][] warehouse) {
        for (int i = 0; i < warehouse.length + 2; i++) {
            System.out.print('.');
        }

        System.out.println();

        for (int row = 0; row < warehouse[0].length; row++) {
            System.out.print('.');

            for (int col = 0; col < warehouse.length; col++) {
                char output = ' ';

                switch (warehouse[col][row]) {
                    case ROBOT:
                        output = 'r';
                        break;

                    case PILLAR:
                        output = 'o';
                        break;

                    case BOX:
                        output = '#';
                        break;
                }

                System.out.print(output);
            }

            System.out.println('.');
        }

        for (int i = 0; i < warehouse.length + 2; i++) {
            System.out.print('.');
        }

        System.out.println();
    }
}

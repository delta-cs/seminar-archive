import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

class Main {
    private static final int LEFT = 0;
    private static final int RIGHT = 1;
    private static final int FORWARD = 2;
    private static final int BACK = 3;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int h = scanner.nextInt();
        int w = scanner.nextInt();

        char[][] floor = new char[h][w];

        List<Character> tileColors = new ArrayList<>();
        Map<Character, Integer> program = new HashMap<>();
        for (int row = 0; row < h; row++) {
            for (int col = 0; col < w; col++) {
                char tile = scanner.next().charAt(0);
                floor[row][col] = tile;

                if (!program.containsKey(tile)) {
                    program.put(tile, LEFT);
                    tileColors.add(tile);
                }
            }
        }

        int cleanerY = scanner.nextInt() - 1;
        int cleanerX = scanner.nextInt() - 1;

        int stationY = scanner.nextInt() - 1;
        int stationX = scanner.nextInt() - 1;

        int totalPossiblePrograms = 0;

        while (true) {
            if (tryProgram(floor, cleanerY, cleanerX, stationY, stationX, program)) {
                totalPossiblePrograms++;
            }

            boolean end = false;
            for (int i = 0; i < tileColors.size(); i++) {
                char tileColor = tileColors.get(i);
                program.put(tileColor, program.get(tileColor) + 1);
                if (program.get(tileColor) > 3) {
                    if (i >= tileColors.size() - 1) {
                        end = true;
                    }

                    program.put(tileColor, 0);
                } else {
                    break;
                }
            }

            if (end) {
                break;
            }
        }

        System.out.println(totalPossiblePrograms);
    }

    private static boolean tryProgram(char[][] floor, int cleanerY, int cleanerX, int stationY, int stationX,
                                      Map<Character, Integer> program) {
        boolean[][] floorVisited = new boolean[floor.length][floor[0].length];

        while (true) {
            char tile = floor[cleanerY][cleanerX];
            switch (program.get(tile)) {
                case LEFT:
                    cleanerX--;
                    break;
                case RIGHT:
                    cleanerX++;
                    break;
                case FORWARD:
                    cleanerY--;
                    break;
                case BACK:
                    cleanerY++;
                    break;
            }

            if (cleanerY < 0 || cleanerY >= floor.length || cleanerX < 0 || cleanerX >= floor[0].length
                    || floorVisited[cleanerY][cleanerX]) {
                return false;
            }

            if (cleanerY == stationY && cleanerX == stationX) {
                return true;
            }

            floorVisited[cleanerY][cleanerX] = true;
        }
    }
}

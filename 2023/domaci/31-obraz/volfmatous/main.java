import java.util.Scanner;

class Main {
    static final int LEFT = 0;
    static final int RIGHT = 1;
    static final int TOP = 2;
    static final int BOTTOM = 3;
    static final char NAIL_CHAR = 'o';
    static final int TOP_EDGE_NAIL_COUNT = 2;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int w = scanner.nextInt();
        int h = scanner.nextInt();

        if (w < 1 || h < 1) {
            return;
        }

        char[][] picture = new char[h][w];

        for (int row = 0; row < h; row++) {
            for (int col = 0; col < w; col++) {
                picture[row][col] = scanner.next().charAt(0);
            }
        }

        int topEdgeSide = getTopEdgeSide(picture);
        printPictureFromSide(picture, topEdgeSide);
    }

    static int getTopEdgeSide(char[][] picture) {
        int nailsCount = 0;

        for (int row = 0; row < picture.length; row++) {
            if (picture[row][0] == NAIL_CHAR) {
                nailsCount++;

                if (nailsCount >= TOP_EDGE_NAIL_COUNT) {
                    return LEFT;
                }
            }
        }

        nailsCount = 0;

        for (int row = 0; row < picture.length; row++) {
            if (picture[row][picture[0].length - 1] == NAIL_CHAR) {
                nailsCount++;

                if (nailsCount >= TOP_EDGE_NAIL_COUNT) {
                    return RIGHT;
                }
            }
        }

        nailsCount = 0;

        for (int col = 0; col < picture[0].length; col++) {
            if (picture[0][col] == NAIL_CHAR) {
                nailsCount++;

                if (nailsCount >= TOP_EDGE_NAIL_COUNT) {
                    return TOP;
                }
            }
        }

        return BOTTOM;
    }

    static void printPictureFromSide(char[][] picture, int side) {
        switch (side) {
            case LEFT:
                for (int col = 0; col < picture[0].length; col++) {
                    for (int row = picture.length - 1; row >= 0; row--) {
                        char output = picture[row][col];

                        if (col == 0 || col == picture[0].length - 1 || row == 0 || row == picture.length - 1) {
                            switch (output) {
                                case '|':
                                    output = '-';
                                    break;

                                case '-':
                                    output = '|';
                                    break;
                            }
                        }

                        System.out.print(output);
                    }

                    System.out.println();
                }

                break;

            case RIGHT:
                for (int col = picture[0].length - 1; col >= 0; col--) {
                    for (int row = 0; row < picture.length; row++) {
                        char output = picture[row][col];

                        if (col == 0 || col == picture[0].length - 1 || row == 0 || row == picture.length - 1) {
                            switch (output) {
                                case '|':
                                    output = '-';
                                    break;

                                case '-':
                                    output = '|';
                                    break;
                            }
                        }

                        System.out.print(output);
                    }

                    System.out.println();
                }

                break;

            case TOP:
                for (char[] row : picture) {
                    for (char col : row) {
                        System.out.print(col);
                    }

                    System.out.println();
                }

                break;

            case BOTTOM:
                for (int row = picture.length - 1; row >= 0; row--) {
                    for (int col = picture[0].length - 1; col >= 0; col--) {
                        System.out.print(picture[row][col]);
                    }

                    System.out.println();
                }

                break;
        }
    }
}

import java.util.Scanner;

class Main {
    static final int SYMBOL_WIN_COUNT = 5;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int w = scanner.nextInt();
        int h = scanner.nextInt();
        int t = scanner.nextInt();
        boolean currentPlayerIsA = scanner.next().equals("A");

        int[][] board = new int[w][h];

        for (int i = 0; i < t; i++) {
            int turnX = scanner.nextInt() - 1;
            int turnY = scanner.nextInt() - 1;

            if (board[turnX][turnY] != 0) {
                System.out.println("invalid");
                System.out.println(i + 1);
                return;
            }

            board[turnX][turnY] = currentPlayerIsA ? 1 : 2;

            if (isWin(board, turnX, turnY)) {
                System.out.println(currentPlayerIsA ? 'A' : 'B');
                System.out.println(i + 1);
                return;
            }

            currentPlayerIsA = !currentPlayerIsA;
        }

        System.out.println('?');
    }

    static boolean isWin(int[][] board, int turnX, int turnY) {
        int symbolCountHorizontal = 0;
        int symbolCountVertical = 0;
        int symbolCountDiagonal1 = 0;
        int symbolCountDiagonal2 = 0;

        for (int i = -SYMBOL_WIN_COUNT + 1; i <= SYMBOL_WIN_COUNT - 1; i++) {
            int x = turnX + i;
            int y = turnY;

            if (hasCoordinates(board, x, y) && board[x][y] == board[turnX][turnY]) {
                symbolCountHorizontal++;
            } else {
                symbolCountHorizontal = 0;
            }

            x = turnX;
            y = turnY + i;

            if (hasCoordinates(board, x, y) && board[x][y] == board[turnX][turnY]) {
                symbolCountVertical++;
            } else {
                symbolCountVertical = 0;
            }

            x = turnX + i;
            y = turnY + i;

            if (hasCoordinates(board, x, y) && board[x][y] == board[turnX][turnY]) {
                symbolCountDiagonal1++;
            } else {
                symbolCountDiagonal1 = 0;
            }

            x = turnX + i;
            y = turnY - i;

            if (hasCoordinates(board, x, y) && board[x][y] == board[turnX][turnY]) {
                symbolCountDiagonal2++;
            } else {
                symbolCountDiagonal2 = 0;
            }

            if (symbolCountHorizontal >= SYMBOL_WIN_COUNT
                    || symbolCountVertical >= SYMBOL_WIN_COUNT
                    || symbolCountDiagonal1 >= SYMBOL_WIN_COUNT
                    || symbolCountDiagonal2 >= SYMBOL_WIN_COUNT) {
                return true;
            }
        }

        return false;
    }

    static boolean hasCoordinates(int[][] board, int x, int y) {
        return x >= 0 && x < board.length && y >= 0 && y < board[0].length;
    }
}

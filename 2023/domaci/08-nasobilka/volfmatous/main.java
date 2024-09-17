import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int p = scanner.nextInt();

        printMultiplicationTable(n, p);
    }

    static void printMultiplicationTable(int n, int count) {
        for (int multiplier = 1; multiplier <= count; multiplier++) {
            System.out.println(n * multiplier);
        }
    }
}

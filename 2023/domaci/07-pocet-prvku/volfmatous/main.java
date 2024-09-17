import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int inputCount = 0;

        while (scanner.hasNextLine()) {
            scanner.nextLine();
            inputCount++;
        }

        System.out.println(inputCount);
    }
}

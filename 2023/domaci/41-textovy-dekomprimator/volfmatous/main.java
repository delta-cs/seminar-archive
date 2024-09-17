import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String text = scanner.nextLine();
        boolean compressing = scanner.nextLine().equals("compress");

        if (compressing) {
            int currentLetterCount = 1;

            for (int i = 0; i < text.length(); i++) {
                if (i < text.length() - 1 && text.charAt(i) == text.charAt(i + 1)) {
                    currentLetterCount++;
                } else {
                    System.out.print(text.charAt(i));
                    if (currentLetterCount > 1) {
                        System.out.print(currentLetterCount);
                    }

                    currentLetterCount = 1;
                }
            }
        } else {
            for (int i = 0; i < text.length(); i++) {
                System.out.print(text.charAt(i));

                String countBuffer = "";
                for (int j = i; j < text.length(); j++) {
                    if (j < text.length() - 1 && Character.isDigit(text.charAt(j + 1))) {
                        countBuffer += text.charAt(j + 1);
                    } else {
                        if (!countBuffer.isEmpty()) {
                            int count = Integer.parseInt(countBuffer);
                            for (int k = 0; k < count - 1; k++) {
                                System.out.print(text.charAt(i));
                            }
                        }

                        i = j;
                        break;
                    }
                }
            }
        }

        System.out.println();
    }
}

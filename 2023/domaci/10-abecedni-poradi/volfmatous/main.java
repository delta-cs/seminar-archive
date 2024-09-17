import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        boolean descending = false;
        boolean descendingDecided = false;
        String previousWord = "";
        for (int i = 0; i < n; i++) {
            String currentWord = scanner.next();

            boolean inOrderAscending = areWordsInOrder(previousWord, currentWord, false);
            boolean inOrderDescending = areWordsInOrder(previousWord, currentWord, true);

            previousWord = currentWord;

            if (descendingDecided) {
                if (descending ? !inOrderDescending : !inOrderAscending) {
                    System.out.println("unordered");
                    return;
                }
            } else {
                if (inOrderAscending && inOrderDescending) {
                    continue;
                }

                descendingDecided = true;

                if (inOrderAscending) {
                    descending = false;
                    continue;
                }

                if (inOrderDescending) {
                    descending = true;
                    continue;
                }

                System.out.println("unordered");
                return;
            }
        }

        System.out.println("ordered");
    }

    static boolean areWordsInOrder(String word1, String word2, boolean descending) {
        boolean letterCaseInOrder = true;
        boolean letterCaseInOrderDecided = false;

        int shorterLength = Math.min(word1.length(), word2.length());
        for (int i = 0; i < shorterLength; i++) {
            char char1 = word1.charAt(i);
            char char2 = word2.charAt(i);

            if (Character.toLowerCase(char1) != Character.toLowerCase(char2)) {
                boolean alphabetAscendingOrder = Character.toLowerCase(char1) < Character.toLowerCase(char2);
                return descending ? !alphabetAscendingOrder : alphabetAscendingOrder;
            }

            if (letterCaseInOrderDecided) {
                continue;
            }

            if (Character.isLowerCase(char1) && Character.isUpperCase(char2)) {
                letterCaseInOrder = true;
                letterCaseInOrderDecided = true;
                continue;
            }

            if (Character.isUpperCase(char1) && Character.isLowerCase(char2)) {
                letterCaseInOrder = false;
                letterCaseInOrderDecided = true;
                continue;
            }
        }

        if (word1.length() != word2.length()) {
            return word1.length() < word2.length();
        }

        return letterCaseInOrder;
    }
}

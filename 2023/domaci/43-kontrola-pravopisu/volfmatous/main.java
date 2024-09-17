import java.util.Scanner;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashSet<String> dictionaryWords = new HashSet<>();

        int d = scanner.nextInt();
        for (int i = 0; i < d; i++) {
            dictionaryWords.add(scanner.next());
        }

        boolean sentenceStarts = true;
        boolean previousWordWasNumber = false;

        int l = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < l; i++) {
            String line = scanner.nextLine();

            System.out.println(line);

            if (line.length() < 1) {
                continue;
            }

            List<Integer> errorIndexes = new ArrayList<>();
            List<Integer> errorLengths = new ArrayList<>();
            List<String> errorMessages = new ArrayList<>();

            int currentIndex = 0;
            boolean duplicateSpaceFlag = false;

            String[] words = line.split(" ");

            for (String w : words) {
                String word = w;

                if (word.length() < 1) {
                    if (duplicateSpaceFlag) {
                        errorLengths.set(errorLengths.size() - 1, errorLengths.get(errorLengths.size() - 1) + 1);
                    } else {
                        errorIndexes.add(Math.max(0, currentIndex - 1));
                        errorLengths.add(2);
                        errorMessages.add("duplicate space");
                        duplicateSpaceFlag = true;
                    }

                    currentIndex++;
                    continue;
                }

                duplicateSpaceFlag = false;

                boolean endsWithDot = false;
                if (word.endsWith(".")) {
                    word = word.substring(0, word.length() - 1);
                    endsWithDot = true;
                }

                boolean isNumber = true;
                for (char c : word.toCharArray()) {
                    if (!Character.isDigit(c)) {
                        isNumber = false;
                        break;
                    }
                }

                String wordCapitalized = Character.toUpperCase(word.charAt(0)) + word.substring(1);
                String wordLowercase = word.toLowerCase();

                if (isNumber) {
                    if (word.length() > 3) {
                        errorIndexes.add(currentIndex);
                        errorLengths.add(word.length());
                        errorMessages.add("incorrect number formatting");
                    }
                } else if (!dictionaryWords.contains(wordCapitalized) && !dictionaryWords.contains(wordLowercase)) {
                    errorIndexes.add(currentIndex);
                    errorLengths.add(word.length());
                    errorMessages.add("unknown word");
                } else if (Character.isUpperCase(word.charAt(0)) && !sentenceStarts && !previousWordWasNumber && !dictionaryWords.contains(word)) {
                    errorIndexes.add(currentIndex);
                    errorLengths.add(word.length());
                    errorMessages.add("incorrect leading uppercase");
                } else if (Character.isLowerCase(word.charAt(0)) && (sentenceStarts || !dictionaryWords.contains(wordLowercase))) {
                    errorIndexes.add(currentIndex);
                    errorLengths.add(word.length());
                    errorMessages.add("incorrect leading lowercase");
                }

                currentIndex += w.length() + 1;
                sentenceStarts = endsWithDot && !isNumber;
                previousWordWasNumber = isNumber;
            }

            if (errorIndexes.isEmpty()) {
                continue;
            }

            currentIndex = 0;
            for (int j = 0; j < errorIndexes.size(); j++) {
                for (int k = 0; k < errorIndexes.get(j) - currentIndex; k++) {
                    System.out.print(' ');
                }

                for (int k = 0; k < errorLengths.get(j); k++) {
                    System.out.print('~');
                }

                currentIndex = errorIndexes.get(j) + errorLengths.get(j);
            }

            System.out.println();

            currentIndex = 0;
            for (int j = 0; j < errorIndexes.size(); j++) {
                for (int k = 0; k < errorIndexes.get(j) - currentIndex; k++) {
                    System.out.print(' ');
                }

                System.out.print('^');

                currentIndex = errorIndexes.get(j) + 1;
            }

            System.out.println();

            for (int lineIndex = 0; lineIndex < errorIndexes.size() * 2; lineIndex++) {
                currentIndex = 0;

                for (int j = 0; j < errorIndexes.size() - lineIndex / 2; j++) {
                    for (int k = 0; k < errorIndexes.get(j) - currentIndex; k++) {
                        System.out.print(' ');
                    }

                    if (j == errorIndexes.size() - (lineIndex + 1) / 2) {
                        System.out.print("----- " + errorMessages.get(j));
                    } else {
                        System.out.print('|');
                    }

                    currentIndex = errorIndexes.get(j) + 1;
                }

                System.out.println();
            }

            System.out.println();
        }
    }
}

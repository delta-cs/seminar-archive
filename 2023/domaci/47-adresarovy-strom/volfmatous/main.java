import java.io.File;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String folderPath = scanner.nextLine();

        File directory = new File(folderPath);

        if (!directory.exists() || !directory.isDirectory()) {
            System.out.println("not found");
            return;
        }

        printDirectoryContents(directory, 0);
    }

    static void printDirectoryContents(File directory, int nestLevel) {
        File[] files = directory.listFiles();
        if (files == null) return;
        java.util.Arrays.sort(files);

        System.out.print(" ".repeat(Math.max(0, (nestLevel - 1) * 2)));
        if (nestLevel > 0) {
            System.out.print("- ");
        }
        System.out.println(directory.getName());

        for (File file : files) {
            if (file.isFile()) {
                System.out.print(" ".repeat(Math.max(0, nestLevel * 2)));
                System.out.println("- " + file.getName());
            }
        }

        for (File subDirectory : files) {
            if (subDirectory.isDirectory()) {
                printDirectoryContents(subDirectory, nestLevel + 1);
            }
        }
    }
}

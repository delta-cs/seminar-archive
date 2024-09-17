import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.zip.ZipFile;
import java.io.File;

class Main {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        String filePath = scanner.nextLine();

        if (!(new File(filePath)).exists()) {
            System.out.println("not found");
            return;
        }

        ZipFile zipFile = new ZipFile(filePath);
        zipFile.stream().filter(entry -> entry.getName().equals("input.txt")).findFirst().ifPresent(entry -> {
            try (BufferedReader zipReader = new BufferedReader(new InputStreamReader(zipFile.getInputStream(entry)))) {
                String line;
                while ((line = zipReader.readLine()) != null) {
                    System.out.println(line);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        });
    }
}

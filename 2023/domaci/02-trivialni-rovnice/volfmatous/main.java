import java.util.Scanner;
import java.text.DecimalFormat;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        double c = scanner.nextDouble();

        String output;
        if (b == 1) {
            output = "undefined";
        } else {
            double x = (c - a) / (b + 1);
            output = new DecimalFormat("#.################").format(x);
        }

        System.out.println(output);
    }
}

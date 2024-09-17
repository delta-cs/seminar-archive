import java.util.Scanner;
import java.text.DecimalFormat;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double n = scanner.nextDouble();

        double result = 0;

        char operation = '+';

        double temp1 = 0;
        char temp1Operation = '+';
        boolean temp1Used = false;

        double temp2 = 0;
        char temp2Operation = '+';
        boolean temp2Used = false;

        for (int i = 0; i < n; i++) {
            double operand = scanner.nextDouble();
            scanner.nextLine();

            char nextOperation = '+';
            if (i < n - 1) {
                nextOperation = scanner.nextLine().charAt(0);
            }

            if (temp2Used) {
                temp2 = applyOperation(temp2, temp2Operation, operand);
                temp2Operation = nextOperation;
            }

            if (nextOperation == '+' || nextOperation == '-' || i >= n - 1) {
                if (temp1Used) {
                    temp1 = applyOperation(temp1, temp1Operation, temp2Used ? temp2 : operand);
                    result = applyOperation(result, operation, temp1);

                    temp1Used = false;
                    temp2Used = false;
                } else {
                    result = applyOperation(result, operation, operand);
                }

                operation = nextOperation;
            } else if (nextOperation == '*' || nextOperation == '/') {
                if (temp1Used) {
                    temp1 = applyOperation(temp1, temp1Operation, temp2Used ? temp2 : operand);
                    temp2Used = false;
                } else {
                    temp1Used = true;
                    temp1 = operand;
                }

                temp1Operation = nextOperation;
            } else if (nextOperation == '^') {
                if (temp1Used) {
                    if (temp2Used) {
                        continue;
                    }

                    if (temp1Operation == '^') {
                        temp1 = applyOperation(temp1, temp1Operation, operand);
                        temp1Operation = nextOperation;
                    } else {
                        temp2Used = true;
                        temp2 = operand;
                        temp2Operation = nextOperation;
                    }
                } else {
                    temp1Used = true;
                    temp1 = operand;
                    temp1Operation = nextOperation;
                }
            }
        }

        System.out.println(new DecimalFormat("#.################").format(result));
    }

    static double applyOperation(double a, char operation, double b) {
        double result = 0;

        switch (operation) {
            case '+':
                result = a + b;
                break;

            case '-':
                result = a - b;
                break;

            case '*':
                result = a * b;
                break;

            case '/':
                result = a / b;
                break;

            case '^':
                result = Math.pow(a, b);
                break;
        }

        return result;
    }
}

#include <iostream>
#include <cmath>

double applyOperation(double a, char operation, double b) {
    double result = 0.0;

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
            result = pow(a, b);
            break;
    }

    return result;
}

int main() {
    double n;
    double result = 0.0;
    char operation = '+';
    double temp1 = 0.0;
    char temp1Operation = '+';
    bool temp1Used = false;
    double temp2 = 0.0;
    char temp2Operation = '+';
    bool temp2Used = false;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        double operand;
        std::cin >> operand;

        char nextOperation = '+';
        if (i < n - 1) {
            std::cin >> nextOperation;
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

    std::cout << result << std::endl;

    return 0;
}

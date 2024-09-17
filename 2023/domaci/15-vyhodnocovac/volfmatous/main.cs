using System;

internal class Program
{
    static void Main(string[] args)
    {
        double n = double.Parse(Console.ReadLine());

        double result = 0;

        char operation = '+';

        double temp1 = 0;
        char temp1Operation = '+';
        bool temp1Used = false;

        double temp2 = 0;
        char temp2Operation = '+';
        bool temp2Used = false;

        for (int i = 0; i < n; i++)
        {
            double operand = double.Parse(Console.ReadLine());

            char nextOperation = '+';
            if (i < n - 1)
            {
                nextOperation = char.Parse(Console.ReadLine());
            }

            if (temp2Used)
            {
                temp2 = ApplyOperation(temp2, temp2Operation, operand);
                temp2Operation = nextOperation;
            }

            if (nextOperation == '+' || nextOperation == '-' || i >= n - 1)
            {
                if (temp1Used)
                {
                    temp1 = ApplyOperation(temp1, temp1Operation, temp2Used ? temp2 : operand);
                    result = ApplyOperation(result, operation, temp1);

                    temp1Used = false;
                    temp2Used = false;
                }
                else
                {
                    result = ApplyOperation(result, operation, operand);
                }

                operation = nextOperation;
            }
            else if (nextOperation == '*' || nextOperation == '/')
            {
                if (temp1Used)
                {
                    temp1 = ApplyOperation(temp1, temp1Operation, temp2Used ? temp2 : operand);
                    temp2Used = false;
                }
                else
                {
                    temp1Used = true;
                    temp1 = operand;
                }

                temp1Operation = nextOperation;
            }
            else if (nextOperation == '^')
            {
                if (temp1Used)
                {
                    if (temp2Used)
                    {
                        continue;
                    }

                    if (temp1Operation == '^')
                    {
                        temp1 = ApplyOperation(temp1, temp1Operation, operand);
                        temp1Operation = nextOperation;
                    }
                    else
                    {
                        temp2Used = true;
                        temp2 = operand;
                        temp2Operation = nextOperation;
                    }
                }
                else
                {
                    temp1Used = true;
                    temp1 = operand;
                    temp1Operation = nextOperation;
                }
            }
        }

        Console.WriteLine(result);
    }

    static double ApplyOperation(double a, char operation, double b)
    {
        double result = 0;

        switch (operation)
        {
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
                result = Math.Pow(a, b);
                break;
        }

        return result;
    }
}
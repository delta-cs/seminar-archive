#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    int a0, b0, a1, b1;
    int n, na, nb;
    int q;

    while (scanf(" %d %d", &a, &b) == 2) {
        if (a < b) {
            a = b;
            b = a;
        }

        /*
         *     a  | b
         *   +---------+
         * a | 1  | 0  | "( a0, b0 )"
         * b | 0  | 1  | "( a1, b1 )"
         * n | na | nb | q
         *   |    |    |
         *
         */

        a0 = 1;
        b0 = 0;
        a1 = 0;
        b1 = 1;

        n = a % b;
        q = a / b;

        na = a0 - q * a1;
        nb = b0 - q * b1;

        a = b;
        a0 = a1;
        b0 = b1;

        b = n;
        a1 = na;
        b1 = nb;

        while (n != 0) {
            n = a % b;
            q = a / b;

            na = a0 - q * a1;
            nb = b0 - q * b1;

            a = b;
            a0 = a1;
            b0 = b1;

            b = n;
            a1 = na;
            b1 = nb;
        }

        printf("%d\n", a);
    }

    return 0;
}

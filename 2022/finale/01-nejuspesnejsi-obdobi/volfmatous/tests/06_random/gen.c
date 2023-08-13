#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int PROFIT_MIN = 0;
const int PROFIT_MAX = 10000;
const int COUNT = 1000000;

int main() {
    srand(time(NULL));

    printf("%d\n\n", COUNT);

    for (int i = 0; i < COUNT; ++i) {
        printf("%d\n", rand() % (PROFIT_MAX - PROFIT_MIN + 1) + PROFIT_MIN);
    }
}
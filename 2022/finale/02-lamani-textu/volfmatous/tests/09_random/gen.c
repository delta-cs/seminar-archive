#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

const int LENGTH = 1000000;
const int LINE_LENGTH_MIN = 2;
const int LINE_LENGTH_MAX = 60;

int rnd(int min, int max) {
    return rand() % (max - min) + min;
}

int isWordAllowedAtLineEnd(char word) {
    return word != 'k' &&
           word != 's' &&
           word != 'v' &&
           word != 'z' &&
           word != 'K' &&
           word != 'S' &&
           word != 'V' &&
           word != 'Z';
}

int main() {
    srand(time(NULL));

    char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.\0";
    int charsCount = (int) strlen(chars);

    int lineLength = rnd(LINE_LENGTH_MIN, LINE_LENGTH_MAX);
    int linesCount = 1;

    char output[LENGTH];

    char lastChar = ' ';

    for (int i = 0; i < LENGTH; ++i) {
        int random = rnd(0, 1000);

        if (random > 995 && i != LENGTH - 1 && lastChar != ' ' && lastChar != '\n' && isWordAllowedAtLineEnd(lastChar)) {
            output[i] = '\n';
            output[i + 1] = '\n';

            linesCount += 2;
            i++;
        } else if (random > 980 && i != LENGTH - 1 && lastChar != ' ' && lastChar != '\n') {
            output[i] = '\n';

            linesCount++;
        } else if (random > 900 && i != LENGTH - 1 && lastChar != ' ' && lastChar != '\n') {
            output[i] = ' ';
        } else {
            char c;
            do {
                c = chars[rnd(0, charsCount)];
            } while (i > 1 && output[i - 1] == ' ' &&
            !isWordAllowedAtLineEnd(output[i - 2]) && !isWordAllowedAtLineEnd(c));

            output[i] = c;
        }

        lastChar = output[i];
    }

    printf("%d\n%d\n\n", lineLength, linesCount);
    for (int i = 0; i < LENGTH; ++i) {
        printf("%c", output[i]);
    }
    printf("\n");
}

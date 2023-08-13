#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// returns: 0 = normal, -1 = EOF, -2 = newline
int scanWord(char **output, int *length) {
    int currentLength = 0;
    int capacity = 1;
    char *word = malloc((capacity + 1) * sizeof(char));

    int result;
    while (1) {
        char input;
        result = scanf("%c", &input);

        if (result == EOF) {
            result = -1;
            break;
        }

        if (input == ' ') {
            result = 0;
            break;
        }

        if (input == '\n') {
            result = -2;
            break;
        }

        currentLength++;
        if (currentLength > capacity) {
            capacity *= 2;
            word = realloc(word, (capacity + 1) * sizeof(char));
        }
        word[currentLength - 1] = input;
    }

    word[currentLength] = '\0';

    int wordLength = 0;

    int bytes = 0;
    while (bytes < currentLength)
    {
        bytes += mblen(&word[bytes], MB_CUR_MAX);
        wordLength++;
    }

    *output = word;
    *length = wordLength;
    return result;
}

int isWordAllowedAtLineEnd(char *word) {
    if (word == 0) {
        return 1;
    }

    return strcmp(word, "k") != 0
           && strcmp(word, "s") != 0
           && strcmp(word, "v") != 0
           && strcmp(word, "z") != 0
           && strcmp(word, "K") != 0
           && strcmp(word, "S") != 0
           && strcmp(word, "V") != 0
           && strcmp(word, "Z") != 0;
}

int main() {
    setlocale(LC_CTYPE, "cs_CZ.utf8");

    int maxLineLength;
    scanf(" %d", &maxLineLength);

    int lines;
    scanf(" %d", &lines);

    scanf("\n");

    int currentLineLength = 0;
    int isNewParagraph = 1;

    char *previousWord = 0;

    char *nextWord;
    int nextWordLength;
    int nextResult = scanWord(&nextWord, &nextWordLength);

    while (1) {
        char *word = nextWord;
        int wordLength = nextWordLength;
        int result = nextResult;

        if (result == -1) {
            printf("\n");
            break;
        }

        nextResult = scanWord(&nextWord, &nextWordLength);

        if (result == -2 && wordLength == 0) {
            printf("\n\n");
            isNewParagraph = 1;
            currentLineLength = 0;
            continue;
        }

        currentLineLength += wordLength;

        if (!isWordAllowedAtLineEnd(word) && currentLineLength + 1 + nextWordLength > maxLineLength &&
            !isNewParagraph) {
            printf("\n");

            isNewParagraph = 1;
            currentLineLength = wordLength;
        }

        if (currentLineLength > maxLineLength &&
            !(!isWordAllowedAtLineEnd(previousWord) && currentLineLength + 1 + wordLength > maxLineLength)) {
            if (!isNewParagraph) {
                printf("\n");
            }

            currentLineLength = wordLength;
        } else {
            if (!isNewParagraph) {
                printf(" ");
            }
        }

        currentLineLength++;

        printf("%s", word);

        free(previousWord);
        previousWord = word;

        isNewParagraph = 0;
    }

    free(nextWord);
}

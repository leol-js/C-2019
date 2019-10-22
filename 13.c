#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 1000

int checkWord(char word[], int size) {
    for (size_t i = 0; i < size / 2; i++) {
        if (word[i] != word[size - 1- i]) return 0;
    }
    return 1;
}

int main(int argc, char const *argv[]) {
    printf("Input lib of polindrom\n");
    char c;
    char* word = malloc(SIZE * sizeof(char));
    int realSize = 0;

    while ((c = getchar()) != ';') {
        if (isalpha(c)) {
            word[realSize] = c;
            realSize++;
        } else {
            if (realSize > 0 && checkWord(word, realSize)) {
                word[realSize] = '\0';
                printf("\nIt's POLINDROM - %s\n", word);
            }
            realSize = 0;
        }
    }
    return 0;
}

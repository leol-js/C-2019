#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char const *argv[]) {
    FILE *fin, *fout;

    if (!(fin = fopen("14/test.in", "r+"))) {
        printf("Can not open file! : test.in");
        return -1;
    }

    if (!(fout = fopen("14/test.out", "w+"))) {
        printf("Can not open file! : test.out");
        return -1;
    }

    int size = 0;
    int rsize = 10;

    char *type = malloc(rsize * sizeof(int));
    char *string = malloc(rsize * sizeof(int));
    char *position = malloc(rsize * sizeof(int));

    int curPosition = 0;
    int curString = 1;

    while (feof(fin) == 0) {
        char c = fgetc(fin);
        curPosition++;
        switch (c) {
            case '\n':
                curPosition = 0;
                curString++;
                break;
            case '{':
            case '[':
            case '(':
                type[size] = c;
                string[size] = curString;
                position[size] = curPosition;
                size++;
                break;

            case '}':
            case ']':
            case ')':
                if (size > 0) {
                    size--;
                    if (type[size] == (c - ((c == ')')? 1: 2))) {
                        fprintf(fout, "%c%c | open - %4i:%-4i | close - %4i:%-4i\n", type[size], c, string[size], position[size], curString, curPosition);
                    } else {
                        fprintf(fout, "%c  | open - %4i:%-4i | close - NAN\n", type[size], string[size], position[size]);
                        fprintf(fout, "%c  | open -     NAN | close - %4i:%-4i\n", c, curString, curPosition);
                    }
                } else {
                    fprintf(fout, "%c  | open - NAN | close - %4i:%-4i\n", c, curString, curPosition);
                }
        }
    }
    return 0;
}

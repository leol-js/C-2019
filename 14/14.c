#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int openFile(char name[], char mode[], FILE** file) {
    if (!(*file = fopen(name, mode))) {
        printf("Can not open file! : %s", name);
        return 1;
    }
    return 0;
}

int test() {
    FILE *fin, *fout;
    int i = openFile("14/test.in", "r+", &fin);
    i += openFile("14/test.out", "w+", &fout);
    if (i > 0) return -1;

    int size = 0;
    int rsize = 10;

    char *type = malloc(rsize * sizeof(char));
    int *string = malloc(rsize * sizeof(int));
    int *position = malloc(rsize * sizeof(int));

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
                if (size == rsize) {
                    rsize *= 2;
                    type = realloc(type, rsize * sizeof(char));
                    string = realloc(string, rsize * sizeof(int));
                    position = realloc(position, rsize * sizeof(int));
                }
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
                        fprintf(fout, "%c  | open - %4i:%-4i | close -     NAN  \n", type[size], string[size], position[size]);
                        fprintf(fout, "%c  | open -     NAN   | close - %4i:%-4i\n", c, curString, curPosition);
                    }
                } else {
                    fprintf(fout, "%c  | open -     NAN   | close - %4i:%-4i\n", c, curString, curPosition);
                }
        }
    }
    return 0;
}


int main(int argc, char const *argv[]) {
    return test();
}

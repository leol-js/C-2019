#include <stdio.h>
#include <stdlib.h>


void push(int *arr, int value, int *size, int *capacity) {
     if(*size > *capacity){
          realloc(arr, sizeof(arr) * 2);
          *capacity = sizeof(arr) * 2;
     }

     arr[*size] = value;
     *size = *size + 1;
}

void splitarray(int *array, int a, int b, int c) {
    int size = c - a;
    int tmp[size];
    int counta = a;
    int countb = b;

    for (int i = 0; i < c - a; i++) {
        if (counta < b && (array[counta] <= array[countb] || countb >= c)) {
            tmp[i] = array[counta];
            counta++;
        } else {
            if (countb < c && (array[countb] <= array[counta] || counta >= b)) {
                tmp[i] = array[countb];
                countb++;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        array[a + i] = tmp[i];
    }
}

void quicksort(int *array, int start, int end) {


    if (end - start <= 2) {
        splitarray(array, start, (end + start) / 2, end);
    } else {
        quicksort(array, start, (end + start) / 2);
        quicksort(array, (end + start) / 2, end);
        splitarray(array, start, (end + start) / 2, end);
    }
}

int main() {
    char c;
    int size = 0;
    int capacity = 10;
    int* array = (int*) malloc(capacity * sizeof(int));

    int num = 0;
    char n = 1;

    while ((c = getchar()) != '.') {
        switch (c) {
            case ' ':
            case 10 :
                if (n = 1) {
                    push(array, num, &size, &capacity);
                    num = 0;
                    n = 0;
                }
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
                num = num * 10 + c - '0';
                n = 1;
                break;
            default :
                printf("%s\n", "Stupid programm");
        }
    }
    if (n = 1) {
        push(array, num, &size, &capacity);
    }

    for (int i = 0; i < size; i += 1)
        printf("%d ", array[i]);
    printf("\n");

    quicksort(array, 0, size);

    for (int i = 0; i < size; i += 1)
        printf("%d ", array[i]) ;

    free(array);
    return 0;
}

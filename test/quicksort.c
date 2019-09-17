#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"


void push(int *arr, int value, int *size, int *capacity) {
    if(*size > *capacity){
        printf("More memory\n");
        realloc(arr, sizeof(arr) * 2);
        *capacity = sizeof(arr) * 2;

        if(arr == NULL) {          //reallocated pointer ptr1
            printf("\nExiting!!");
            free(arr);
            exit(0);
        }
    }

    arr[*size] = value;
    *size = *size + 1;
    printf("%d/%d\n", *size - 1, *capacity);
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
    int* array = malloc(capacity * sizeof(int));
    printf("%d\n", sizeof(array));

    int num = 0;
    int n = 0;

    while ((c = getchar()) != '.') {
        switch (c) {
            case ' ':
            case 10 :
                if (n) {
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
    if (n) {
        push(array, num, &size, &capacity);
    }
    printf("Your unsorted array: \n");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");

    printf("Start sorting...\n");
    quicksort(array, 0, size);
    printf("Sorting finishd, your array: \n");

    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");

    free(array);
    return 0;
}

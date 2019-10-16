#include "DoubleSortingFunctions.h"

typedef unsigned long size_t;

void sortInsertCount(double dArray[], int dArrSize, long *swap , long *ifs ) {
    double newElement;
    int location;

    for (int i = 1; i < dArrSize; i++) {
        newElement = dArray[i];
        location = i - 1;
        while (location >= 0 && dArray[location] > newElement) {
            dArray[location + 1] = dArray[location];
            location = location - 1;
            *swap  += 1;
            *ifs  += 1;
        }
        *ifs  += 1;

        dArray[location + 1] = newElement;
        *swap  += 1;
    }
}

void sortBubbleCount(double dArray[], int dArrSize, long *swap , long *ifs ) {
    for (size_t i = 0; i < dArrSize - 1; i++) {
        char flag = 0;
        for (size_t j = 0; j < dArrSize - i; j++) {
            if (dArray[j] > dArray[j + 1]) {
                double tmp = dArray[j + 1];
                dArray[j + 1] = dArray[i];
                dArray[i] = tmp;
                flag = 1;
                *swap  += 1;
            }
            *ifs  += 1;
        }

        if (flag == 0) break;
        *ifs  += 1;
    }
}

void sortSelectCount(double dArray[], int dArrSize, long *swap , long *ifs ) {
    for (size_t i = 0; i < dArrSize - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < dArrSize; j++) {
            if (dArray[j] < dArray[min]) min = j;
            *ifs  += 1;
        }

        if (min != i) {
            double tmp = dArray[min];
            dArray[min] = dArray[i];
            dArray[i] = tmp;
            *swap  += 1;
        }
        *ifs  += 1;
    }
}

void splitArraysToOneCount(double array[], int a, int b, int c, long *swap , long *ifs ) {
    int size = c - a;
    double tmp[size];
    int counta = a;
    int countb = b;

    for (size_t i = 0; i < c - a; i++) {
        if (counta < b && (array[counta] <= array[countb] || countb >= c)) {
            tmp[i] = array[counta];
            counta++;
            *swap  += 1;
        } else {
            if (countb < c && (array[countb] <= array[counta] || counta >= b)) {
                tmp[i] = array[countb];
                countb++;
                *swap  += 1;
            }
            *ifs  += 1;
        }
        *ifs  += 1;
    }

    for (size_t i = 0; i < size; i++) {
        array[a + i] = tmp[i];
    }
}
void sortQuickImCount(double dArray[], int start, int end, long *swap , long *ifs ) {
    if (end - start <= 2) {
        splitArraysToOneCount(dArray, start, (end + start) / 2, end, swap , ifs );
    } else {
        sortQuickImCount(dArray, start, (end + start) / 2, swap , ifs );
        sortQuickImCount(dArray, (end + start) / 2, end, swap , ifs );
        splitArraysToOneCount(dArray, start, (end + start) / 2, end, swap , ifs );
    }
    *ifs  += 1;
}
void sortQuickCount (double dArray[], int dArrSize, long *swap , long *ifs ) {
    sortQuickImCount(dArray, 0, dArrSize + 1, swap , ifs );
}




void sortInsert(double dArray[], int dArrSize) {
    double newElement;
    int location;

    for (size_t i = 1; i < dArrSize; i++) {
        newElement = dArray[i];
        location = i - 1;
        while (location >= 0 && dArray[location] > newElement) {
            dArray[location + 1] = dArray[location];
            location = location - 1;
        }
        dArray[location + 1] = newElement;
    }
}

void sortBubble(double dArray[], int dArrSize) {
    for (size_t i = 0; i < dArrSize - 1; i++) {
        char flag = 0;
        for (size_t j = 0; j < dArrSize - i; j++) {
            if (dArray[j] > dArray[j + 1]) {
                double tmp = dArray[j + 1];
                dArray[j + 1] = dArray[i];
                dArray[i] = tmp;
                flag = 1;
            }
        }

        if (flag == 0) break;
    }
}

void sortSelect(double dArray[], int dArrSize) {
    for (size_t i = 0; i < dArrSize - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < dArrSize; j++) {
            if (dArray[j] < dArray[min]) min = j;
        }

        if (min != i) {
            double tmp = dArray[min];
            dArray[min] = dArray[i];
            dArray[i] = tmp;
        }
    }
}

void splitArraysToOne(double array[], int a, int b, int c) {
    int size = c - a;
    double tmp[size];
    int counta = a;
    int countb = b;

    for (size_t i = 0; i < c - a; i++) {
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

    for (size_t i = 0; i < size; i++) {
        array[a + i] = tmp[i];
    }
}
void sortQuickIm(double dArray[], int start, int end) {
    if (end - start <= 2) {
        splitArraysToOne(dArray, start, (end + start) / 2, end);
    } else {
        sortQuickIm(dArray, start, (end + start) / 2);
        sortQuickIm(dArray, (end + start) / 2, end);
        splitArraysToOne(dArray, start, (end + start) / 2, end);
    }
}
void sortQuick (double dArray[], int dArrSize) {
    sortQuickIm(dArray, 0, dArrSize + 1);
}

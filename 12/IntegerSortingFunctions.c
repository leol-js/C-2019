#include "IntegerSortingFunctions.h"

void sortInsertCount(int iArray[], int iArrSize, long *swap , long *ifs ) {
    int newElement, location;

    for (int i = 1; i < iArrSize; i++) {
        newElement = iArray[i];
        location = i - 1;
        while (location >= 0 && iArray[location] > newElement) {
            iArray[location + 1] = iArray[location];
            location = location - 1;
            *swap  += 1;
            *ifs  += 1;
        }
        *ifs  += 1;

        iArray[location + 1] = newElement;
        *swap  += 1;
    }
}

void sortBubbleCount(int iArray[], int iArrSize, long *swap , long *ifs ) {
    for (size_t i = 0; i < iArrSize - 1; i++) {
        char flag = 0;
        for (size_t j = 0; j < iArrSize - i; j++) {
            if (iArray[j] > iArray[j + 1]) {
                int tmp = iArray[j + 1];
                iArray[j + 1] = iArray[i];
                iArray[i] = tmp;
                flag = 1;
                *swap  += 1;
            }
            *ifs  += 1;
        }

        if (flag == 0) break;
        *ifs  += 1;
    }
}

void sortSelectCount(int iArray[], int iArrSize, long *swap , long *ifs ) {
    for (size_t i = 0; i < iArrSize - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < iArrSize; j++) {
            if (iArray[j] < iArray[min]) min = j;
            *ifs  += 1;
        }

        if (min != i) {
            int tmp = iArray[min];
            iArray[min] = iArray[i];
            iArray[i] = tmp;
            *swap  += 1;
        }
        *ifs  += 1;
    }
}

void sortQuickCount (int iArray[], int iArrSize, long *swap , long *ifs ) {
    sortQuickIm(iArray, 0, iArrSize + 1, swap , ifs );
}
void sortQuickImCount(int iArray[], int start, int end, long *swap , long *ifs ) {
    if (end - start <= 2) {
        splitArraysToOne(iArray, start, (end + start) / 2, end, swap , ifs );
    } else {
        sortQuickIm(iArray, start, (end + start) / 2, swap , ifs );
        sortQuickIm(iArray, (end + start) / 2, end, swap , ifs );
        splitArraysToOne(iArray, start, (end + start) / 2, end, swap , ifs );
    }
    *ifs  += 1;
}
void splitArraysToOneCount(int array[], int a, int b, int c, long *swap , long *ifs ) {
    int size = c - a;
    int tmp[size];
    int counta = a;
    int countb = b;

    for (int i = 0; i < c - a; i++) {
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

    for (int i = 0; i < size; i++) {
        array[a + i] = tmp[i];
    }
}




void sortInsert(int iArray[], int iArrSize) {
    int newElement, location;

    for (int i = 1; i < iArrSize; i++) {
        newElement = iArray[i];
        location = i - 1;
        while (location >= 0 && iArray[location] > newElement) {
            iArray[location + 1] = iArray[location];
            location = location - 1;
        }
        iArray[location + 1] = newElement;
    }
}

void sortBubble(int iArray[], int iArrSize) {
    for (size_t i = 0; i < iArrSize - 1; i++) {
        char flag = 0;
        for (size_t j = 0; j < iArrSize - i; j++) {
            if (iArray[j] > iArray[j + 1]) {
                int tmp = iArray[j + 1];
                iArray[j + 1] = iArray[i];
                iArray[i] = tmp;
                flag = 1;
            }
        }

        if (flag == 0) break;
    }
}

void sortSelect(int iArray[], int iArrSize) {
    for (size_t i = 0; i < iArrSize - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < iArrSize; j++) {
            if (iArray[j] < iArray[min]) min = j;
        }

        if (min != i) {
            int tmp = iArray[min];
            iArray[min] = iArray[i];
            iArray[i] = tmp;
        }
    }
}

void sortQuick (int iArray[], int iArrSize) {
    sortQuickIm(iArray, 0, iArrSize + 1);
}
void sortQuickIm(int iArray[], int start, int end) {
    if (end - start <= 2) {
        splitArraysToOne(iArray, start, (end + start) / 2, end);
    } else {
        sortQuickIm(iArray, start, (end + start) / 2);
        sortQuickIm(iArray, (end + start) / 2, end);
        splitArraysToOne(iArray, start, (end + start) / 2, end);
    }
    *ifs  += 1;
}
void splitArraysToOne(int array[], int a, int b, int c) {
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

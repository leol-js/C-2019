//Дан целочисленный массив размера N. Определить количество участков, на которых его элементы монотонно возрастают.

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <omp.h>


#define TEST     100
#define ELEMENTS 10000
#define SIZE     10000


void sortInsert(int iArray[], int iArrSize, int *swap , int *ifs );
void sortBubble(int iArray[], int iArrSize, int *swap , int *ifs );
void sortSelect(int iArray[], int iArrSize, int *swap , int *ifs );
void sortQuick (int iArray[], int iArrSize, int *swap , int *ifs );

void splitArraysToOne(int array[], int a, int b, int c, int *swap , int *ifs );
void sortQuickIm(int array[], int start, int end, int *swap , int *ifs );

void generateArray(int iArray[], int iArrSize, int minValue, int maxValue);
void printArray(const char name[], int iArray[], int iArrSize);
void cloneArray(int array[], int newArray[], int iArrSize);
int checkArray(int iArray[], int iArrSize);

struct statistic{
    int swap;
    int ifs;

    double summaryTime;
    double worseTime;
    double bestTime;
};

void testSort(int array[], int arraySize, int *times, int *ifs, int *swap, void(*sorter)()) {
    int newArray[arraySize];
    cloneArray(array, newArray, arraySize);

    *times = omp_get_wtime();
    sorter(newArray, arraySize, swap, ifs);
    *times = omp_get_wtime() - *times;
}

int main() {
    printf("--------------------------------------------------------------\n");
    printf("%15s | %10s %10s %10s %10s\n", "Sort of:", "Insert", "Bubble", "Select", "Quick");
    printf("--------------------------------------------------------------\n");

    for (size_t elementsNumber = 10; elementsNumber < ELEMENTS; elementsNumber *= 10) {
        struct statistic insert = {0, 0, 0, 0, SIZE};
        struct statistic bubble = {0, 0, 0, 0, SIZE};
        struct statistic select = {0, 0, 0, 0, SIZE};
        struct statistic quick  = {0, 0, 0, 0, SIZE};
        int ops = 0;

        for (size_t elementsSize = 10; elementsSize < SIZE; elementsSize *= 10) {
            int array[elementsNumber];
            for (size_t i = 0; i < 100; i++) {
                int swap, ifs, time;
                generateArray(array, elementsNumber, 0, elementsSize);

                swap = 0, ifs = 0, time = 0;
                testSort(array, elementsNumber, &time, &ifs, &swap, sortInsert);
                insert.summaryTime += time;
                insert.swap += swap;
                insert.ifs += ifs;
                if (insert.worseTime < time) insert.worseTime = time;
                if (insert.bestTime > time) insert.bestTime = time;

                swap = 0, ifs = 0, time = 0;
                testSort(array, elementsNumber, &time, &ifs, &swap, sortBubble);
                bubble.summaryTime += time;
                bubble.swap += swap;
                bubble.ifs += ifs;
                if (bubble.worseTime < time) bubble.worseTime = time;
                if (bubble.bestTime > time) bubble.bestTime = time;


                swap = 0, ifs = 0, time = 0;
                testSort(array, elementsNumber, &time, &ifs, &swap, sortSelect);
                select.summaryTime += time;
                select.swap += swap;
                select.ifs += ifs;
                if (select.worseTime < time) select.worseTime = time;
                if (select.bestTime > time) select.bestTime = time;


                swap = 0, ifs = 0, time = 0;
                testSort(array, elementsNumber, &time, &ifs, &swap, sortQuick );
                quick.summaryTime += time;
                quick.swap += swap;
                quick.ifs += ifs;
                if (quick.worseTime < time) quick.worseTime = time;
                if (quick.bestTime > time) quick.bestTime = time;
                ops++;
            }

            printf("%15s | %10d %10d %10d %10d\n", "Number of ops",   ops, ops, ops, ops);
            printf("%15s | %10d %10d %10d %10d\n", "Number of elem",  elementsNumber, elementsNumber, elementsNumber, elementsNumber);
            printf("%15s | %10d %10d %10d %10d\n", "Size of elem",    elementsSize, elementsSize, elementsSize, elementsSize);
            printf("%15s | %10d %10d %10d %10d\n", "Number of ifs",   insert.ifs, bubble.ifs, select.ifs, quick.ifs);
            printf("%15s | %10d %10d %10d %10d\n", "Number of swaps", insert.swap, bubble.swap, select.swap, quick.swap);
            printf("%15s | %10lf %10lf %10lf %10lf\n", "Summary time",    insert.summaryTime, bubble.summaryTime, select.summaryTime, quick.summaryTime);
            printf("%15s | %10lf %10lf %10lf %10lf\n", "Best time",       insert.bestTime, bubble.bestTime, select.bestTime, quick.bestTime);
            printf("%15s | %10lf %10lf %10lf %10lf\n", "Worse time",      insert.worseTime, bubble.worseTime, select.worseTime, quick.worseTime);
            printf("%15s | %10lf %10lf %10lf %10lf\n", "Middle time",     insert.summaryTime / ops, bubble.summaryTime / ops, select.summaryTime / ops, quick.summaryTime / ops);
            printf("%15s | %10lf %10lf %10lf %10d\n", "Time / ElemNum",  insert.summaryTime / elementsNumber, bubble.summaryTime / elementsNumber, select.summaryTime / elementsNumber, quick.summaryTime / elementsNumber);
            printf("--------------------------------------------------------------\n");
        }
    }


}

void sortInsert(int iArray[], int iArrSize, int *swap , int *ifs ) {
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


void sortBubble(int iArray[], int iArrSize, int *swap , int *ifs ) {
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


void sortSelect(int iArray[], int iArrSize, int *swap , int *ifs ) {
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


void sortQuick (int iArray[], int iArrSize, int *swap , int *ifs ) {
    sortQuickIm(iArray, 0, iArrSize + 1, swap , ifs );
}
void sortQuickIm(int iArray[], int start, int end, int *swap , int *ifs ) {
    if (end - start <= 2) {
        splitArraysToOne(iArray, start, (end + start) / 2, end, swap , ifs );
    } else {
        sortQuickIm(iArray, start, (end + start) / 2, swap , ifs );
        sortQuickIm(iArray, (end + start) / 2, end, swap , ifs );
        splitArraysToOne(iArray, start, (end + start) / 2, end, swap , ifs );
    }
    *ifs  += 1;
}
void splitArraysToOne(int array[], int a, int b, int c, int *swap , int *ifs ) {
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

int checkArray(int iArray[], int iArrSize) {
    if (iArrSize < 2) return 0;
    for (size_t i = 0; i < iArrSize - 1; i++) {
        if (iArray[i] > iArray[i + 1]) return i;
    }
    return 0;
}


void generateArray(int iArray[], int iArrSize, int minValue, int maxValue) {
    if (minValue < maxValue) {
        minValue += 1; // include minValue in output
    } else {
        int tmp = minValue;
        minValue = maxValue + 1; // include minValue in output
        maxValue = tmp;
    }

    srand(time(NULL));
    for (int i = 0; i < iArrSize; i++) {
        iArray[i] = rand() % (maxValue - minValue) + minValue;
  	}
    return;
}

void cloneArray(int array[], int newArray[], int iArrSize) {
    for (size_t i = 0; i < iArrSize; i++) {
        newArray[i] = array[i];
    }
}

void printArray(const char name[], int iArray[], int iArrSize) {
    printf("Массив ");
  	printf(name);
  	printf(": ");
    for (int i = 0; i < iArrSize; i++) {
        printf("%d ", iArray[i]);
    }
    printf("\n");
    return;
}

//Дан целочисленный массив размера N. Определить количество участков, на которых его элементы монотонно возрастают.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "IntegerSortingFunctions.h"
#include "IntegerServiceFunctions.h"

#define TEST     100
#define ELEMENTS 10000
#define SIZE     10000

int checkArray(int iArray[], int iArrSize);

struct statistic{
    long swap;
    long ifs;

    double summaryTime;
    double worseTime;
    double bestTime;
};

double timesSec() {
    struct timespec tv;

    clock_gettime(CLOCK_MONOTONIC, &tv);
    return tv.tv_sec + ((double) tv.tv_nsec) / 1000000000;
}

double testSort(int array[], int arraySize, long *ifs, long *swap, void(*sorter)()) {
    int newArray[arraySize];
    cloneArray(array, newArray, arraySize);

    double a, b;
    a = timesSec();
    sorter(newArray, arraySize, swap, ifs);
    b = timesSec();
    return b - a;
}

int main() {
    printf("-----------------------------------------------------------------\n");
    printf("%15s | %10s %10s %10s %10s\n", "Sort of:", "Insert", "Bubble", "Select", "Quick");
    printf("-----------------------------------------------------------------\n");


    for (size_t elementsNumber = 10; elementsNumber < ELEMENTS; elementsNumber *= 10) {
        struct statistic insert = {0, 0, 0, 0, SIZE};
        struct statistic bubble = {0, 0, 0, 0, SIZE};
        struct statistic select = {0, 0, 0, 0, SIZE};
        struct statistic quick  = {0, 0, 0, 0, SIZE};
        int ops = 0;

        for (size_t elementsSize = 10; elementsSize < SIZE; elementsSize *= 10) {
            int array[elementsNumber];
            for (size_t i = 0; i < 100; i++) {
                long swap, ifs;
                double times;
                generateArray(array, elementsNumber, 0, elementsSize);

                swap = 0, ifs = 0, times = 0;
                times = testSort(array, elementsNumber, &ifs, &swap, sortInsert);
                insert.summaryTime += times;
                insert.swap += swap;
                insert.ifs += ifs;
                if (insert.worseTime < times) insert.worseTime = times;
                if (insert.bestTime > times) insert.bestTime = times;

                swap = 0, ifs = 0, times = 0;
                times = testSort(array, elementsNumber, &ifs, &swap, sortBubble);
                bubble.summaryTime += times;
                bubble.swap += swap;
                bubble.ifs += ifs;
                if (bubble.worseTime < times) bubble.worseTime = times;
                if (bubble.bestTime > times) bubble.bestTime = times;


                swap = 0, ifs = 0, times = 0;
                times = testSort(array, elementsNumber, &ifs, &swap, sortSelect);
                select.summaryTime += times;
                select.swap += swap;
                select.ifs += ifs;
                if (select.worseTime < times) select.worseTime = times;
                if (select.bestTime > times) select.bestTime = times;


                swap = 0, ifs = 0, times = 0;
                times = testSort(array, elementsNumber, &ifs, &swap, sortQuick );
                quick.summaryTime += times;
                quick.swap += swap;
                quick.ifs += ifs;
                if (quick.worseTime < times) quick.worseTime = times;
                if (quick.bestTime > times) quick.bestTime = times;
                ops++;
            }

            printf("%15s | %11d %11d %11d %11d\n", "Number of ops",   ops, ops, ops, ops);
            printf("%15s | %11d %11d %11d %11d\n", "Number of elem",  elementsNumber, elementsNumber, elementsNumber, elementsNumber);
            printf("%15s | %11d %11d %11d %11d\n", "Size of elem",    elementsSize, elementsSize, elementsSize, elementsSize);
            printf("%15s | %11ld %11ld %11ld %11ld\n", "Number of ifs",   insert.ifs, bubble.ifs, select.ifs, quick.ifs);
            printf("%15s | %11ld %11ld %11ld %11ld\n", "Number of swaps", insert.swap, bubble.swap, select.swap, quick.swap);
            printf("%15s | %3.9lf %3.9lf %3.9lf %3.9lf\n", "Summary times",    insert.summaryTime, bubble.summaryTime, select.summaryTime, quick.summaryTime);
            printf("%15s | %3.9lf %3.9lf %3.9lf %3.9lf\n", "Best times",       insert.bestTime, bubble.bestTime, select.bestTime, quick.bestTime);
            printf("%15s | %3.9lf %3.9lf %3.9lf %3.9lf\n", "Worse times",      insert.worseTime, bubble.worseTime, select.worseTime, quick.worseTime);
            printf("%15s | %3.9lf %3.9lf %3.9lf %3.9lf\n", "Middle times",     insert.summaryTime / ops, bubble.summaryTime / ops, select.summaryTime / ops, quick.summaryTime / ops);
            printf("%15s | %3.9lf %3.9lf %3.9lf %3.9lf\n", "Time / ElemNum",  insert.summaryTime / elementsNumber, bubble.summaryTime / elementsNumber, select.summaryTime / elementsNumber, quick.summaryTime / elementsNumber);
            printf("-----------------------------------------------------------------\n");
        }
    }


}

int checkArray(int iArray[], int iArrSize) {
    if (iArrSize < 2) return 0;
    for (size_t i = 0; i < iArrSize - 1; i++) {
        if (iArray[i] > iArray[i + 1]) return i;
    }
    return 0;
}

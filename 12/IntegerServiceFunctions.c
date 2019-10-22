#include "IntegerServiceFunctions.h"

#define RAND_MAX 32767

typedef long int __time_t;
typedef __time_t time_t;
typedef unsigned long size_t;

int printf(const char *format, ...);
int scanf(const char *format, ...);
void srand(unsigned seed);
time_t time(time_t *time);
int rand(void);

int inputINumber(const char name[], int left, int right) {
  	int rez;
  	do {
    	printf(name);
    	printf(" = (от %d до %d) = ", left, right);
    	scanf("%d", &rez);
  	} while (rez < left || rez > right);
    return rez;
}

void inputIArray(const char name[], int iArray[], int iArrSize) {
  	printf("Ввод массива ");
  	printf(name);
  	printf("\n");

    for (int i = 0; i < iArrSize; i++) {
    	printf("[%2d] = ", i);
    	scanf("%d", &iArray[i]);
  	}

    printf("\n");
    return;
}

void generateIArray(int iArray[], int iArrSize, int minValue, int maxValue) {
    if (minValue < maxValue) {
        minValue += 1; // include minValue in output
    } else {
        int tmp = minValue;
        minValue = maxValue + 1; // include minValue in output
        maxValue = tmp;
    }

    srand(time(0));
    for (int i = 0; i < iArrSize; i++) {
        iArray[i] = ((double)rand() / (double)RAND_MAX) * (maxValue - minValue) + minValue;
  	}
    return;
}

void outputIArray(const char name[], int iArray[], int iArrSize) {
    printf("Массив ");
  	printf(name);
  	printf(": ");
    for (int i = 0; i < iArrSize; i++) {
        printf("%d ", iArray[i]);
    }
    printf("\n");
    return;
}

int checkIArray(int iArray[], int iArrSize) {
    if (iArrSize < 2) return -1;
    for (size_t i = 0; i < iArrSize - 1; i++) {
        if (iArray[i] > iArray[i + 1]) return i;
    }
    return -1;
}

void cloneIArray(int iArray[], int newIArray[], int iArrSize) {
    for (size_t i = 0; i < iArrSize; i++) {
        newIArray[i] = iArray[i];
    }
}

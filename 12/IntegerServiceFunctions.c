#include "IntegerServiceFunctions.h"

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

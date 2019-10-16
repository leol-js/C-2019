#include "DoubleServiceFunctions.h"

double inputDNumber(const char name[], double left, double right) {
  	double rez;
  	do {
    	printf(name);
    	printf(" = (от %lf до %lf) = ", left, right);
    	scanf("%lf", &rez);
  	} while (rez < left || rez > right);
    return rez;
}

void inputDArray(const char name[], double dArray[], int dArrSize) {
  	printf("Ввод массива ");
  	printf(name);
  	printf("\n");

    for (int i = 0; i < dArrSize; i++) {
    	printf("[%2d] = ", i);
    	scanf("%lf", &dArray[i]);
  	}

    printf("\n");
    return;
}

void generateDArray(double dArray[], int dArrSize, double minValue, double maxValue) {
    if (minValue < maxValue) {
        minValue += 1; // include minValue in output
    } else {
        double tmp = minValue;
        minValue = maxValue + 1; // include minValue in output
        maxValue = tmp;
    }

    srand(time(0));
    for (int i = 0; i < dArrSize; i++) {
        dArray[i] = ((double)rand() / (double)(RAND_MAX)) * (maxValue - minValue) + minValue;
  	}

    printf("\n");
    return;
}

void outputDArray(const char name[], double dArray[], int dArrSize) {
    printf("Массив ");
  	printf(name);
  	printf(" : ");
    for (int i = 0; i < dArrSize; i++) {
        printf("%lf ", dArray[i]);
  	}
    printf("\n");
    return;
}

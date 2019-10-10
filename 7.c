
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INT_SIZE 1000

double inputDNumber(const char name[], double left, double right);
double inputINumber(const char name[], int left, int right);

void inputDArray(const char name[], double dArray[], int dArrSize);
void inputIArray(const char name[], int iArray[], int iArrSize);

void generateDArray(double dArray[], int dArrSize, double minValue, double maxValue);
void generateIArray(int iArray[], int iArrSize, int minValue, int maxValue);

void outputDArray(const char name[], double dArray[], int dArrSize);
void outputIArray(const char name[], int iArray[], int iArrSize);

void sortDArray(double dArray[], int dArrSize);
void sortIArray(int iArray[], int iArrSize);

void qSortDArray(double dArray[], int dArrSize);
void qSortIArray(int iArray[], int iArrSize);

int compareI(const int *a, const int *b);
int compareD(const double *a, const double *b);

int main(int type) {
    double a[30];
    // inputDNumber("a", 1, 4);

    generateDArray(a, 30, 10, 30);
    outputDArray("a", a, 30);

    // inputDArray("a", a, 5);
    // outputDArray("a", a, 30);

    qSortDArray(a, 30);
    outputDArray("a", a, 30);
    return 0;
}


double inputDNumber(const char name[], double left, double right) {
  	double rez;
  	do {
    	printf(name);
    	printf(" = (от %lf до %lf) = ", left, right);
    	scanf("%lf", &rez);
  	} while (rez < left || rez > right);
    return rez;
}

double inputINumber(const char name[], int left, int right) {
  	int rez;
  	do {
    	printf(name);
    	printf(" = (от %d до %d) = ", left, right);
    	scanf("%d", &rez);
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

void sortDArray(double dArray[], int dArrSize) {
    for (size_t i = 0; i < dArrSize - 1; i++) {
        int ptr = i;
        for (size_t j = i + 1; j < dArrSize; j++) {
            if (dArray[j] < dArray[ptr]) {
                ptr = j;
            }
        }

        double tmp = dArray[ptr];
        dArray[ptr] = dArray[i];
        dArray[i] = tmp;
    }
}

void sortIArray(int iArray[], int iArrSize) {
    for (size_t i = 0; i < iArrSize - 1; i++) {
        int ptr = i;
        for (size_t j = i + 1; j < iArrSize; j++) {
            if (iArray[j] < iArray[ptr]) {
                ptr = j;
            }
        }

        int tmp = iArray[ptr];
        iArray[ptr] = iArray[i];
        iArray[i] = tmp;
    }
}

void qSortDArray(double dArray[], int dArrSize) {
    qsort(dArray, dArrSize, sizeof(double), (int(*) (const void *, const void *)) compareD);
}

void qSortIArray(int iArray[], int iArrSize) {
    qsort(iArray, iArrSize, sizeof(int), (int(*) (const void *, const void *)) compareI);
}

int compareI(const int *a, const int *b) {
    return *a - *b;
}

int compareD(const double *a, const double *b) {
    return *a == *b? 0 : *a > *b? 1: -1;
}

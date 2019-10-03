//Дан целочисленный массив размера N. Определить количество участков, на которых его элементы монотонно возрастают.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateIArray(int iArray[], int iArrSize, int minValue, int maxValue);
void outputIArray(const char name[], int iArray[], int iArrSize);
int countMonoPart(int iArray[], int iArrSize);

int main() {
    int n;
    printf("Print array size:\n");
    scanf("%d", &n);
    int array[n];

    generateIArray(array, n, 0, 100);
    outputIArray("Array", array, n);
    printf("%d\n", countMonoPart(array, n));
}

int countMonoPart(int iArray[], int iArrSize) {
    int result = 0;
    char flag = 0;
    for (size_t i = 0; i < iArrSize - 1; i++) {
        if (!flag && iArray[i] < iArray[i + 1]) {
            flag = 1;
        }

        if (flag && iArray[i] >= iArray[i + 1]) {
            result++;
        }

        if (iArray[i] >= iArray[i + 1]) {
            flag = 0;
        }
    }

    if (flag) {
        result++;
    }
    return result;
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

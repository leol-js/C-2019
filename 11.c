#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(type, a, b) {type tmp = a; a = b; b = tmp;}

void generateIArray(int iArray[], int iArrSize, int minValue, int maxValue) {
    if (minValue < maxValue) {
        minValue += 1; // include minValue in output
    } else {
        int tmp = minValue;
        minValue = maxValue + 1; // include minValue in output
        maxValue = tmp;
    }

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
        printf("%4d ", iArray[i]);
    }
    printf("\n");
    return;
}


int _5(int array[], int arraySize) {
    int count = 0;
    for (size_t i = 0; i < arraySize; i++) {
        if (i > 0 && array[i - 1] < array[i]) {
            count++;
        }
    }
    return count;
}

int _6(int array[], int arraySize) {
    int count = 0;
    char flag = 0;
    for (size_t i = 0; i < arraySize - 1; i++) {
        if (!flag && array[i] < array[i + 1]) {
            flag = 1;
        }

        if (flag && array[i] >= array[i + 1]) {
            count++;
        }

        if (array[i] >= array[i + 1]) {
            flag = 0;
        }
    }

    if (flag) {
        count++;
    }

    return count;
}

void transS(int n, int array[n][n]) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i; j < n; j++) {
            SWAP(int, array[i][j], array[j][i]);
        }
    }
}

void transR(int n, int m, int array[n][m], int newArray[m][n]) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            newArray[j][i] = array[i][j];
        }
    }
}

void multiple(int n, int m, int a[n][m], int b[m][n], int res[m][n]) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            res[i][j] = 0;
            for (size_t k = 0; k < m; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}



int main(int argc, char const *argv[]) {
    printf("Print array size: ");
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n][m], b[m][n], res[n][n];
    srand(time(NULL));

    for (size_t i = 0; i < n; i++) {
        generateIArray(a[i], m, 0, 10);
        outputIArray("a", a[i], m);
    }

    for (size_t i = 0; i < m; i++) {
        generateIArray(b[i], n, 0, 10);
        outputIArray("b", b[i], n);
    }
    // printf("5 task: %d\n", _5(array[0], m));
    // printf("6 task: %d\n", _6(array[0], m));

    multiple(n, m, a, b, res);
    for (size_t i = 0; i < n; i++) {
        outputIArray("res", res[i], n);
    }
    return 0;
}

//Дан целочисленный массив размера N. Найти минимальный из его локальных максимумов.

#include <stdio.h>
#include <float.h>

int main() {
    int n;
    printf("Print array size:\n");
    scanf("%d", &n);

    printf("Print %d array elements\n", n);
    float arr[n];
    for (size_t i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    float min = FLT_MAX_EXP;
    for (size_t i = 1; i < n - 1; i++) {
        if (((i == 0 && arr[i] > arr[i + 1]) ||
            (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) ||
            (i == n - 1 && arr[i] < arr[i + 1])) && min > arr[i]) {
                min = arr[i];
        }
    }

    printf("The minimal of local max: %f", min);
    return 0;
}

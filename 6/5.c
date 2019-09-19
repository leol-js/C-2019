//Дан целочисленный массив размера N. Определить количество участков, на которых его элементы монотонно возрастают.

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

    int count = 0;
    char flag = 0;
    for (size_t i = 0; i < n - 1; i++) {
        if (!flag && arr[i] < arr[i + 1]) {
            flag = 1;
        }

        if (flag && arr[i] >= arr[i + 1]) {
            count++;
        }

        if (arr[i] >= arr[i + 1]) {
            flag = 0;
        }
    }

    if (flag) {
        count++;
    }

    printf("Number of this segments: %d", count);
    return 0;
}

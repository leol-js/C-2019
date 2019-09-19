//Дан массив целых чисел размера N. Найти количество его локальных минимумов, т.е. случаев, когда элемент массива меньше своих соседних.

#include <stdio.h>

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
    for (size_t i = 0; i < n; i++) {
        if ((i == 0 && arr[i] < arr[i + 1]) ||
            (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]) ||
            (i == n - 1 && arr[i] > arr[i + 1])) {
            count++;
        }
    }

    printf("Numer of local min: %d", count);
    return 0;
}

//Задан массив, состоящий из N целых чисел. Элементы массива, стоящие на четных номерах, отсортировать в порядке возрастания. Порядок и расположение остальных элементов не должен измениться.

#include <stdio.h>

int main() {
    int n;
    printf("Print array size:\n");
    scanf("%d", &n);

    printf("Print %d array elements\n", n);
    int arr[n];
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    for (size_t i = 0; i < n; i += 2) {
        int min = i;
        for (size_t j = i; j < n; j += 2) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }

    printf("Final array:\n");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

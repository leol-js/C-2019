//Задан массив из N вещественных элементов. Определить количество элементов массива, которые больше своего левого соседа.

#include <stdio.h>

int main() {
    int n;
    printf("Print array size\n");
    scanf("%d", &n);

    printf("Print %d array elements\n", n);
    float arr[n];
    int count = 0;
    for (size_t i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        if (i > 0 && arr[i - 1] < arr[i]) {
            count++;
        }
    }

    printf("Number of this number = %d", count);
    return 0;
}

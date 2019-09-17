//Задан массив из N вещественных элементов. Вычислить сумму элементов массива, имеющих четные индексы.

#include <stdio.h>

int main() {
    int n;
    printf("Print array size\n");
    scanf("%d", &n);

    printf("Print %d array elements\n", n);
    float arr[n];
    float sum = 0;
    for (size_t i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        if (i % 2 == 0) {
            sum += arr[i];
        }
    }

    printf("Sum = %f", sum);
    return 0;
}

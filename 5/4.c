//Задан массив из N вещественных элементов. Вычислить сумму элементов массива, индексы элементов которых образуют последовательность чисел Фибоначчи.

#include <stdio.h>

int main() {
    int n;
    printf("Print array size\n");
    scanf("%d", &n);

    printf("Print %d array elements\n", n);
    float arr[n];
    for (size_t i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    float sum = 0;
    int a = 1;
    int b = 2;
    if (n < 2) {
        sum = 0;
    } else {
        if (n == 2) {
            sum = arr[1];
        } else {
            while (b < n) {
                sum += arr[a];
                b = a + b;
                a = b - a;
            }
        }
    }


    printf("Sum of this number = %f", sum);
    return 0;
}

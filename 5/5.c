//Задан массив из N вещественных элементов. Удалить из массива элементы, величина которых находится в интервале (a, b) (числа a и b (0 < a < b) — даны), оставляя неизменным порядок следования остальных элементов.

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

    float a, b;
    printf("Print a and b:\n");
    scanf("%f%f", &a, &b);

    int count = 0; //number of deleted elements
    for (size_t i = 0; i < n - count; i++) {
        if (a < arr[i] && arr[i] < b) { //if number is correct for our expression
            count++;
            for (size_t j = i; j < n - count; j++) {
                arr[j] = arr[j + 1];
            }
            i--; //compens i++ in for
        }
    }
    n -= count; //new array length


    printf("The final array:\n");
    for (size_t i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
    return 0;
}

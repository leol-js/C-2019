//Задан массив из N целочисленных элементов. Определить число чередований знака, т.е. число переходов с «-» на «+» и с «+» на «-».

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
        if (i > 0 && arr[i - 1] * arr[i] < 0) {
            count++;
        }
    }

    printf("Number of this situation = %d", count);
    return 0;
}

/*Дано вещественное число A и целое N. Определить значение следующего выражения: 1-A+A2-A3+…+(-1)NAN. Замечание: условный оператор не использовать.*/

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    float a;
    printf("Print float a and decimal n\n");
    scanf("%f%d", &a, &n);

    long int sum = 1;
    for (int i = 0; i < n; i++) {
        sum += powf(-1, i) * powf(a, i);
    }

    printf("%li\n", sum);

    return 0;
}

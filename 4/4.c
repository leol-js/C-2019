/*Последовательность чисел Фибоначчи { fi } задается рекуррентным соотношением: f0 = 0; f1 = 1; fk = fk-2 + fk-1 , k=2,3,4, … ; Вычислить сумму всех чисел Фибоначчи, которые не превосходят заданное число m.*/

#include <stdio.h>

int main() {
    float m;
    printf("Print M number\n");
    scanf("%f", &m);

    int a1 = 0;
    int a2 = 1;
    int sum = 0;
    while (a2 <= m) {
        sum += a2;
        a2 = a2 + a1;
        a1 = a2 - a1;
    }

    printf("%d\n", sum);
    return 0;
}

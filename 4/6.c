//Написать программу, которая выводит на консоль таблицу умножения

#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            int mtpl = i * j;
            if (mtpl < 10) {
                printf("  %d ", mtpl);
            } else {
                if (mtpl > 99) {
                    printf("%d ", mtpl);
                } else {
                    printf(" %d ", mtpl);
                }
            }
        }
        printf("\n");
    }
}

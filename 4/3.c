#include <stdio.h>

int main() {
    int a;
    printf("Print number: \n");
    scanf("%d", &a);

    if (a == 0) {
        printf("%d", 0);
    } else {
        for (int i = 0; i < 999; i++) {
            if (i / 100 + (i / 10) % 10 + i % 10 == a) {
                printf("%d ", i);
            }
        }
    }


    return 0;
}

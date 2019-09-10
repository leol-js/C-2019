#include <stdio.h>

int main() {
    int a;
    printf("Print number: \n");
    scanf("%d", &a);

    while (a > 0) {
        printf("%d", a % 10);
        a /= 10;
    }
    return 0;
}

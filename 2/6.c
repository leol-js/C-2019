#include <stdio.h>

int main()
{
    float a, b, c, d;

    printf("Print four number: \n");
    scanf("%f%f%f%f", &a, &b, &c, &d);

    if (a == b && b == c) {
        printf("This is fourth\n");
    } else {
        if (a == b && b == d) {
            printf("This is third\n");
        } else {
            if (a == c && c == d) {
                printf("This is second\n");
            } else {
                printf("This is first\n");
            }
        }
    }

    return 0;
}

#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Print three mark\n");
    scanf("%d%d%d", &a, &b, &c);

    if (a == 5 && b == 5 && c == 5) {
        printf("Five only!\n");
    } else {
        if (a >=4 && b >= 4 && c >= 4) {
            printf("Four and more!\n");
        } else {
            if (a == 2 && b == 2 && c == 2) {
                printf("Two only!\n");
            } else {
                printf("You have random mark!\n");
            }
        }
    }

    return 0;
}

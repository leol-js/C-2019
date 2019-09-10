#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    float a;

    printf("Print number: \n");
    scanf("%f", &a);

    int a1 = (int) a;
    int a2 = (int) ((a - a1) * 100);

    printf("%d ", a1);
    switch (a1 % 10) {
        case 1:
            printf("рубль ");
            break;
        case 2:
        case 3:
        case 4:
            printf("рубля ");
            break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 0:
            printf("рублей ");
            break;
    }

    printf("%d ", a2);
    switch (a2 % 10) {
        case 1:
            printf("копейка");
            break;
        case 2:
        case 3:
        case 4:
            printf("копейки");
            break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 0:
            printf("копеек");
            break;
    }

    return 0;
}

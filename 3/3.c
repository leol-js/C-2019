#include <stdio.h>
#include <locale.h>

int main()
{
    int a;

    printf("Print year: \n");
    scanf("%d", &a);

    printf("Год ");
    switch ((a - 1984) / 12) {
        case 0:
            printf("зелен");
            break;
        case 1:
            printf("красн");
            break;
        case 2:
            printf("желт");
            break;
        case 3:
            printf("бел");
            break;
        case 4:
            printf("черн");
            break;
    }

    switch ((a - 1984) % 12) {
        case 0:
            printf("ой крысы");
            break;
        case 1:
            printf("ой коровы");
            break;
        case 2:
            printf("ого тигра");
            break;
        case 3:
            printf("ого зайца");
            break;
        case 4:
            printf("четыре года");
            break;
        case 5:
            printf("пять лет");
            break;
        case 6:
            printf("шесть лет");
            break;
        case 8:
            printf("восемь лет");
            break;
        case 9:
            printf("девять лет");
            break;
    }

    return 0;
}

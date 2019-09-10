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
            printf("ого дракона");
            break;
        case 5:
            printf("ой змеи");
            break;
        case 6:
            printf("ой лошади");
            break;
        case 7:
            printf("ой овцы");
            break;
        case 8:
            printf("ой обезьяны");
            break;
        case 9:
            printf("ой курицы");
            break;
        case 10:
            printf("ой собаки");
            break;
        case 11:
            printf("ой свиньи");
            break;
        case 7:
            printf("девять лет");
            break;    }

    return 0;
}

#include <stdio.h>
#include <locale.h>

int main()
{
    int a;

    printf("Print age: \n");
    scanf("%d", &a);

    switch (a / 10) {
        case 2:
            printf("Двадцать ");
            break;
        case 3:
            printf("Тридцать ");
            break;
        case 4:
            printf("Сорок ");
            break;
        case 5:
            printf("Пятьдесят ");
            break;
        case 6:
            printf("Шестьдесят ");
            break;
        case 8:
            printf("Восемьдесят ");
            break;
        case 9:
            printf("Девяносто ");
            break;
    }

    if (a % 10 != 0) {
        switch (a % 10) {
            case 1:
                printf("один год");
                break;
            case 2:
                printf("два года");
                break;
            case 3:
                printf("три года");
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
    } else {
        printf("лет");
    }


    return 0;
}

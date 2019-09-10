#include <stdio.h>
#include <locale.h>

int main()
{
    int a;

    printf("Print number: \n");
    scanf("%d", &a);

    switch (a / 100) {
        case 1:
            printf("Сто ");
            break;
        case 2:
            printf("Двести ");
            break;
        case 3:
            printf("Триста ");
            break;
        case 4:
            printf("Четыреста ");
            break;
        case 5:
            printf("Пятьсот ");
            break;
        case 6:
            printf("Шестьсот ");
            break;
        case 8:
            printf("Восемьсот ");
            break;
        case 9:
            printf("Девятьсот ");
            break;
    }

    if ((a / 10) % 10 != 1) {
        switch ((a / 10) % 10) {
            case 2:
                printf("двадцать ");
                break;
            case 3:
                printf("тридцать ");
                break;
            case 4:
                printf("сорок ");
                break;
            case 5:
                printf("пятьдесят ");
                break;
            case 6:
                printf("шестьдесят ");
                break;
            case 8:
                printf("восемьдесят ");
                break;
            case 9:
                printf("девяносто ");
                break;
        }

        switch (a % 10) {
            case 1:
                printf("один ");
                break;
            case 2:
                printf("два ");
                break;
            case 3:
                printf("три ");
                break;
            case 4:
                printf("четыре ");
                break;
            case 5:
                printf("пять ");
                break;
            case 6:
                printf("шесть ");
                break;
            case 8:
                printf("восемь ");
                break;
            case 9:
                printf("девять ");
                break;
        }
    } else {
        switch (a % 10) {
            case 0:
                printf("десять ");
                break;
            case 1:
                printf("одинадцать ");
                break;
            case 2:
                printf("двенадцать ");
                break;
            case 3:
                printf("тринадцать ");
                break;
            case 4:
                printf("четырнадцать ");
                break;
            case 5:
                printf("пятнадцать ");
                break;
            case 6:
                printf("шестнадцать ");
                break;
            case 8:
                printf("восемнадцать ");
                break;
            case 9:
                printf("девятнадцать ");
                break;
        }
    }

    return 0;
}

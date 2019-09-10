#include <stdio.h>
#include <math.h>

int main()
{
    float boatV, riverV, lakeT, riverT;

    printf("Print boat speed U: \n");
    scanf("%f", &boatV);

    printf("Print river speed V: \n");
    scanf("%f", &riverV);

    printf("Print lake time T1: \n");
    scanf("%f", &lakeT);

    printf("Print river time T2: \n");
    scanf("%f", &riverT);

    printf("S = %f\n", boatV * lakeT + (boatV - riverV) * riverT);
        return 0;
}

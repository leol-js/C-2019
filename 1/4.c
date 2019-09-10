#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, t;

    printf("Print first car speed: \n");
    scanf("%f", &a);

    printf("Print second car speed: \n");
    scanf("%f", &b);

    printf("Print time: \n");
    scanf("%f", &t);

    printf("S = %f\n", (a + b * t));
    return 0;
}

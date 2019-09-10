#include <stdio.h>
#include <math.h>

int main()
{
    float a, b;

    printf("Print two number: \n");
    scanf("%f%f", &a, &b);
    printf("(a^2 + b^2) / 2 = %f\n", (powf(a, 2) + powf(b, 2)) / 2);
    printf("(|a| + |b|) / 2 = %f\n", (fabs(a) + fabs(b) / 2));

    return 0;
}

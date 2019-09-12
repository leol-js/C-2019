#include <stdio.h>
#include <math.h>

int main()
{
    float length;
    float area;
    printf("Print circle length: ");
    scanf("%f", &length);
    area = powf(length / 6.28, 2) * 3.14;
    printf("\nArea of a circle is %f\n", area);
    return 0;
}

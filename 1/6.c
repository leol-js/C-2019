#include <stdio.h>
#include <math.h>

int main()
{
    float a0, a1, b0, b1, c0, c1;

    printf("Print first point coordinate: \n");
    scanf("%f%f", &a0, &a1);

    printf("Print second point coordinate: \n");
    scanf("%f%f", &b0, &b1);

    printf("Print third point coordinate: \n");
    scanf("%f%f", &c0, &c1);

    float ab, ac, bc;
    ab = sqrt(powf(a0 - b0, 2) + powf(a1 - b1, 2));
    ac = sqrt(powf(a0 - c0, 2) + powf(a1 - c1, 2));
    bc = sqrt(powf(c0 - b0, 2) + powf(c1 - b1, 2));
    if (ab + ac < bc || ac + bc < ab || bc + ab < ac) {
        printf("Incorrect triangle\n");
    } else {
        float p = ab + ac + bc;
        printf("L = %f\n", p);
        printf("S = %f\n", sqrt(p / 2 * (p / 2 - ab) * (p / 2 - ac)* (p / 2 - bc)));
    }
    return 0;
}

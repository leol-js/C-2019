#include <stdio.h>
#include <stdlib.h>
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
    ab = powf(a0 - b0, 2) + powf(a1 - b1, 2);
    ac = powf(a0 - c0, 2) + powf(a1 - c1, 2);
    bc = powf(c0 - b0, 2) + powf(c1 - b1, 2);

    if (ac > ab && ac > bc) {
        float tmp = ac;
        ac = ab;
        ab = tmp;
    } else {
        if (bc > ab && bc > ac) {
            float tmp = bc;
            bc = ab;
            ab = tmp;
        }
    }

    if (ab == bc + ac) {
        printf("Rectangular triangle\n");
    } else {
        if (ab > bc + ac) {
            printf("Obtuse triangle\n");
        } else {
            printf("Acute angel triangle\n");
        }
    }
    return 0;
}

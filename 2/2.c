#include <stdio.h>
#include <math.h>

int main()
{
    float x1, y1, r1, x2, y2, r2;
    printf("Print x,y and r for first circle\n");
    scanf("%f%f%f", &x1, &y1, &r1);

    printf("Print x,y and r for second circle\n");
    scanf("%f%f%f", &x2, &y2, &r2);

    float length = sqrt(powf(x1 - x2, 2) + powf(y1 - y2, 2));

    if (length > r1 + r2) {
        printf("Circles do not contact\n");
    } else {
        if (length == 0 && fabs(r1 - r2) < 0.00003) {
            printf("Circles are math up\n");
        } else {
            if (length == r1 + r2 || length == fabs(r1 - r2)) {
                printf("Circles are contact\n");
            } else {
                printf("Circles are intersect\n");
            }
        }
    }

    return 0;
}

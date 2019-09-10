#include <stdio.h>
#include <math.h>

#define GET_VARIABLE_NAME(Variable) (#Variable)



int main()
{
    float x, y;

    printf("Print x,y for dot\n");
    scanf("%f%f", &x, &y);

    if (x == 0 && y == 0) {
        printf("At the start of coordination system\n");
    } else {
        if (x == 0) {
            printf("At the X axis\n");
        } else {
            if (y == 0) {
                printf("At the Y axis\n");
            } else {
                if (x > 0) {
                    if (y > 0) {
                        printf("At the 1 forth\n");
                    } else {
                        printf("At the 4 forth\n");
                    }
                } else {
                    if (y > 0) {
                        printf("At the 2 forth\n");
                    } else {
                        printf("At the 3 forth\n");

                    }
                }
            }
        }
    }

    return 0;
}

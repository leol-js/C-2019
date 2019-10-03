#define _POSIX_X_SOURCE 200809L

#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>

int nodI(int a, int b) {
    int c = 1;
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int nodR(int a, int b) {
    if (b == 0) return a;
    nodR(a % b, a);
}

int main(int argc, char const *argv[]) {
    printf("Print two number:\n");
    int a, b;
    scanf("%d%d", &a, &b);
    double time1, time2;
    int nodr, nodi;

    struct timespec spec;


    clock_gettime(CLOCK_MONOTONIC, &spec);
    time1 = spec.tv_nsec;
    nodi = nodR(a, b);
    clock_gettime(CLOCK_MONOTONIC, &spec);
    time1 = spec.tv_nsec - time1;


    clock_gettime(CLOCK_MONOTONIC, &spec);
    time2 = spec.tv_nsec;
    nodi = nodI(a, b);
    clock_gettime(CLOCK_MONOTONIC, &spec);
    time2 = spec.tv_nsec - time2;

    printf("--------------------------------------------------------------\n");
    printf("%s : %lf\n%s : %lf\n", "Recursive", time1, "Normal", time2);

    return 0;
}

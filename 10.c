#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TRY 100000

double timeSec() {
    struct timespec tv;

    clock_gettime(CLOCK_MONOTONIC, &tv);
    return tv.tv_sec + ((double) tv.tv_nsec) / 1000000000;
}

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
    nodR(b, a % b);
}

int main(int argc, char const *argv[]) {
    printf("Print two number:\n");
    int a, b;
    scanf("%d%d", &a, &b);
    double timeRS, timeRF, timeIS, timeIF;
    int nodr, nodi;

    timeRS = timeSec();
    for (size_t i = 0; i < TRY; i++) {
        nodr = nodR(a, b);
    }
    timeRF = timeSec();

    timeIS = timeSec();
    for (size_t i = 0; i < TRY; i++) {
        nodi = nodI(a, b);
    }
    timeIF = timeSec();

    if (nodi != nodr) {
        printf("--------------------------------------------------------------\n");
        printf("%14s | %6d %6d | \nIteractive : %6d\nRecursive : %6d\n", "ERROR NOD", a, b, nodi, nodr);
        return 1;
    }

    printf("--------------------------------------------------------------\n");
    printf("%14s | %6.15lf sec\n%14s | %6.15lf sec\n",
        "Recursive", (timeRF - timeRS) / TRY,
        "Normal",    (timeIF - timeIS) / TRY);

    return 0;
}

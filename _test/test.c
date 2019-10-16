#include <stdio.h>
#include <sys/time.h>

double timeSec() {
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return tv.tv_sec + ((double) tv.tv_usec) / 1000000;
}

int main(int argc, char const *argv[]) {

    return 0;
}

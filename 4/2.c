#include <stdio.h>

int main() {
    int n, k;
    printf("Print n, k: \n");
    scanf("%d%d", &n, &k);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * k;
    }
    printf("%d", sum);
    return 0;
}

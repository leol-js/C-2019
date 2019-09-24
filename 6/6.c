//Заданы два целочисленных массива длины N и M соответственно. Каждый массив не содержит повторений. Построить массив, являющийся объединением заданных наборов.

#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main() {
    int n1;
    printf("Print first array size:\n");
    scanf("%d", &n1);

    printf("Print %d first array elements\n", n1);
    int arr1[n1];
    for (size_t i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    int n2;
    printf("Print second array size:\n");
    scanf("%d", &n2);

    printf("Print %d first array elements\n", n2);
    int arr2[n2];
    for (size_t i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    qsort(arr1, n1, sizeof(int), compare);
    qsort(arr2, n2, sizeof(int), compare);

    int arr[n1 + n2];
    int a = 0;
    int b = 0;
    while (a + b < n1 + n2) {
        if (a < n1) {
            if (b < n2) {
                if (arr1[a] <= arr2[b]) {
                    arr[a + b] = arr1[a];
                    a++;
                } else {
                    arr[a + b] = arr2[b];
                    b++;
                }
            } else {
                arr[a + b] = arr1[a];
                a++;
            }
        } else {
            arr[a + b] = arr2[b];
            b++;
        }
    }


    printf("Final array:\n");
    for (size_t i = 0; i < n1 + n2; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

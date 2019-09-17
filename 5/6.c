//Задан массив Y[n], элементами которого являются целые числа. Преобразовать массив так, чтобы все его нечетные элементы оказались в конце.
//Лишнее--Порядок элементов в четной и нечетной частях может измениться.

#include <stdio.h>

int main() {
    int n;
    printf("Print array size:\n");
    scanf("%d", &n);

    printf("Print %d array elements\n", n);
    int arr[n];
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0; //number of swapped elements
    for (size_t i = 0; i < n - count; i++) {
        if (arr[i] % 2 == 0) { //if number is correct for our expression
            count++;
            float tmp = arr[i];
            for (size_t j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[n - 1] = tmp;
            i--; //compens i++ in for
        }
    }


    printf("The final array:\n");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

//Дан целочисленный массив размера N. Определить количество участков, на которых его элементы монотонно возрастают.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ARRAY_MAX 100000
#define ARRAY_MIN 10

#define ELEMS_MAX 100000
#define ELEMS_MIN 10


void sortInsert(int iArray[], int iArrSize, long *swap , long *ifs );
void sortBubble(int iArray[], int iArrSize, long *swap , long *ifs );
void sortSelect(int iArray[], int iArrSize, long *swap , long *ifs );
void sortQuick (int iArray[], int iArrSize, long *swap , long *ifs );

void generateArray(int iArray[], int iArrSize, int minValue, int maxValue);
void printArray(const char name[], int iArray[], int iArrSize);
void cloneArray(const int array[], int newArray[], int iArrSize);
int  checkArray(const int iArray[], int iArrSize);

struct reply{
    unsigned long long  swaps;
    unsigned long long  ifs;
    double              time;  //time in nanosecs
    int                 error; //-1 - no errors, -2 - invalid size, 0-n - error at this plase by sorting.
};

struct multipleReply {
    struct reply insert;
    struct reply bubble;
    struct reply select;
    struct reply quick ;
};

double times() {
    struct timespec tv;

    clock_gettime(CLOCK_MONOTONIC, &tv);
    return tv.tv_sec + ((double) tv.tv_nsec) / 1000000000;
}

struct reply test(int array[], int arraySize, void(*sorter)()) {
    struct reply ret = {0, 0, 0, -2};
    if (arraySize == 0) return ret;
    double a, b;
    int *testingArray = malloc(arraySize * sizeof(array[0]));

    cloneArray(array, testingArray, arraySize);

    a = times();
    sorter(testingArray, arraySize, &ret.swaps, &ret.ifs);
    b = times();

    ret.time = b - a;
    ret.error = checkArray(testingArray, arraySize);
    if (ret.error != -1) printArray("Errored array", testingArray, arraySize);
    return ret;
}

struct multipleReply testArray(int array[], int arraySize) {
    struct multipleReply ret = {
            test(array, arraySize, sortInsert),
            test(array, arraySize, sortBubble),
            test(array, arraySize, sortSelect),
            test(array, arraySize, sortQuick)
    };
    return ret;
}

//struct multipleReply testRandArray(int arraySize, int elementsSize) {
//    int *array = malloc(arraySize * sizeof(int));
//    generateArray(array, arraySize, 0, elementsSize);
//    struct multipleReply ret = {
//            test(array, arraySize, sortInsert),
//            test(array, arraySize, sortBubble),
//            test(array, arraySize, sortSelect),
//            test(array, arraySize, sortQuick)
//    };
//    return ret;
//}

int printOneSortingStat(struct reply reply, char* name) {
    if (reply.error == -1) {
        printf("%6s|%14lld|%14lld|% 15.9lf\n",
               name, reply.swaps, reply.ifs, reply.time);
    } else {
        printf("We have a ERROR at %d position by %s sorter\n", reply.error, name);
    }
}

int printOneSortingStatWithGUI(struct reply reply, char* name) {
    printf("----------------------------------------------------\n%6s|%14s|%14s|%15s\n----------------------------------------------------\n",
           "Sorter", "Swaps num", "Ifs num", "Time to sort");
    printOneSortingStat(reply, name);
    printf("----------------------------------------------------\n");
}

int printSortingStat(struct multipleReply reply) {
    printf("----------------------------------------------------\n%6s|%14s|%14s|%15s\n----------------------------------------------------\n",
           "Sorter", "Swaps num", "Ifs num", "Time to sort");
    printOneSortingStat(reply.insert, "Insert");
    printOneSortingStat(reply.bubble, "Bubble");
    printOneSortingStat(reply.select, "Select");
    printOneSortingStat(reply.quick , "Quick");
    printf("----------------------------------------------------\n");
}

int printMenu() {
    printf("Press number key to start/continue:\n");
    printf("1: Start insert sort and show result\n");
    printf("2: Start bubble sort and show result\n");
    printf("3: Start select sort and show result\n");
    printf("4: Start quick  sort and show result\n");
    printf("5: Start all sorts and show results\n");
    printf("6: Generate new array\n");
    printf("7: Get new array by input\n");
    printf("8: Change array size\n");
    printf("9: Change elements size\n");
    printf("0: Exit\n");
}

int main() {
    char bool = 1;

    int ARRAY_SIZE = 10;
    int ELEMS_SIZE = 10;

    int *array = malloc(ARRAY_SIZE * sizeof(int));
    char isInit = 0;

    char ref = 1;
    char c;

    do {
        if (ref) printMenu();
        ref = 1;

        scanf("%c", &c);

        switch (c) {
            case '1':
                printf("\n");
                if (!isInit) {
                    printf("Your array have not beed initialized...\nDo it for you\n");
                    generateArray(array, ARRAY_SIZE, 0, ELEMS_SIZE);
                    printf("Done!\n");
                    isInit = 1;
                }
                printf("Start sorting test!\n");
                printOneSortingStatWithGUI(test(array, ARRAY_SIZE, sortInsert), "Insert");
                printf("Sorting test finished!\n\n");
                break;
            case '2':
                printf("\n");
                if (!isInit) {
                    printf("Your array have not beed initialized...\nDo it for you\n");
                    generateArray(array, ARRAY_SIZE, 0, ELEMS_SIZE);
                    printf("Done!\n");
                    isInit = 1;
                }
                printf("Start sorting test!\n");
                printOneSortingStatWithGUI(test(array, ARRAY_SIZE, sortBubble), "Bubble");
                printf("Sorting test finished!\n\n");
                break;
            case '3':
                printf("\n");
                if (!isInit) {
                    printf("Your array have not beed initialized...\nDo it for you\n");
                    generateArray(array, ARRAY_SIZE, 0, ELEMS_SIZE);
                    isInit = 1;
                    printf("Done!\n");
                }
                printf("Start sorting test!\n");
                printOneSortingStatWithGUI(test(array, ARRAY_SIZE, sortSelect), "Select");
                printf("Sorting test finished!\n\n");
                break;
            case '4':
                printf("\n");
                if (!isInit) {
                    printf("Your array have not beed initialized...\nDo it for you\n");
                    generateArray(array, ARRAY_SIZE, 0, ELEMS_SIZE);
                    isInit = 1;
                    printf("Done!\n");
                }
                printf("Start sorting test!\n");
                printOneSortingStatWithGUI(test(array, ARRAY_SIZE, sortQuick), "Quick");
                printf("Sorting test finished!\n\n");
                break;
            case '5':
                if (!isInit) {
                    printf("Your array have not beed initialized...\nDo it for you\n");
                    generateArray(array, ARRAY_SIZE, 0, ELEMS_SIZE);
                    isInit = 1;
                    printf("Done!\n");
                }
                printf("Start multiple sorting test!\n");
                printSortingStat(testArray(array, ARRAY_SIZE));
                printf("Multiple sorting test finished!\n\n");
                break;
            case '6':
                printf("Start array initialization...\n");
                generateArray(array, ARRAY_SIZE, 0, ELEMS_SIZE);
                isInit = 1;
                printf("Done!\n");
                printArray("Your array", array, ARRAY_SIZE);
                break;
            case '7':
                if (ARRAY_SIZE > 20) {
                    printf("Your array size more than 20 (%d)\n", ARRAY_SIZE);
                    char stat;
                    scanf("%c", &stat);
                    while (stat != 'y' && stat != 'n') {
                        printf("Are you sure you want to continue? (y/n)\n");
                        scanf("%c", &stat);
                    }
                    if (stat == 'n') break;
                }
                printf("Your array size %d\nPlease, enter %d elements of array: (Only decimal number available)\n", ARRAY_SIZE, ARRAY_SIZE);
                for (int i = 0; i < ARRAY_SIZE; ++i) {
                    printf("Enter [%d] element:", i);
                    scanf("%d", &array[i]);
                }
                break;
            case '8':
                printf("You want to change array size!");
                int asize;
                do {
                    printf("\nPlease, enter new size (%d < size < %d) of array :", ARRAY_MIN, ARRAY_MAX);
                    scanf("%d", &asize);
                } while(asize < ARRAY_MIN || asize > ARRAY_MAX);
                printf("Size of array success changed to %d!\n", asize);
                isInit = 0;
                ARRAY_SIZE = asize;
                array = realloc(array, ARRAY_SIZE * sizeof(int));
                break;
            case '9':
                printf("You want to change elements size!");
                int esize;
                do {
                    printf("\nPlease, enter new size (%d < size < %d) of elements : ", ELEMS_MIN, ELEMS_MAX);
                    scanf("%d", &esize);
                } while(esize < ELEMS_MIN || esize > ELEMS_MAX);
                isInit = 0;
                printf("Size of elements success changed to %d!\n", esize);
                ELEMS_SIZE = esize;
                break;
            case '0':
                printf("Thank you for using!\nShut down...\n\nGood Bye!\n\n\n\n\n\n");
                bool = 0;
                break;
            case '\n':
            case '\r':
            case ' ':
                ref = 0;
                break;
            default:
                ref = 0;
                printf("Incorrect input - '%c'! Please, enter number 0..9\n", c);
        }
    } while(bool);
}

void sortInsert(int iArray[], int iArrSize, long *swap , long *ifs ) {
    int newElement, location;

    for (int i = 1; i < iArrSize; i++) {
        newElement = iArray[i];
        location = i - 1;
        while (location >= 0 && iArray[location] > newElement) {
            iArray[location + 1] = iArray[location];
            location = location - 1;
            *swap  += 1;
            *ifs  += 1;
        }
        *ifs  += 1;

        iArray[location + 1] = newElement;
        *swap  += 1;
    }
}


void sortBubble(int iArray[], int iArrSize, long *swap , long *ifs ) {
    for (size_t i = 0; i < iArrSize; i++) {
        char flag = 0;
        for (size_t j = 0; j < iArrSize - i; j++) {
            if (iArray[j] > iArray[j + 1]) {
                int tmp = iArray[j + 1];
                iArray[j + 1] = iArray[j];
                iArray[j] = tmp;
                flag = 1;

                *swap  += 1;
            }
            *ifs  += 1;
        }

        *ifs  += 1;
        if (flag == 0) break;
    }
}


void sortSelect(int iArray[], int iArrSize, long *swap , long *ifs ) {
    for (size_t i = 0; i < iArrSize - 1; i++) {
        size_t min = i;
        for (size_t j = i; j < iArrSize; j++) {
            if (iArray[j] < iArray[min]) min = j;

            *ifs  += 1;
        }

        int tmp = iArray[min];
        iArray[min] = iArray[i];
        iArray[i] = tmp;

        *swap  += 1;
        *ifs += 1;
    }
}


void splitArraysToOne(int array[], int a, int b, int c, long *swap , long *ifs ) {
    int size = c - a;
    int tmp[size];
    int counta = a;
    int countb = b;

    for (int i = 0; i < c - a; i++) {
        if (counta < b && (array[counta] <= array[countb] || countb >= c)) {
            tmp[i] = array[counta];
            counta++;
            *swap  += 1;
        } else {
            if (countb < c && (array[countb] <= array[counta] || counta >= b)) {
                tmp[i] = array[countb];
                countb++;
                *swap  += 1;
            }
            *ifs  += 1;
        }
        *ifs  += 1;
    }

    for (int i = 0; i < size; i++) {
        array[a + i] = tmp[i];
    }
}
void sortQuickIm(int iArray[], int start, int end, long *swap , long *ifs ) {
    if (end - start <= 2) {
        splitArraysToOne(iArray, start, (end + start) / 2, end, swap , ifs );
    } else {
        sortQuickIm(iArray, start, (end + start) / 2, swap , ifs );
        sortQuickIm(iArray, (end + start) / 2, end, swap , ifs );
        splitArraysToOne(iArray, start, (end + start) / 2, end, swap , ifs );
    }
    *ifs  += 1;
}
void sortQuick (int iArray[], int iArrSize, long *swap , long *ifs ) {
    sortQuickIm(iArray, 0, iArrSize + 1, swap , ifs );
}


int checkArray(const int iArray[], int iArrSize) {
    if (iArrSize < 2) return -1;
    for (int i = 0; i < iArrSize - 1; i++) {
        if (iArray[i] > iArray[i + 1]) {
            return i;
        }
    }
    return -1;
}

void generateArray(int iArray[], int iArrSize, int minValue, int maxValue) {
    if (minValue < maxValue) {
        minValue += 1; // include minValue in output
    } else {
        int tmp = minValue;
        minValue = maxValue + 1; // include minValue in output
        maxValue = tmp;
    }

    srand(time(NULL));
    for (int i = 0; i < iArrSize; i++) {
        iArray[i] = rand() % (maxValue - minValue) + minValue;
    }
}

void cloneArray(const int array[], int newArray[], int iArrSize) {
    for (size_t i = 0; i < iArrSize; i++) {
        newArray[i] = array[i];
    }
}

void printArray(const char name[], int iArray[], int iArrSize) {
    printf("%s: ", name);
    for (int i = 0; i < iArrSize; i++) {
        printf("%d ", iArray[i]);
    }
    printf("\n");
}

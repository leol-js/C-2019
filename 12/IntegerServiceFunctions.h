#ifndef INTEGER_SERVICE_FUNCTIONS
#define INTEGER_SERVICE_FUNCTIONS

int inputINumber(const char name[], int left, int right);
void inputIArray(const char name[], int iArray[], int iArrSize);
void generateIArray(int iArray[], int iArrSize, int minValue, int maxValue);
void outputIArray(const char name[], int iArray[], int iArrSize);
int checkIArray(int iArray[], int iArrSize);
void cloneIArray(int iArray[], int newIArray[], int iArrSize);

#endif

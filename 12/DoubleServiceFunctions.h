#ifndef DOUBLE_SERVICE_FUNCTIONS
#define DOUBLE_SERVICE_FUNCTIONS

double inputDNumber(const char name[], double left, double right);
void inputDArray(const char name[], double dArray[], int dArrSize);
void generateDArray(double dArray[], int dArrSize, double minValue, double maxValue);
void outputDArray(const char name[], double dArray[], int dArrSize);
int checkDArray(double dArray[], int dArrSize);
void cloneDArray(int dArray[], int newDArray[], int dArrSize);

#endif

#ifndef DOUBLE_SORTING_FUNCTIONS
#define DOUBLE_SORTING_FUNCTIONS

void sortInsertCount(double iArray[], double iArrSize, long *swap , long *ifs );
void sortBubbleCount(double iArray[], double iArrSize, long *swap , long *ifs );
void sortSelectCount(double iArray[], double iArrSize, long *swap , long *ifs );
void sortQuickCount (double iArray[], double iArrSize, long *swap , long *ifs );

void splitArraysToOne(double array[], double a, double b, double c, long *swap , long *ifs );
void sortQuickIm(double array[], double start, double end, long *swap , long *ifs );



void sortInsert(double iArray[], double iArrSize);
void sortBubble(double iArray[], double iArrSize);
void sortSelect(double iArray[], double iArrSize);
void sortQuick (double iArray[], double iArrSize);

void splitArraysToOne(double array[], double a, double b, double c);
void sortQuickIm(double array[], double start, double end);

#endif

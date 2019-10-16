#ifndef INTEGER_SORTING_FUNCTIONS
#define INTEGER_SORTING_FUNCTIONS

void sortInsertCount(int iArray[], int iArrSize, long *swap , long *ifs );
void sortBubbleCount(int iArray[], int iArrSize, long *swap , long *ifs );
void sortSelectCount(int iArray[], int iArrSize, long *swap , long *ifs );
void sortQuickCount (int iArray[], int iArrSize, long *swap , long *ifs );

void sortInsert(int iArray[], int iArrSize);
void sortBubble(int iArray[], int iArrSize);
void sortSelect(int iArray[], int iArrSize);
void sortQuick (int iArray[], int iArrSize);

#endif

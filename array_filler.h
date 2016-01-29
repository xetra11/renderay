#ifndef ARRAY_FILLER_H
#define ARRAY_FILLER_H

typedef struct{
  int height;
  int width;
}ArrayDimension;

typedef struct{
  ArrayDimension dimension;
  char* array;
}Canvas;

/* API */
Canvas createNewCanvas(int height, int width, char initValues);
void customFillArrayHorizontalLine(char* arrayToFill, char fillSymbol,int offset, int row, int count, int arrayWidth);
void customfillArrayVerticalLine(char* arrayToFill, char fillSymbol, int offset, int column, int count, int arrayWidth);
void fillArrayHorizontalLine(char* arrayToFill, char fillSymbol, int row, int arrayWidth);
void fillArrayVerticalLine(char* arrayToFill, char fillSymbol, int column, int arrayWidth, int arrayHeight);
void initializeArray(char* arrayToInit, char fillSymbol, int height, int width);
Canvas getNewCanvas(int height, int width, char initValues);

#endif

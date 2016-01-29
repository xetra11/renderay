#include <stdlib.h>
#include <stdio.h>
#include "array_filler.h"

/***************** API *************************/

Canvas createNewCanvas(int height, int width, char initValues){
  Canvas newCanvas;
    return newCanvas;
}

void initializeArray(/*Canvas newCanvas*/ char* arrayToInit, char fillSymbol, int height, int width){
  //char* arrayToInit = newCanvas.array;
  int iterator_Y;
  int iterator_X;

  for(iterator_Y = 0; iterator_Y < height; iterator_Y++){
    for(iterator_X = 0; iterator_X < width; iterator_X++){
      *(arrayToInit+iterator_X+(iterator_Y*width)) = fillSymbol;
    }
  }
}

void customFillArrayHorizontalLine(char* arrayToFill, char fillSymbol, int offset, int row, int count, int arrayWidth ){
  int iterator;
  int posToDrawAt;
  int rowToStartDrawing;

  for(iterator = 0; iterator < count; iterator++){
    rowToStartDrawing = row * arrayWidth;
    posToDrawAt = iterator + offset;
    *(arrayToFill+(posToDrawAt+rowToStartDrawing)) = fillSymbol;
  }
}

void customfillArrayVerticalLine(char* arrayToFill, char fillSymbol, int offset, int column, int count, int arrayWidth){
  int iterator;
  int posToDrawAt;
  int columnToStartDrawing;

  for(iterator = 0; iterator < count; iterator++){
    columnToStartDrawing = column;
    posToDrawAt = (iterator + offset) * arrayWidth;
    *(arrayToFill+(posToDrawAt+columnToStartDrawing)) = fillSymbol;
  }
}

void fillArrayHorizontalLine(char* arrayToFill, char fillSymbol, int row, int arrayWidth){
  int iterator;
  int posToDrawAt;
  int rowToStartDrawing;

  for(iterator = 0; iterator < arrayWidth; iterator++){
    rowToStartDrawing = row * arrayWidth;
    posToDrawAt = iterator;
    *(arrayToFill+(posToDrawAt+rowToStartDrawing)) = fillSymbol;
  }
}

void fillArrayVerticalLine(char* arrayToFill, char fillSymbol, int column, int arrayWidth, int arrayHeight){
  int iterator;
  int posToDrawAt;
  int columnToStartDrawing;

  for(iterator = 0; iterator < arrayHeight; iterator++){
    columnToStartDrawing = column;
    posToDrawAt = (iterator) * arrayWidth;
    *(arrayToFill+(posToDrawAt+columnToStartDrawing)) = fillSymbol;
  }
}

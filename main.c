#include <stdio.h>
#include <stdlib.h>
#include "array_filler.h"

#define ARRAY_HEIGHT 30
#define ARRAY_WIDTH 30

/*Prototypen*/
//Helper
void printArray(char* arrayToPrint, ArrayDimension dimension);
//Examples
void renderSmiley(char* arrayToSmile);
void renderCross(char* arrayToCross);
void renderSudokuField(char* arrayToRender);

int main(void){

  Canvas canvas;
  ArrayDimension arrayDimension;

  arrayDimension.height = ARRAY_HEIGHT;
  arrayDimension.width = ARRAY_WIDTH;
  char testArray[arrayDimension.height][arrayDimension.width];

  initializeArray(testArray[0], 32, ARRAY_HEIGHT, ARRAY_WIDTH);
  renderSmiley(testArray[0]);
  // renderCross(testArray[0]);
  // renderSudokuField(testArray[0]);
  // printArray(testArray[0], ARRAY_HEIGHT, ARRAY_WIDTH);
  printArray(testArray[0], arrayDimension);

  return 0;
}

/* Helper / Examples */

void renderSmiley(char* arrayToSmile){
  customFillArrayHorizontalLine(arrayToSmile, '|', 1, 0, 3, ARRAY_WIDTH);
  customFillArrayHorizontalLine(arrayToSmile, 'o', 0, 1, 1, ARRAY_WIDTH);
  customFillArrayHorizontalLine(arrayToSmile, 'o', 4, 1, 1, ARRAY_WIDTH);
  customFillArrayHorizontalLine(arrayToSmile, '@', 1, 2, 1, ARRAY_WIDTH);
  customFillArrayHorizontalLine(arrayToSmile, '@', 3, 2, 1, ARRAY_WIDTH);
  customFillArrayHorizontalLine(arrayToSmile, 'o', 0, 2, 1, ARRAY_WIDTH);
  customFillArrayHorizontalLine(arrayToSmile, 'o', 4, 2, 1, ARRAY_WIDTH);
  customFillArrayHorizontalLine(arrayToSmile, 'o', 0, 3, 1, ARRAY_WIDTH);
  customFillArrayHorizontalLine(arrayToSmile, 'o', 4, 3, 1, ARRAY_WIDTH);
  customFillArrayHorizontalLine(arrayToSmile, '-', 2, 3, 1 , ARRAY_WIDTH);
  customFillArrayHorizontalLine(arrayToSmile, 'o', 1, 4, 3, ARRAY_WIDTH);
}

void renderCross(char* arrayToCross){
  fillArrayHorizontalLine(arrayToCross, '-', 2, ARRAY_WIDTH);
  fillArrayVerticalLine(arrayToCross, '|', 2, ARRAY_WIDTH, ARRAY_HEIGHT);
}

void renderSudokuField(char* arrayToRender){
  fillArrayHorizontalLine(arrayToRender, '-', 1, ARRAY_WIDTH);
  fillArrayVerticalLine(arrayToRender, '|', 6, ARRAY_WIDTH, ARRAY_HEIGHT);
  fillArrayVerticalLine(arrayToRender, '|', 11, ARRAY_WIDTH, ARRAY_HEIGHT);
  fillArrayVerticalLine(arrayToRender, '|', 16, ARRAY_WIDTH, ARRAY_HEIGHT);
  fillArrayVerticalLine(arrayToRender, '|', 21, ARRAY_WIDTH, ARRAY_HEIGHT);
  fillArrayHorizontalLine(arrayToRender, '-', 6, ARRAY_WIDTH);
  fillArrayHorizontalLine(arrayToRender, '-', 11, ARRAY_WIDTH);
  fillArrayHorizontalLine(arrayToRender, '-', 16, ARRAY_WIDTH);
  fillArrayHorizontalLine(arrayToRender, '-',21, ARRAY_WIDTH);
}

void printArray(char* arrayToPrint, ArrayDimension dimension){
  int iterator_Y;
  int iterator_X;

  for(iterator_Y = 0; iterator_Y < dimension.height; iterator_Y++){
    for(iterator_X = 0; iterator_X < dimension.width; iterator_X++){
      printf("%c", *(arrayToPrint+(iterator_Y* dimension.width) + iterator_X));
    }
    printf("\n");
  }
}

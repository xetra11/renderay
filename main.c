#include <stdio.h>
#include <stdlib.h>
#include "renderay.h"

#define ARRAY_HEIGHT 5
#define ARRAY_WIDTH 5

/*Prototypen*/
//Helper
void printArray(Canvas* canvas, ArrayDimension dimension);
//Examples
void renderSmiley(Canvas* canvas);
void renderCross(Canvas* canvas);
void renderSudokuField(Canvas* canvas);

int main(void){

  Canvas* canvas = createNewCanvas(ARRAY_HEIGHT, ARRAY_WIDTH);

  //initializeArray(canvas, '.');

  renderSmiley(canvas);
  /* renderCross(canvas); */
  // renderSudokuField(testArray[0]);
  // printArray(testArray[0], ARRAY_HEIGHT, ARRAY_WIDTH);
  printArray(canvas, canvas->dimension);

  return 0;
}

/* Helper / Examples */

void renderSmiley(Canvas* canvas){
  char* arrayToSmile = canvas->array;

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

void renderCross(Canvas* canvas){
  char* arrayToCross = canvas->array;

  fillArrayHorizontalLine(arrayToCross, '-', 2, ARRAY_WIDTH);
  fillArrayVerticalLine(arrayToCross, '|', 2, ARRAY_WIDTH, ARRAY_HEIGHT);
}

void renderSudokuField(Canvas* canvas){
  char* arrayToRender = canvas->array;

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

void printArray(Canvas* canvas, ArrayDimension dimension){
  int iterator_Y;
  int iterator_X;
  char* arrayToPrint = canvas->array;

  for(iterator_Y = 0; iterator_Y < dimension.height; iterator_Y++){
    for(iterator_X = 0; iterator_X < dimension.width; iterator_X++){
      printf("%c", *(arrayToPrint+(iterator_Y* dimension.width) + iterator_X));
    }
    printf("\n");
  }
}

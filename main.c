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
  /* renderSudokuField(canvas); */
  // printArray(testArray[0], ARRAY_HEIGHT, ARRAY_WIDTH);
  printArray(canvas, canvas->dimension);

  return 0;
}

/* Helper / Examples */

void renderSmiley(Canvas* canvas){
  customFillArrayHorizontalLine(canvas, '|', 1, 0, 3);
  customFillArrayHorizontalLine(canvas, 'o', 0, 1, 1);
  customFillArrayHorizontalLine(canvas, 'o', 4, 1, 1);
  customFillArrayHorizontalLine(canvas, '@', 1, 2, 1);
  customFillArrayHorizontalLine(canvas, '@', 3, 2, 1);
  customFillArrayHorizontalLine(canvas, 'o', 0, 2, 1);
  customFillArrayHorizontalLine(canvas, 'o', 4, 2, 1);
  customFillArrayHorizontalLine(canvas, 'o', 0, 3, 1);
  customFillArrayHorizontalLine(canvas, 'o', 4, 3, 1);
  customFillArrayHorizontalLine(canvas, '-', 2, 3, 1);
  customFillArrayHorizontalLine(canvas, 'o', 1, 4, 3);
}

void renderCross(Canvas* canvas){
  fillArrayHorizontalLine(canvas, '-', 2);
  fillArrayVerticalLine(canvas, '|', 2);
}

void renderSudokuField(Canvas* canvas){
  fillArrayHorizontalLine(canvas, '-', 1);
  fillArrayVerticalLine(canvas, '|', 6);
  fillArrayVerticalLine(canvas, '|', 11);
  fillArrayVerticalLine(canvas, '|', 16);
  fillArrayVerticalLine(canvas, '|', 21);
  fillArrayHorizontalLine(canvas, '-', 6);
  fillArrayHorizontalLine(canvas, '-', 11);
  fillArrayHorizontalLine(canvas, '-', 16);
  fillArrayHorizontalLine(canvas, '-',21);
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

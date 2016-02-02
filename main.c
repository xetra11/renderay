#include <stdio.h>
#include <stdlib.h>
#include "renderay.h"

#define ARRAY_HEIGHT 30
#define ARRAY_WIDTH 50

/*Prototypen*/
//Helper
void printArray(Canvas* canvas, ArrayDimension dimension);
//Examples
void renderSmiley(Canvas* canvas);
void renderCross(Canvas* canvas);
void renderSudokuField(Canvas* canvas);

void renderTopHeader(Canvas* canvas, int gapSize);

int main(void){

  Canvas* canvas = createNewCanvas(ARRAY_HEIGHT, ARRAY_WIDTH);

  initializeArray(canvas, '.');

  /* renderSmiley(canvas); */
  /* renderCross(canvas); */
  renderSudokuField(canvas);
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
  renderTopHeader(canvas, 2);
}

void renderTopHeader(Canvas* canvas, int gapSize){
  int counter = 0;
  int iterator;
  int maxWidth = canvas->dimension.width;

  for(iterator = gapSize; iterator < maxWidth; iterator+=gapSize+1){
    fillPoint(canvas, 'A'+ counter++, iterator, 0);
  }
}

void printArray(Canvas* canvas, ArrayDimension dimension){
  int iterator_Y;
  int iterator_X;
  char* arrayToPrint = canvas->array;

  for(iterator_Y = 0; iterator_Y < dimension.height; iterator_Y++){
    for(iterator_X = 0; iterator_X < dimension.width; iterator_X++){
      printf("%c", arrayToPrint[iterator_Y* dimension.width + iterator_X]);
    }
    printf("\n");
  }
}

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "renderay_core.h"
#include "renderay_shapes.h"

#define ARRAY_HEIGHT 20
#define ARRAY_WIDTH 40


/*Prototypen*/
//Helper
void printArray(Canvas* canvas, ArrayDimension dimension);
//Examples
void renderSmiley(Canvas* canvas);
void renderCross(Canvas* canvas);
void renderSudokuField(Canvas* canvas);

void renderTopHeader(Canvas* canvas, int gapSize);
void renderLeftHeader(Canvas* canvas, int gapSize);
void renderHorizontalBars(Canvas* canvas);
void renderVerticalBars(Canvas* canvas);
void renderCrosses(Canvas* canvas);

int main(void){

  Canvas* canvas = new_Canvas(ARRAY_HEIGHT, ARRAY_WIDTH);

  /* canvas_fill(canvas, '.');  */

  shapes_rectangle(canvas, 0, 0, 10, 20);
  shapes_rectangle(canvas, 1, 1, 8, 18);
  shapes_rectangle(canvas, 2, 2, 6, 16);
  shapes_rectangle(canvas, 3, 3, 5, 14);
  shapes_rectangle(canvas, 4, 4, 3, 5);
  shapes_rectangle(canvas, 11, 4, 3, 5);

  /* renderSmiley(canvas); */
  /* renderCross(canvas); */
  /* renderSudokuField(canvas); */
  /* canvas_fillPoint(canvas, '9', 3,2); */
  printArray(canvas, canvas->dimension);

  return 0;
}

/* Helper / Examples */

void renderSmiley(Canvas* canvas){
  canvas_fillLineHorizontalCustom(canvas, '|', 1, 0, 3);
  canvas_fillLineHorizontalCustom(canvas, 'o', 0, 1, 1);
  canvas_fillLineHorizontalCustom(canvas, 'o', 4, 1, 1);
  canvas_fillLineHorizontalCustom(canvas, '@', 1, 2, 1);
  canvas_fillLineHorizontalCustom(canvas, '@', 3, 2, 1);
  canvas_fillLineHorizontalCustom(canvas, 'o', 0, 2, 1);
  canvas_fillLineHorizontalCustom(canvas, 'o', 4, 2, 1);
  canvas_fillLineHorizontalCustom(canvas, 'o', 0, 3, 1);
  canvas_fillLineHorizontalCustom(canvas, 'o', 4, 3, 1);
  canvas_fillLineHorizontalCustom(canvas, '-', 2, 3, 1);
  canvas_fillLineHorizontalCustom(canvas, 'o', 1, 4, 3);
}

void renderCross(Canvas* canvas){
  canvas_fillLineHorizontal(canvas, '-', 2);
  canvas_fillLineVertical(canvas, '|', 2);
}

void renderSudokuField(Canvas* canvas){
  renderTopHeader(canvas, 3);
  renderLeftHeader(canvas, 1);
  renderHorizontalBars(canvas);
  renderVerticalBars(canvas);
  renderCrosses(canvas);

}

void renderTopHeader(Canvas* canvas, int gapSize){
  int counter = 0;
  int iterator;
  int maxWidth = canvas->dimension.width;

  for(iterator = gapSize; iterator < maxWidth; iterator+=gapSize+1){
    canvas_fillPoint(canvas, 'A'+ counter++, iterator, 0);
  }

  canvas_fillLineHorizontal(canvas, '-', 1);

}
void renderLeftHeader(Canvas* canvas, int gapSize){
  int counter = 0;
  int iterator;
  int maxHeight = canvas->dimension.height;

  for(iterator = gapSize+1; iterator < maxHeight; iterator+=gapSize+1){
      canvas_fillPoint(canvas, counter++ + '0', 0, iterator);
    }

  canvas_fillLineVertical(canvas, '|', 1);
  canvas_fillPoint(canvas, '+', 1, 1);
}

void renderHorizontalBars(Canvas* canvas){
  int iterator;
  int maxWidth = canvas->dimension.width;

  for(iterator = 3; iterator < maxWidth; iterator+=2){
    canvas_fillLineHorizontal(canvas, '-', iterator );
  }
}

void renderVerticalBars(Canvas* canvas){
  int iterator;
  int maxWidth = canvas->dimension.width;

  for(iterator = 5; iterator < maxWidth; iterator+=4){
    canvas_fillLineVertical(canvas, '|', iterator );
  }
}

void renderCrosses(Canvas* canvas){
  int maxWidth = canvas->dimension.width;
  int maxHeight = canvas->dimension.height;
  int y;
  int x;

  /* canvas_fillPoint(canvas,'+', 5,1); */

  for(y = 1; y < maxHeight; y+=2){
    for(x = 1; x < maxWidth; x+=4){
      canvas_fillPoint(canvas, '+', x, y);
    }
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

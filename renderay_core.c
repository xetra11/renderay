/*
==========================================================================================================>
                     _
                    | |
  _ __ ___ _ __   __| | ___ _ __ __ _ _   _
 | '__/ _ | '_ \ / _` |/ _ | '__/ _` | | | |
 | | |  __| | | | (_| |  __| | | (_| | |_| |
 |_|  \___|_| |_|\__,_|\___|_|  \__,_|\__, |
                                       __/ |
                                      |___/

             +++ Core +++


 Author: Patrick C. Hoefer (xetra11)
 Version: 1.1.2
 Date: 06.02.2016
 ----------------------------------------------------------------------------------------------------------
                                                Description
 ----------------------------------------------------------------------------------------------------------
 The core library for renderay holds everything you need to render in a simple
 way within an array. To provide an array to which renderay can render into you
 have to create a Canvas type and pass it to the render functions
 ----------------------------------------------------------------------------------------------------------
                                                    API
 ----------------------------------------------------------------------------------------------------------
 Canvas* new_Canvas(int height, int width)
 void canvas_fillLineHorizontalCustom(Canvas* canvas, char fillSymbol,int offset, int row, int count);
 void canvas_fillLineVerticalCustom(Canvas* canvas, char fillSymbol, int offset, int column, int count);
 void canvas_fillLineHorizontal(Canvas* canvas, char fillSymbol, int row);
 void canvas_fillLineVertical(Canvas* canvas, char fillSymbol, int column);
 void canvas_fillPoint(Canvas* canvas, char fillSymbol, int x, int y);
 void canvas_fillLine(Canvas* canvas, char fillSymbol, int startX, int startY, int endX, int endY);
 void canvas_fill(Canvas* canvas, char fillSymbol);
 - - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Please read the DOC.md to get the whole documentation for renderay
 =========================================================================================================>
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "renderay_core.h"

int determineSign(int num);

Canvas* new_Canvas(int height, int width){
  ArrayDimension dimension ;
  Canvas* newCanvas = malloc(sizeof(Canvas));
  char* array = calloc(height, width);

  dimension.height = height;
  dimension.width = width;
  newCanvas->dimension = dimension;
  newCanvas->array = array;

  canvas_fill(newCanvas, 32);

  return newCanvas;
}

void canvas_fill(Canvas* newCanvas, char fillSymbol){
  char* arrayToInit = newCanvas->array;
  int height = newCanvas->dimension.height;
  int width = newCanvas->dimension.width;
  int iterator_Y;
  int iterator_X;

  for(iterator_Y = 0; iterator_Y < height; iterator_Y++){
    for(iterator_X = 0; iterator_X < width; iterator_X++){
      arrayToInit[iterator_X + iterator_Y*width] = fillSymbol;
    }
  }
}

void canvas_fillPoint(Canvas* canvas, char fillSymbol, int x, int y){
  char* arrayToFill = canvas->array;
  int maxWidth = canvas->dimension.width;
  int maxHeight = canvas->dimension.height;

  // check for invalid input
  if(x < 0 || y < 0){
    printf("Invalid parameter for (canvas_fillPoint): must not be lesser than zero!\n");
    return;
  }

  if(x > maxWidth || y > maxHeight){
    printf("Invalid parameter for (canvas_fillPoint): higher than canvas boundaries!\n");
    return;
  }

  if(x <= maxWidth && y <= maxHeight){
    arrayToFill[x+(y*maxWidth)] = fillSymbol;
  }
}

void canvas_fillLine(Canvas* canvas, char fillSymbol, int xStart, int yStart, int xEnd, int yEnd){
  int iterator;
  //paralell steps
  int paraX;
  int paraY;
  //diagonal steps
  int diagX;
  int diagY;
  //default coords
  int x_start  = xStart;
  int x_end    = xEnd;
  int y_start  = yStart;
  int y_end    = yEnd;
  int x        = x_start;
  int y        = y_start;

  // check for invalid input
  if(xStart < 0 || yStart < 0 || xEnd < 0 || yEnd < 0){
    printf("Invalid parameter for (canvas_fillLine): must not be lesser than zero!\n");
    return;
  }

  // calclate deltas
  int dx       = x_end - x_start;
  int dy       = y_end - y_start;

  // set sign
  int signOfX  = determineSign(dx);
  int signOfY  = determineSign(dy);
  if(dx < 0) dx = -dx;
  if(dy < 0) dy = -dy;

  int fastError;
  int slowError;
  int error;

  /* which direction has the faster draw frequency */
  if(dx>dy){
    /* x is the faster one */
    paraX = signOfX; // will step +1 or -1 or 0
    paraY = 0;       // will only diagonally cause slower
    diagX = signOfX;
    diagY = signOfY; // now y will step also
    fastError = dy;
    slowError = dx;
  }else{
    /* y is the faster one */
    paraX = 0;
    paraY = signOfY;
    diagX = signOfX;
    diagY = signOfY;
    fastError = dx;
    slowError = dy;
  }

  //init loop
  error = slowError/2;
  canvas_fillPoint(canvas, fillSymbol, x, y);

  /* count renders */
  for(iterator = 0; iterator < slowError; ++iterator){
    //update error
    error -= fastError;
    if(error < 0){
      /* make error pos again */
      error += slowError;
      /* one step to slower direction */
      x += diagX;
      y += diagY;
    }else{
      /* one step in fast direction */
      x += paraX;
      y += paraY;
    }
    canvas_fillPoint(canvas, fillSymbol, x, y);
  }
}

void canvas_fillLineHorizontalCustom(Canvas* canvas, char fillSymbol, int offset, int row, int count){
  char* arrayToFill = canvas->array;
  int arrayWidth =  canvas->dimension.width;
  int iterator;
  int posToDrawAt;
  int rowToStartDrawing;

  for(iterator = 0; iterator < count; iterator++){
    rowToStartDrawing = row * arrayWidth;
    posToDrawAt = iterator + offset;
    arrayToFill[posToDrawAt+rowToStartDrawing] = fillSymbol;
  }
}

void canvas_fillLineVerticalCustom(Canvas* canvas, char fillSymbol, int offset, int column, int count){
  char* arrayToFill = canvas->array;
  int arrayWidth = canvas->dimension.width;
  int iterator;
  int posToDrawAt;
  int columnToStartDrawing;

  for(iterator = 0; iterator < count; iterator++){
    columnToStartDrawing = column;
    posToDrawAt = (iterator + offset) * arrayWidth;
    arrayToFill[posToDrawAt+columnToStartDrawing] = fillSymbol;
  }
}

void canvas_fillLineHorizontal(Canvas* canvas, char fillSymbol, int row){
  char* arrayToFill = canvas->array;
  int arrayWidth = canvas->dimension.width;
  int iterator;
  int posToDrawAt;
  int rowToStartDrawing;

  for(iterator = 0; iterator < arrayWidth; iterator++){
    rowToStartDrawing = row * arrayWidth;
    posToDrawAt = iterator;
    arrayToFill[posToDrawAt+rowToStartDrawing] = fillSymbol;
  }
}

void canvas_fillLineVertical(Canvas* canvas, char fillSymbol, int column){
  char* arrayToFill = canvas->array;
  int arrayHeight = canvas->dimension.height;
  int arrayWidth = canvas->dimension.width;
  int iterator;
  int posToDrawAt;
  int columnToStartDrawing;

  for(iterator = 0; iterator < arrayHeight; iterator++){
    columnToStartDrawing = column;
    posToDrawAt = (iterator) * arrayWidth;
    arrayToFill[posToDrawAt+columnToStartDrawing] = fillSymbol;
  }
}


/* Helper */

int determineSign(int num){
  return (num > 0) ? 1 : (num < 0) ? -1 : 0;
}

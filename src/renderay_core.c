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
 Version: 1.5.1
 Date: 28.02.2016
 ----------------------------------------------------------------------------------------------------------
                                                Description
 ----------------------------------------------------------------------------------------------------------
 The core library for renderay holds everything you need to render in a simple
 way within an array. To provide an array to which renderay can render into you
 have to create a Canvas type and pass it to the render functions
*/

#include "renderay_core.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int determinnneSign(int num);

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

void canvas_renderPointByPoint(Canvas* canvas, char fillSymbol, Point point){
  char* arrayToFill = canvas->array;
  int maxWidth = canvas->dimension.width;
  int maxHeight = canvas->dimension.height;
  int x = point.x;
  int y = point.y;


  // check for invalid input
  if(x < 0 || y < 0){
    printf("Invalid parameter for (canvas_renderPointByPoint): must not be lesser than zero!\n");
    return;
  }

  if(x > maxWidth || y > maxHeight){
    printf("Invalid parameter for (canvas_renderPointByPoint): higher than canvas boundaries!\n");
    return;
  }

  if(x <= maxWidth && y <= maxHeight){
    arrayToFill[x+(y*maxWidth)] = fillSymbol;
  }
}

void canvas_renderPointByCoord(Canvas* canvas, char fillSymbol, int x, int y){
  char* arrayToFill = canvas->array;
  int maxWidth = canvas->dimension.width;
  int maxHeight = canvas->dimension.height;
  
  // check for invalid input
  if(x < 0 || y < 0){
    printf("Invalid parameter for (canvas_renderPointByPoint): must not be lesser than zero!\n");
    return;
  }

  if(x > maxWidth || y > maxHeight){
    printf("Invalid parameter for (canvas_renderPointByPoint): higher than canvas boundaries!\n");
    return;
  }

  if(x <= maxWidth && y <= maxHeight){
    arrayToFill[x+(y*maxWidth)] = fillSymbol;
  }
}

void canvas_renderLine(Canvas* canvas, char fillSymbol, Line line){
  int iterator;
  //paralell steps
  int paraX;
  int paraY;
  //diagonal steps
  int diagX;
  int diagY;
  //default coords
  int x_start  = line.start.x;
  int x_end    = line.end.x;
  int y_start  = line.start.y;
  int y_end    = line.end.y;
  Point point;
  point.x      = x_start;
  point.y      = y_start;

  // check for invalid input
  if(x_start < 0 || y_start < 0 || x_end < 0 || y_end < 0){
    printf("Invalid parameter for (canvas_renderLine): must not be lesser than zero!\n");
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
  canvas_renderPointByPoint(canvas, fillSymbol, point);

  /* count renders */
  for(iterator = 0; iterator < slowError; ++iterator){
    //update error
    error -= fastError;
    if(error < 0){
      /* make error pos again */
      error += slowError;
      /* one step to slower direction */
      point.x += diagX;
      point.y += diagY;
    }else{
      /* one step in fast direction */
      point.x += paraX;
      point.y += paraY;
    }
    canvas_renderPointByPoint(canvas, fillSymbol, point);
  }
}

void canvas_renderLineHorizontalCustom(Canvas* canvas, char fillSymbol, int offset, int row, int count){
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

void canvas_renderLineVerticalCustom(Canvas* canvas, char fillSymbol, int offset, int column, int count){
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

void canvas_renderLineHorizontal(Canvas* canvas, char fillSymbol, int row){
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

void canvas_renderLineVertical(Canvas* canvas, char fillSymbol, int column){
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

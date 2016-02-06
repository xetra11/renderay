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
 Version: 1.0
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
 void canvas_fill(Canvas* canvas, char fillSymbol);
 - - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Please read the DOC.md to get the whole documentation for renderay
 =========================================================================================================>
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "renderay_core.h"

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

  if(x <= maxWidth && y <= maxHeight){
    arrayToFill[x+(y*maxWidth)] = fillSymbol;
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

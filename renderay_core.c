/*
author: Patrick Hoefer
name: renderay-core (render & array)
description: Renderay tries to simplify the rendering of arrays.
             Therefore the API provides the user with static and
             customizable functions to draw characters into a
             character array.
documentation: How to:
               To start rendering an array and printing it to the screen th               e user has to create a "Canvas" type/object first. A Canvas
               holds the dimension and the pointer to the corresponding
               array to easy the use of functions due slim parameterlist
               and to capsule canvas-specific state like the width and the
               height.
               After creating an canvas the user can pass it to the render-
               ing functions and let the canvas be filled with specified
               characters at the customized positions. The usecase of
               this library is to create custom functions to draw with the
               help of the rendering functions provided by Renderay.
version: 1.0
date: 29.01.2016
dependencies: -
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

/*
author: Patrick Hoefer
name: renderay (render & array)
description: Renderay tries to simplify the rendering of arrays.
             Therefore the API provides the user with static and
             customizable functions to draw characters into a
             character array.
documentation: How to:
               To start rendering an array and printing it to the screen the
               user has to create a "Canvas" type/object first. A Canvas
               holds the dimension and the pointer to the corresponding
               array to easy the use of functions due slim parameterlist
               and to capsule canvas-specific state like the width and the
               height.
               After creating an canvas the user can pass it to the render-
               ing functions and let the canvas be filled with specified
               characters at the customized positions. The usecase of
               this library is to create custom functions to draw with the
               help of the rendering functions provided by Renderay.
version: 0.1
date: 29.01.2016
dependencies: renderay.c
*/

#ifndef RENDERAY_H
#define RENDERAY_H

typedef struct{
  int height;
  int width;
}ArrayDimension;

typedef struct{
  ArrayDimension dimension;
  char* array;
}Canvas;

/* API */
Canvas* new_Canvas(int height, int width);
void canvas_fillLineHorizontalCustom(Canvas* canvas, char fillSymbol,int offset, int row, int count);
void canvas_fillLineVerticalCustom(Canvas* canvas, char fillSymbol, int offset, int column, int count);
void canvas_fillLineHorizontal(Canvas* canvas, char fillSymbol, int row);
void canvas_fillLineVertical(Canvas* canvas, char fillSymbol, int column);
void canvas_fillPoint(Canvas* canvas, char fillSymbol, int x, int y);
void canvas_fill(Canvas* canvas, char fillSymbol);


#endif

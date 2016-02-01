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
Canvas* createNewCanvas(int height, int width);
void customFillArrayHorizontalLine(char* arrayToFill, char fillSymbol,int offset, int row, int count, int arrayWidth);
void customfillArrayVerticalLine(char* arrayToFill, char fillSymbol, int offset, int column, int count, int arrayWidth);
void fillArrayHorizontalLine(char* arrayToFill, char fillSymbol, int row, int arrayWidth);
void fillArrayVerticalLine(char* arrayToFill, char fillSymbol, int column, int arrayWidth, int arrayHeight);
void initializeArray(Canvas* canvas, char fillSymbol);
Canvas getNewCanvas(int height, int width, char initValues);

#endif

/*
================================================================================>
                     _
                    | |
  _ __ ___ _ __   __| | ___ _ __ __ _ _   _
 | '__/ _ | '_ \ / _` |/ _ | '__/ _` | | | |
 | | |  __| | | | (_| |  __| | | (_| | |_| |
 |_|  \___|_| |_|\__,_|\___|_|  \__,_|\__, |
                                       __/ |
                                      |___/

             +++ Shapes +++


 Author: Patrick C. Hoefer (xetra11)
 Version: 1.5.1
 Date: 28.02.2016
 --------------------------------------------------------------------------------
                                   Description
 --------------------------------------------------------------------------------
 renderay-shapes is a library based on renderay-core.
 It provides a simple API for geometrical shapes like
 rectangles, circles and so on.
 --------------------------------------------------------------------------------
                                       API
 --------------------------------------------------------------------------------
 void shapes_renderRectangle(Canvas* canvas, int left, int top, int height, int width)
 void shapes_renderRectangleDOS(Canvas* canvas, int left, int top, int height, int width)
 void shapes_renderCircle(Canvas* canvas, int x, int y, int radius);
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Please read the DOC.md to get the whole documentation for renderay
================================================================================>
*/


#include <stdio.h>
#include "renderay_core.h"
#include "renderay_shapes.h"

void renderRectangleTop(Canvas* canvas, int left, int top, int width, char edgeSymbol, char hzSymbol);
void renderRectangleBottom(Canvas* canvas, int left, int top, int height, int width, char edgeSymbol, char hzSymbol);
void renderRectangleLeft(Canvas* canvas, int left, int top, int height, char edgeSymbol, char vtSymbol);
void renderRectangleRight(Canvas* canvas, int left, int top, int height, int width, char edgeSymbol, char vtSymbol);
void renderRectangle(Canvas* canvas, int left, int top, int height, int width, char edgeSymbol);

void shapes_renderCircle(Canvas* canvas, int x_mid, int y_mid, int radius){

  int error = 1 - radius;
  int diagX = 0;
  int diagY = -2 * radius;
  int x = 0;
  int y = radius;

  // render anchor points (top, left, right, bottom)
  canvas_renderPoint(canvas,'+', x_mid, y_mid + radius);
  canvas_renderPoint(canvas,'+', x_mid, y_mid - radius);
  canvas_renderPoint(canvas,'+', x_mid + radius, y_mid);
  canvas_renderPoint(canvas,'+', x_mid - radius, y_mid);

  while(x < y){
    if(error >= 0){
      y--;
      diagY += 2;
      error += diagY;
    }
    x++;
    diagX += 2;
    error += diagX + 1;
  }

  canvas_renderPoint(canvas, '+', x_mid + x, y_mid + y);
  canvas_renderPoint(canvas, '+', x_mid - x, y_mid + y);
  canvas_renderPoint(canvas, '+', x_mid + x, y_mid - y);
  canvas_renderPoint(canvas, '+', x_mid - x, y_mid - y);
  canvas_renderPoint(canvas, '+', x_mid + y, y_mid + x);
  canvas_renderPoint(canvas, '+', x_mid - y, y_mid + x);
  canvas_renderPoint(canvas, '+', x_mid + y, y_mid - x);
  canvas_renderPoint(canvas, '+', x_mid - y, y_mid - x);

}

void shapes_renderRectangle(Canvas* canvas, int left, int top, int height, int width){
  char edgeSymbol = '+';
  renderRectangle(canvas, left, top, height, width, edgeSymbol);
}

void shapes_renderRectangleDOS(Canvas* canvas, int left, int top, int height, int width){

  char vtSymbol = '\xB3';
  char hzSymbol = '\xC4';

  renderRectangleTop(canvas, left, top, width, '\xC5', hzSymbol );
  renderRectangleBottom(canvas, left, top, height, width, '\xC5', hzSymbol);
  renderRectangleLeft(canvas, left, top, height, '\xC5', vtSymbol);
  renderRectangleRight(canvas, left, top, height, width, '\xC5', vtSymbol);
}

void renderRectangle(Canvas* canvas, int left, int top, int height, int width, char edgeSymbol){
  char hzSymbol = '-';
  char vtSymbol = '|';

  renderRectangleTop(canvas, left, top, width, edgeSymbol, hzSymbol);
  renderRectangleBottom(canvas, left, top, height, width, edgeSymbol, hzSymbol);
  renderRectangleLeft(canvas, left, top, height, edgeSymbol, vtSymbol);
  renderRectangleRight(canvas, left, top, height, width, edgeSymbol, vtSymbol);
}

void renderRectangleTop(Canvas* canvas, int left, int top, int width, char edgeSymbol, char lineSymbol){
  char* array = canvas->array;
  int maxWidth = canvas->dimension.width;
  int iterator = 0;
  int posToDrawAt = 0;
  int edgeDrawBegin = iterator + left + (top*maxWidth);
  int edgeDrawEnd = (width-1) + left + (top*maxWidth);

  for(iterator = 0; iterator < width; iterator++ ){
    posToDrawAt = iterator + left + (top*maxWidth);
    array[posToDrawAt] = lineSymbol;
  }

  array[edgeDrawBegin] = edgeSymbol;
  array[edgeDrawEnd] = edgeSymbol;

}

void renderRectangleBottom(Canvas* canvas, int left, int top, int height, int width, char edgeSymbol, char lineSymbol){
  char* array = canvas->array;
  int maxWidth = canvas->dimension.width;
  int iterator = 0;
  int posToDrawAt = 0;
  int edgeDrawBegin = iterator + left + ((top + height-1)*maxWidth);
  int edgeDrawEnd = (width-1) + left + ((top + height-1)*maxWidth);

  for(iterator = 0; iterator < width; iterator++ ){
    posToDrawAt = iterator + left + ((top + height-1)*maxWidth);
    array[posToDrawAt] = lineSymbol;
  }

  array[edgeDrawBegin] = edgeSymbol;
  array[edgeDrawEnd] = edgeSymbol;

}

void renderRectangleLeft(Canvas* canvas, int left, int top, int height, char edgeSymbol, char lineSymbol){
  char* array = canvas->array;
  int maxWidth = canvas->dimension.width;
  int iterator = 0;
  int posToDrawAt = 0;
  int edgeDrawBegin = (top * maxWidth) + (iterator * maxWidth) + left;
  //  int edgeDrawEnd = iterator + left + (height*maxWidth);

  for(iterator = 0; iterator < height-1; iterator++ ){
    posToDrawAt = ((iterator+top) * maxWidth) + left;
    array[posToDrawAt] = lineSymbol;
  }

  array[edgeDrawBegin] = edgeSymbol;
}

void renderRectangleRight(Canvas* canvas, int left, int top, int height, int width, char edgeSymbol, char lineSymbol){
  char* array = canvas->array;
  int maxWidth = canvas->dimension.width;
  int iterator = 0;
  int posToDrawAt = 0;
  int edgeDrawBegin = ((iterator+top) * maxWidth) + (left+width-1);
  //  int edgeDrawEnd = iterator + left + (height*maxWidth);

  for(iterator = 0; iterator < height-1; iterator++ ){
    posToDrawAt = ((iterator+top) * maxWidth) + (left+width-1);
    array[posToDrawAt] = lineSymbol;
  }

  array[edgeDrawBegin] = edgeSymbol;
}

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
 Version: 1.3.1
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
 void canvas_renderLineHorizontalCustom(Canvas* canvas, char fillSymbol,int offset, int row, int count);
 void canvas_renderLineVerticalCustom(Canvas* canvas, char fillSymbol, int offset, int column, int count);
 void canvas_renderLineHorizontal(Canvas* canvas, char fillSymbol, int row);
 void canvas_renderLineVertical(Canvas* canvas, char fillSymbol, int column);
 void canvas_renderPoint(Canvas* canvas, char fillSymbol, int x, int y);
 void canvas_renderLine(Canvas* canvas, char fillSymbol, int startX, int startY, int endX, int endY);
 void canvas_fill(Canvas* canvas, char fillSymbol);
 - - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Please read the DOC.md to get the whole documentation for renderay
 =========================================================================================================>
*/

#ifndef RENDERAY_CORE_H
#define RENDERAY_CORE_H

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
void canvas_renderLineHorizontalCustom(Canvas* canvas, char fillSymbol,int offset, int row, int count);
void canvas_renderLineVerticalCustom(Canvas* canvas, char fillSymbol, int offset, int column, int count);
void canvas_renderLineHorizontal(Canvas* canvas, char fillSymbol, int row);
void canvas_renderLineVertical(Canvas* canvas, char fillSymbol, int column);
void canvas_renderPoint(Canvas* canvas, char fillSymbol, int x, int y);
void canvas_fill(Canvas* canvas, char fillSymbol);
void canvas_renderLine(Canvas* canvas, char fillSymbol, int xStart, int yStart, int xEnd, int yEnd);


#endif

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
void canvas_fillLineHorizontalCustom(Canvas* canvas, char fillSymbol,int offset, int row, int count);
void canvas_fillLineVerticalCustom(Canvas* canvas, char fillSymbol, int offset, int column, int count);
void canvas_fillLineHorizontal(Canvas* canvas, char fillSymbol, int row);
void canvas_fillLineVertical(Canvas* canvas, char fillSymbol, int column);
void canvas_fillPoint(Canvas* canvas, char fillSymbol, int x, int y);
void canvas_fill(Canvas* canvas, char fillSymbol);


#endif

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

#ifndef RENDERAY_SHAPES_H
#define RENDERAY_SHAPES_H

#include "renderay_core.h"

typedef struct{
  Point center;
  int radius;
}Circle;


void shapes_renderRectangle(Canvas* canvas, int x, int y, int height, int width);
void shapes_renderRectangleDOS(Canvas* canvas, int x, int y, int height, int width);
void shapes_renderCircle(Canvas* canvas, Circle circle);

#endif

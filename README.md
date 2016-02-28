#Renderay [![Build Status](https://travis-ci.org/xetra11/renderay.svg?branch=master)](https://travis-ci.org/xetra11/renderay)

*Author: Patrick C. H.*  
***Stable Release: 1.5.1***  
[[**Download .zip**]](https://github.com/xetra11/renderay/archive/v.1.5.1.zip)  
[[**Download .tar.gz**]](https://github.com/xetra11/renderay/archive/v.1.5.1.tar.gz)



1. What is it?
2. How to use?
3. Modules
  1. Core
  2. Shapes
4. Future Plans

### 1. What is it?
Well it's the best thing you might ever step over...if you have nothing better to do than filling two-dimensional arrays with ascii characters. I created it to ease the filling of friggin' 2D arrays for myself and well it's my first real library. So I try to make it as professional as possible in the range of making something that has been done a thousand times before. I still hope anybody might say "Oh yeee jeez thats exactly what I was looking for".

### 2. How to use?
Before using this you should be at least familiar with the way to integrate libraries to your projects in C/C++. If you're capable of this kind of magic just download and include "renderay_core.h", "renderay_core.c", "renderay_shapes.h", "renderay_shapes.c" files to your project folder or wherever you wanna keep your libs.

If you just want to draw horizontal or vertical lines and/or plain single symbols to the array then you only need **renderay_core**

If you might want to already have rectangles being rendered out of the box, then you should include **renderay_shapes** as well.

#####Example:

```C
#include "renderay_core.h"
#include "renderay_shapes.h"

#define ARRAY_HEIGHT 10
#define ARRAY_WIDTH 20

void printCanvas(Canvas* canvas);

int main(void){
  Canvas* canvas = new_Canvas(ARRAY_HEIGHT, ARRAY_WIDTH); // create a canvas to render to
  shapes_renderRectangle(canvas, 0, 0, 5, 5); // render a shape to the canvas (see Submodules/Shapes for the API)
  printCanvas(canvas); // print the canvas (not a build in function!)
  
  return 0;
}

void printCanvas(Canvas* canvas){
int x;
int y;
int maxHeight = canvas->dimension.height;
int maxWidth = canvas->dimension.width;
char* arrayToPrint = canvas->array;

for(y = 0; y < maxHeight; y++){
  for(x = 0; x < maxWidth; x++){
    printf("%c", arrayToPrint[(y * maxWidth) + x]);  
  }
  printf("\n");
}
```


#####Output:
```
+---+                                   
|   |                                   
|   |                                   
|   |                                   
+---+ 
```

###3. Modules
####1. Core

The core API provides the basic functionality to render onto a canvas. You can draw a vertical, horizontal line with ascii characters or just a point. Every function needs the canvas as a parameter.
##### Functions:
```C
Canvas* new_Canvas(int height, int width)
```
>######Description:
>First step function to get renderay to work. This will create a canvas to render onto. This canvas will be passed to every of the following functions.
>######Parameters:
>*height* - set the height of the canvas  
>*width* - set the width of the canvas  
>######Returns:
>*Canvas** - the canvas "object" you can use to render onto  

```C
void canvas_fill(Canvas* canvas, char fillSymbol)
```
>######Description:
>This function will fill the whole canvas with the given fill symbol. Good practice to measure the positions of rendered objects in a canvas is to give '.' as fill symbol. This will fill the whole canvas with dots where you can check if the object is in the wanted position i.e.
>######Parameters:
>*canvas* - the canvas this function should render onto  
>*fillSymbol* - the ascii character that should be rendered  
>######Returns:
>*void* - nothing 

```C
void canvas_renderLineHorizontalCustom(Canvas* canvas, char fillSymbol, int offset, int row, int count)
```
>######Description:
>Renders a horizontal line onto the canves starting at the given offset and row. The count you provide will determine the maximal length of the line.
>######Parameters:
>*canvas* - the canvas this function should render onto  
>*fillSymbol* - the ascii character that should be rendered  
>*offset* - the offset position (horizontal) the rendering should start at 
>*row* - the row the rendering should start at  
>*count* - the amount of characters that should be rendered  
>######Returns:
>*void* - nothing  

```C
void canvas_renderLineVerticalCustom(Canvas* canvas, char fillSymbol, int offset, int column, int count)
```
>######Description:
>Renders a vertical line onto the canves starting at the given offset and column. The count you provide will determine the maximal length of the line.
>######Parameters:
>*canvas* - the canvas this function should render onto  
>*fillSymbol* - the ascii character that should be rendered  
>*offset* - the offset position (vertical) the rendering should start at 
>*column* - the column the rendering should start at  
>*count* - the amount of characters that should be rendered  
>######Returns:
>*void* - nothing  

```C
void canvas_renderLineHorizontal(Canvas* canvas, char fillSymbol, int row)
```
>######Description:
>Renders a horizontal line from the most left to the most right of the canvas width. You only need to provide the row where the rendering should start at.
>######Parameters:
>*canvas* - the canvas this function should render onto  
>*fillSymbol* - the ascii character that should be rendered  
>*row* - the row the line should be rendered in  
>######Returns:
>*void* - nothing  

```C
void canvas_renderLineVertical(Canvas* canvas, char fillSymbol, int column)
```
>######Description:
>Renders a vertical line from the top to the bottom of the canvas. You only need to provide the column where the rendering should start at.
>######Parameters:
>*canvas* - the canvas this function should render onto  
>*fillSymbol* - the ascii character that should be rendered  
>*column* - the column the line should be rendered in  
>######Returns:
>*void* - nothing 

```C
void canvas_renderLine(Canvas* canvas, char fillSymbol, int startX, int startY, int endX, int endY)
```
>######Description:
>Renders a line from the given start (startX, startY) to the destination (endX, endY)
>######Parameters:
>*canvas* - the canvas this function should render onto  
>*fillSymbol* - the ascii character that should be rendered  
>*startX* - the x position to start the line at  
>*startY* - the y position to start the line at  
>*endX* - the x position of the lines destination   
>*endY* - the y position of the lines destination     
>######Returns:
>*void* - nothing 

```C
void canvas_renderPoint(Canvas* canvas, char fillSymbol, int x, int y)
```
>######Description:
>Renders the given fill symbol to a specific positon(x,y) onto the canvas.
>######Parameters:
>*canvas* - the canvas this function should render onto  
>*fillSymbol* - the ascii character that should be rendered  
>*x* - the x position of the point  
>*y* - the y position of the point  
>######Returns:
>*void* - nothing 

####1. Shapes

The shapes module provides some predefined solutions to render simple shapes like rectangles and circles. It therefore uses the functions of renderay-core so its depenend on that module.
##### Functions:

```C
void shapes_renderRectangle(Canvas* canvas, int left, int top, int height, int width)
```
>######Description:
>Renders a rectangle with given dimensions starting at the top and left position.
>######Parameters:
>*canvas* - the canvas this function should render onto  
>*left* - the left point to start rendering  
>*top* - the top point to start rendering  
>*height* - the maximal height of the rectangle  
>*width* - the maximal width of the rectangle  
>######Returns:
>*void* - nothing 

```C
void shapes_renderRectangleDOS(Canvas* canvas, int left, int top, int height, int width)
```
>######Description:
>Renders a rectangle with given dimensions starting at the top and left position. Uses DOS ASCII to draw lines.  
**Warning** This will only work for Windows/DOS Consoles
>######Parameters:
>*canvas* - the canvas this function should render onto  
>*left* - the left point to start rendering  
>*top* - the top point to start rendering  
>*height* - the maximal height of the rectangle  
>*width* - the maximal width of the rectangle  
>######Returns:
>*void* - nothing 


```C
void shapes_renderCircle(Canvas* canvas, int x, int y, int radius)
```
>######Description:
>Renders a circle with the mid point (x, y) and its radius. Still looks weird because of the width to height relation of the console.
>######Parameters:
>*canvas* - the canvas this function should render onto  
>*x* - the x position of the middle point  
>*y* - the y position of the middle point  
>*radius* - the radius to draw to  
>######Returns:
>*void* - nothing 




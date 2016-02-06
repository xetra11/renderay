#Renderay

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
  shapes_rectangle(canvas, 5, 5, 5, 5); // render a shape to the canvas (see Submodules/Shapes for the API)
  print(canvas); // print the canvas (not a build in function!)
  
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
######Parameters:
*height* - set the height of the canvas  
*width* - set the width of the canvas  
######Returns:
*Canvas**


```C
void canvas_fillLineHorizontalCustom(Canvas* canvas, char fillSymbol,int offset, int row, int count)
void canvas_fillLineVerticalCustom(Canvas* canvas, char fillSymbol, int offset, int column, int count)
void canvas_fillLineHorizontal(Canvas* canvas, char fillSymbol, int row)
void canvas_fillLineVertical(Canvas* canvas, char fillSymbol, int column)
void canvas_fillPoint(Canvas* canvas, char fillSymbol, int x, int y)
void canvas_fill(Canvas* canvas, char fillSymbol)
```

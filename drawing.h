#ifndef DRAWING_H
#define DRAWING_H

#include "canvas.h"

// Line drawing function: Draws a line from (x1, y1) to (x2, y2)
void draw_line(char grid[HEIGHT][WIDTH], int x1, int y1, int x2, int y2);

// Rectangle drawing function: Top-left at (x, y), with width (w) and height (h)
void draw_rectangle(char grid[HEIGHT][WIDTH], int x, int y, int w, int h);

// Add these two lines to the bottom of drawing.h:
void draw_circle(char grid[HEIGHT][WIDTH], int xc, int yc, int r);
void draw_triangle(char grid[HEIGHT][WIDTH], int x1, int y1, int x2, int y2, int x3, int y3);

#endif
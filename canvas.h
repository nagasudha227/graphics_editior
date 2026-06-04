#ifndef CANVAS_H
#define CANVAS_H

// Defining the dimensions of our drawing grid
#define WIDTH 60
#define HEIGHT 20

// Function declarations: Telling the compiler these functions exist in canvas.c
void clear_grid(char grid[HEIGHT][WIDTH]);
void print_grid(char grid[HEIGHT][WIDTH]);

#endif
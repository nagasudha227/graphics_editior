#include <stdio.h>
#include "canvas.h"

// Fills the 2D grid array entirely with underscores '_'
void clear_grid(char grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = '_';
        }
    }
}

// Prints the 2D grid to the terminal screen line-by-line
void print_grid(char grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n"); // Move to the next row
    }
}
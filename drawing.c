#include <stdio.h>
#include <stdlib.h> // Needed for the abs() math function
#include "drawing.h"

// Bresenham's Line Algorithm to plot '*' on our grid
void draw_line(char grid[HEIGHT][WIDTH], int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        // Only draw if the coordinates are inside the grid boundaries
        if (x1 >= 0 && x1 < WIDTH && y1 >= 0 && y1 < HEIGHT) {
            grid[y1][x1] = '*'; // Draw the point using an asterisk
        }

        // If we reached the end coordinates, stop
        if (x1 == x2 && y1 == y2) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

// Rectangle drawing: Connects 4 lines to make a box
void draw_rectangle(char grid[HEIGHT][WIDTH], int x, int y, int w, int h) {
    // 1. Draw top border
    draw_line(grid, x, y, x + w - 1, y);
    // 2. Draw bottom border
    draw_line(grid, x, y + h - 1, x + w - 1, y + h - 1);
    // 3. Draw left border
    draw_line(grid, x, y, x, y + h - 1);
    // 4. Draw right border
    draw_line(grid, x + w - 1, y, x + w - 1, y + h - 1);
}
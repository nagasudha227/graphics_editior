#include <stdio.h>
#include "canvas.h"
#include "drawing.h" // Include our new drawing functions

int main() {
    // 1. Allocate the 2D grid
    char grid[HEIGHT][WIDTH];

    // 2. Clear the grid to all underscores
    clear_grid(grid);

    // 3. Test drawing lines (an X shape across the canvas)
    // Line 1: Top-left to bottom-right
    draw_line(grid, 0, 0, 59, 19);
    // Line 2: Bottom-left to top-right
    draw_line(grid, 0, 19, 59, 0);

    // 4. Test drawing a rectangle in the center
    // Starting at x=20, y=5, width=20, height=10
    draw_rectangle(grid, 20, 5, 20, 10);

    // 5. Print the grid to the terminal screen
   printf("=== 2D Graphics Editor ===\n\n");
    print_grid(grid);
    printf("\nGrid rendered with shapes successfully!\n");

    return 0;
}
#include <stdio.h>
#include "canvas.h"

int main() {
    // 1. Allocate the 2D grid in memory
    char grid[HEIGHT][WIDTH];

    // 2. Fill the grid with underscores
    clear_grid(grid);

    // 3. Print the blank grid to the screen
    printf("=== 2D Graphics Editor (Day 1: Blank Canvas) ===\n\n");
    print_grid(grid);
    printf("\nGrid initialized and rendered successfully!\n");

    return 0;
}
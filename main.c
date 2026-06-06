#include <stdio.h>
#include "canvas.h"
#include "drawing.h"

int main() {
    char grid[HEIGHT][WIDTH];

    // 1. Clear the grid to all underscores
    clear_grid(grid);

    // 2. Test Line (Top-Left)
    // From (2, 2) to (15, 8)
    draw_line(grid, 2, 2, 15, 8);

    // 3. Test Rectangle (Top-Right)
    // Top-left at (40, 2), width = 15, height = 6
    draw_rectangle(grid, 40, 2, 15, 6);

    // 4. Test Triangle (Bottom-Left)
    // Connecting points (5, 12), (20, 18), and (5, 18)
    draw_triangle(grid, 5, 12, 20, 18, 5, 18);

    // 5. Test Circle (Bottom-Right)
    // Center at (45, 13), radius = 5
    draw_circle(grid, 45, 13, 5);

    // 6. Print the final grid
    printf("=== 2D Graphics Editor ===\n\n");
    print_grid(grid);
    printf("\nGrid rendered with all 4 shapes successfully!\n");

    return 0;
}
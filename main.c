#include <stdio.h>
#include "canvas.h"
#include "drawing.h"
#include "shape_manager.h"
int main() {
    char grid[HEIGHT][WIDTH];

    
       // 1. Initialize our shape database
    init_shape_manager();

    // 2. Pack the shape parameters into Shape structs and add them to the database
    Shape line = { SHAPE_LINE, .x1 = 2, .y1 = 2, .x2 = 15, .y2 = 8 };
    add_shape(line);

    Shape rect = { SHAPE_RECTANGLE, .x1 = 40, .y1 = 2, .x2 = 15, .y2 = 6 };
    add_shape(rect);

    Shape tri = { SHAPE_TRIANGLE, .x1 = 5, .y1 = 12, .x2 = 20, .y2 = 18, .x3 = 5, .y3 = 18 };
    add_shape(tri);

    Shape circ = { SHAPE_CIRCLE, .x1 = 45, .y1 = 13, .r = 5 };
    add_shape(circ);

    // 3. Draw all shapes from our database onto the grid automatically
    render_all_shapes(grid);

    // 6. Print the final grid
    printf("=== 2D Graphics Editor ===\n\n");
    print_grid(grid);
    printf("\nGrid rendered with all 4 shapes successfully!\n");
        // 7. Test Deleting the Rectangle (which is at index 1)
    printf("\n--- Test: Deleting the Rectangle (Index 1) and redrawing ---\n");
    delete_shape(1); // Delete shape at index 1
    
    render_all_shapes(grid); // Clear grid and redraw the remaining 3 shapes
    print_grid(grid);        // Show the updated grid

    return 0;
}
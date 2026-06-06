#include <stdio.h>
#include "shape_manager.h"
#include "drawing.h"

// 1. Local database variables (hidden inside this file)
static Shape shapes[MAX_SHAPES];
static int shape_count = 0;

// Initializes the shape database
void init_shape_manager() {
    shape_count = 0;
}

// Returns the number of active shapes
int get_shape_count() {
    return shape_count;
}

// Adds a shape to our list
int add_shape(Shape s) {
    if (shape_count >= MAX_SHAPES) {
        return 0; // Fail: list is full
    }
    shapes[shape_count] = s;
    shape_count++;
    return 1; // Success
}

// Deletes a shape at a specific index
int delete_shape(int index) {
    if (index < 0 || index >= shape_count) {
        return 0; // Fail: invalid index
    }
    
    // Shift all shapes after the deleted one to the left to close the gap
    for (int i = index; i < shape_count - 1; i++) {
        shapes[i] = shapes[i + 1];
    }
    
    shape_count--;
    return 1; // Success
}

// Modifies a shape at a specific index with new parameters
int modify_shape(int index, Shape new_shape) {
    if (index < 0 || index >= shape_count) {
        return 0; // Fail: invalid index
    }
    shapes[index] = new_shape;
    return 1; // Success
}

// Clears the grid and draws all active shapes in order
void render_all_shapes(char grid[HEIGHT][WIDTH]) {
    // First, clear the canvas to blank underscores
    clear_grid(grid);
    
    // Loop through the list and draw each shape
    for (int i = 0; i < shape_count; i++) {
        Shape s = shapes[i];
        switch (s.type) {
            case SHAPE_LINE:
                draw_line(grid, s.x1, s.y1, s.x2, s.y2);
                break;
            case SHAPE_RECTANGLE:
                // x2 and y2 store width and height
                draw_rectangle(grid, s.x1, s.y1, s.x2, s.y2);
                break;
            case SHAPE_CIRCLE:
                // r stores the radius
                draw_circle(grid, s.x1, s.y1, s.r);
                break;
            case SHAPE_TRIANGLE:
                draw_triangle(grid, s.x1, s.y1, s.x2, s.y2, s.x3, s.y3);
                break;
        }
    }
}

// Prints a text list of all shapes currently in memory
void print_shape_list() {
    if (shape_count == 0) {
        printf("No shapes added yet.\n");
        return;
    }
    
    for (int i = 0; i < shape_count; i++) {
        Shape s = shapes[i];
        printf("[%d] ", i); // Show the index number (e.g. [0], [1])
        
        switch (s.type) {
            case SHAPE_LINE:
                printf("Line from (%d, %d) to (%d, %d)\n", s.x1, s.y1, s.x2, s.y2);
                break;
            case SHAPE_RECTANGLE:
                printf("Rectangle at (%d, %d) with width %d, height %d\n", s.x1, s.y1, s.x2, s.y2);
                break;
            case SHAPE_CIRCLE:
                printf("Circle at center (%d, %d) with radius %d\n", s.x1, s.y1, s.r);
                break;
            case SHAPE_TRIANGLE:
                printf("Triangle corners: (%d, %d), (%d, %d), (%d, %d)\n", s.x1, s.y1, s.x2, s.y2, s.x3, s.y3);
                break;
        }
    }
}
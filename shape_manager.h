#ifndef SHAPE_MANAGER_H
#define SHAPE_MANAGER_H

#include "canvas.h"

// 1. Defining the types of shapes our editor supports
typedef enum {
    SHAPE_LINE,
    SHAPE_RECTANGLE,
    SHAPE_CIRCLE,
    SHAPE_TRIANGLE
} ShapeType;

// 2. Struct to store information for any type of shape
typedef struct {
    ShapeType type;
    int x1, y1; // Point 1 (Line start / Rectangle top-left / Circle center / Triangle corner 1)
    int x2, y2; // Point 2 (Line end / Rectangle width & height / Triangle corner 2)
    int x3, y3; // Point 3 (Triangle corner 3 - only used for triangles)
    int r;      // Radius (only used for circles)
} Shape;

// 3. Maximum number of shapes the user can add to one drawing
#define MAX_SHAPES 50

// 4. Function declarations to manage our shapes list
void init_shape_manager();
int add_shape(Shape s);
int delete_shape(int index);
int modify_shape(int index, Shape new_shape);
void render_all_shapes(char grid[HEIGHT][WIDTH]);
void print_shape_list();
int get_shape_count();

#endif
#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "drawing.h"
#include "shape_manager.h"

// Helper function to read integers safely and prevent infinite loops
int get_safe_int(const char* prompt) {
    int val;
    char buffer[100];
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &val) == 1) {
                return val;
            }
        }
        printf("Invalid input! Please enter a valid integer.\n");
    }
}

// Function to handle adding a shape
void handle_add_shape() {
    printf("\nSelect Shape Type to Add:\n");
    printf("1. Line\n");
    printf("2. Rectangle\n");
    printf("3. Circle\n");
    printf("4. Triangle\n");
    int choice = get_safe_int("Enter choice (1-4): ");

    Shape s;
    switch (choice) {
        case 1:
            s.type = SHAPE_LINE;
            s.x1 = get_safe_int("Enter start point X1: ");
            s.y1 = get_safe_int("Enter start point Y1: ");
            s.x2 = get_safe_int("Enter end point X2: ");
            s.y2 = get_safe_int("Enter end point Y2: ");
            break;
        case 2:
            s.type = SHAPE_RECTANGLE;
            s.x1 = get_safe_int("Enter top-left corner X: ");
            s.y1 = get_safe_int("Enter top-left corner Y: ");
            s.x2 = get_safe_int("Enter width: ");
            s.y2 = get_safe_int("Enter height: ");
            break;
        case 3:
            s.type = SHAPE_CIRCLE;
            s.x1 = get_safe_int("Enter center X: ");
            s.y1 = get_safe_int("Enter center Y: ");
            s.r = get_safe_int("Enter radius: ");
            break;
        case 4:
            s.type = SHAPE_TRIANGLE;
            s.x1 = get_safe_int("Enter X1 for corner 1: ");
            s.y1 = get_safe_int("Enter Y1 for corner 1: ");
            s.x2 = get_safe_int("Enter X2 for corner 2: ");
            s.y2 = get_safe_int("Enter Y2 for corner 2: ");
            s.x3 = get_safe_int("Enter X3 for corner 3: ");
            s.y3 = get_safe_int("Enter Y3 for corner 3: ");
            break;
        default:
            printf("Invalid shape selection!\n");
            return;
    }

    if (add_shape(s)) {
        printf("Shape added successfully!\n");
    } else {
        printf("Error: Could not add shape (Drawing is full, max 50 shapes)!\n");
    }
}

// Function to handle deleting a shape
void handle_delete_shape() {
    printf("\nCurrent active shapes:\n");
    print_shape_list();
    if (get_shape_count() == 0) return;

    int idx = get_safe_int("Enter shape index number to delete: ");
    if (delete_shape(idx)) {
        printf("Shape deleted successfully!\n");
    } else {
        printf("Error: Invalid index!\n");
    }
}

// Function to handle modifying a shape
void handle_modify_shape() {
    printf("\nCurrent active shapes:\n");
    print_shape_list();
    if (get_shape_count() == 0) return;

    int idx = get_safe_int("Enter shape index to modify: ");
    if (idx < 0 || idx >= get_shape_count()) {
        printf("Error: Invalid index!\n");
        return;
    }

    printf("\nSelect New Shape Type for this index:\n");
    printf("1. Line\n");
    printf("2. Rectangle\n");
    printf("3. Circle\n");
    printf("4. Triangle\n");
    int choice = get_safe_int("Enter choice (1-4): ");

    Shape s;
    switch (choice) {
        case 1:
            s.type = SHAPE_LINE;
            s.x1 = get_safe_int("Enter new X1: ");
            s.y1 = get_safe_int("Enter new Y1: ");
            s.x2 = get_safe_int("Enter new X2: ");
            s.y2 = get_safe_int("Enter new Y2: ");
            break;
        case 2:
            s.type = SHAPE_RECTANGLE;
            s.x1 = get_safe_int("Enter new top-left X: ");
            s.y1 = get_safe_int("Enter new top-left Y: ");
            s.x2 = get_safe_int("Enter new width: ");
            s.y2 = get_safe_int("Enter new height: ");
            break;
        case 3:
            s.type = SHAPE_CIRCLE;
            s.x1 = get_safe_int("Enter new center X: ");
            s.y1 = get_safe_int("Enter new center Y: ");
            s.r = get_safe_int("Enter new radius: ");
            break;
        case 4:
            s.type = SHAPE_TRIANGLE;
            s.x1 = get_safe_int("Enter new X1 for corner 1: ");
            s.y1 = get_safe_int("Enter new Y1 for corner 1: ");
            s.x2 = get_safe_int("Enter new X2 for corner 2: ");
            s.y2 = get_safe_int("Enter new Y2 for corner 2: ");
            s.x3 = get_safe_int("Enter new X3 for corner 3: ");
            s.y3 = get_safe_int("Enter new Y3 for corner 3: ");
            break;
        default:
            printf("Invalid shape selection!\n");
            return;
    }

    if (modify_shape(idx, s)) {
        printf("Shape modified successfully!\n");
    } else {
        printf("Error: Could not modify shape!\n");
    }
}

int main() {
    char grid[HEIGHT][WIDTH];
    
    // Initialize empty list
    init_shape_manager();

    // Add 2 default shapes so the screen is not blank at first run
    Shape default_line = { SHAPE_LINE, .x1 = 2, .y1 = 2, .x2 = 15, .y2 = 8 };
    add_shape(default_line);
    
    Shape default_rect = { SHAPE_RECTANGLE, .x1 = 40, .y1 = 2, .x2 = 15, .y2 = 6 };
    add_shape(default_rect);

    while (1) {
        printf("\n====================================\n");
        printf("        2D GRAPHICS EDITOR          \n");
        printf("====================================\n");
        printf("1. Display Canvas\n");
        printf("2. Add Shape\n");
        printf("3. Delete Shape\n");
        printf("4. Modify Shape\n");
        printf("5. View Shape List\n");
        printf("6. Exit\n");
        printf("====================================\n");

        int choice = get_safe_int("Enter choice (1-6): ");
        switch (choice) {
            case 1:
                render_all_shapes(grid);
                printf("\n");
                print_grid(grid);
                break;
            case 2:
                handle_add_shape();
                break;
            case 3:
                handle_delete_shape();
                break;
            case 4:
                handle_modify_shape();
                break;
            case 5:
                printf("\n--- Active Shapes List ---\n");
                print_shape_list();
                break;
            case 6:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}
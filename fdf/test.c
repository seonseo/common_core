#include <stdio.h>
#include <math.h>

#define WIDTH 2
#define HEIGHT 2

typedef struct s_point
{
    int x;
    int y;
    int z;
}   t_point;

void transform_to_isometric(t_point *point)
{
    double theta = M_PI / 6; // 30 degrees in radians
    double phi = M_PI / 6; // 30 degrees in radians
    int original_x = point->x;
    int original_y = point->y;
    int original_z = point->z;
    
    // Calculate the new x and y using the isometric projection formulas
    point->x = (original_x - original_y) * cos(theta);
    point->y = (original_x + original_y) * sin(phi) - original_z;
    // Since we're projecting to 2D, z can be omitted or set to 0 if needed
    // point->z = 0;
}

void apply_isometric_projection(t_point points[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            transform_to_isometric(&points[i][j]);
        }
    }
}

int main()
{
    t_point points[HEIGHT][WIDTH] = {
        {{0, 0, 0}, {100, 0, 0}},
        {{0, 100, 0}, {0, 0, 100}}
    };
    
    apply_isometric_projection(points);
    
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("(%d, %d, %d) ", points[i][j].x, points[i][j].y, points[i][j].z);
        }
        printf("\n");
    }

    return 0;
}

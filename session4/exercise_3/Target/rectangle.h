typedef struct
{
    int width;
    int height;
} rectangle_t;

void set_dimensions(rectangle_t * rectangle, int width, int height);
int get_area(rectangle_t rectangle);
int get_perimeter(rectangle_t rectangle);
void print_rectangle_info(rectangle_t rectrangle);

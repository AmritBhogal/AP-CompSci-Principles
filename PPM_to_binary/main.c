#include <stdio.h>
#include <stdlib.h>

typedef struct {
    uint8_t x;
    uint8_t y;
} point_t;


int main()
{
    point_t size;

    FILE *image_file = fopen("img.bmp", "r");
    if (image_file == NULL) {
        fprintf(stderr, "Could not open file img.bmp!\n");
        return 1;
    }

    fseek(image_file, 0, SEEK_SET);

    {
        char *buffer = malloc(sizeof(char) * 8);
    }
}
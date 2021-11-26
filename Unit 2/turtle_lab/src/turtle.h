#ifndef _TURTLE_LAB_TURTLE_
#define _TURTLE_LAB_TURTLE_

#include <SDL2/SDL.h>
#include <stdint.h>

#define POINT(_x, _y) (point_t) { .x = _x, .y = _y }
typedef struct {
    int    x, y;
} point_t;

#define COLOUR(_r, _g, _b, _a) (colour_t) { .r = _r, .g = _g, .b = _b, .a = _a }

typedef struct {
    uint8_t r, g, b, a;
} colour_t;

extern const colour_t   COLOUR_BLACK, 
                        COLOUR_WHITE;

struct turtle {
    point_t         position;
    colour_t        draw_colour;
    uint16_t        rotation;
    SDL_Renderer    *renderer;
};

struct turtle *create_turtle(SDL_Window *window, SDL_Renderer *renderer);

void turtle_forward(struct turtle *turtle, int count);
void turtle_backwards(struct turtle *turtle, int count);
void turtle_left(struct turtle *turtle, int count);
void turtle_right(struct turtle *turtle, int count);

void turtle_rotate(struct turtle *turtle, int amount);

#endif
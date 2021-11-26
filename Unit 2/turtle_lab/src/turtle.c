#include "turtle.h"
#include "SDL2/SDL_render.h"
#include <stdlib.h>
#include <math.h>

const colour_t COLOUR_BLACK = { .r = 0,     .g = 0,     .b = 0,     .a = 255 };
const colour_t COLOUR_WHITE = { .r = 255,   .g = 255,   .b = 255,   .a = 255 };

struct turtle *create_turtle(SDL_Window *window, SDL_Renderer *renderer)
{
    point_t window_size;

    SDL_GetWindowSize(window, &window_size.x, &window_size.y);

    struct turtle *turtle = malloc(sizeof(struct turtle));
    turtle->position = (point_t) { 
        .x = window_size.x / 2,
        .y = window_size.y / 2
    };

    turtle->renderer = renderer;
    turtle->rotation = 0;

    turtle->draw_colour = COLOUR(0x0, 0x0, 0x0, 0xFF);

    return turtle;
}

void turtle_forward(struct turtle *turtle, int count)
{
    SDL_SetRenderDrawColor(turtle->renderer, turtle->draw_colour.r, turtle->draw_colour.g, turtle->draw_colour.b, 255);

    point_t newpos = {
        .x = (cos(turtle->rotation) * turtle->position.x) + count,
        .y = (sin(turtle->rotation) * turtle->position.y) + count
    };

    SDL_RenderDrawLine ( 
        turtle->renderer, 
        turtle->position.x, turtle->position.y, 
        newpos.x, 
        turtle->position.y + newpos.y  
    );

    turtle->position = newpos;

    SDL_SetRenderDrawColor(turtle->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderPresent(turtle->renderer);
    SDL_Delay(0);
}

void turtle_backwards(struct turtle *turtle, int count)
{
    SDL_SetRenderDrawColor(turtle->renderer, turtle->draw_colour.r, turtle->draw_colour.g, turtle->draw_colour.b, 255);
    SDL_RenderDrawLine(turtle->renderer, turtle->position.x, turtle->position.y, turtle->position.x, turtle->position.y + count);
    // SDL_RenderPresent(turtle->renderer);

    turtle->position.y += count;

    // turtle->distance_traveled += count;
}

void turtle_left(struct turtle *turtle, int count)
{
    SDL_SetRenderDrawColor(turtle->renderer, turtle->draw_colour.r, turtle->draw_colour.g, turtle->draw_colour.b, 255);
    SDL_RenderDrawLine(turtle->renderer, turtle->position.x, turtle->position.y, turtle->position.x - count, turtle->position.y);
    // SDL_RenderPresent(turtle->renderer);

    turtle->position.x -= count;

    // turtle->distance_traveled += count;
}

void turtle_right(struct turtle *turtle, int count)
{
    SDL_SetRenderDrawColor(turtle->renderer, turtle->draw_colour.r, turtle->draw_colour.g, turtle->draw_colour.b, 255);
    SDL_RenderDrawLine(turtle->renderer, turtle->position.x, turtle->position.y, turtle->position.x + count, turtle->position.y);
    // SDL_RenderPresent(turtle->renderer);

    turtle->position.x += count;

    // turtle->distance_traveled += count;
}

void turtle_rotate(struct turtle *turtle, int amount)
{
    //im a 10xer
    // turtle->rotation = ((turtle->rotation + amount > 360) ? turtle->rotation - 360 : (turtle->rotation + amount < 0) ? turtle->rotation + 360 : turtle->rotation);

    turtle->rotation += amount;
    if (turtle->rotation > 360) {
        turtle->rotation -= 360;
    } else if (turtle->rotation < 0) {
        turtle->rotation += 360;
    }
}

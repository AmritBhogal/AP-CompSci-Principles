#include "turtle.h"
#include "SDL2/SDL_render.h"

const colour_t COLOUR_BLACK = { .r = 0,     .g = 0,     .b = 0,     .a = 255 };
const colour_t COLOUR_WHITE = { .r = 255,   .g = 255,   .b = 255,   .a = 255 };

struct turtle create_turtle(SDL_Window *window, SDL_Renderer *renderer)
{
    point_t window_size;
    SDL_GetWindowSize(window, &window_size.x, &window_size.y);

    struct turtle turtle;
    turtle.position = (point_t) { 
        .x = window_size.x / 2,
        .y = window_size.y / 2
    };
    // turtle.distance_traveled = 0;
    turtle.renderer = renderer;
    // turtle.rotation = 0;

    turtle.draw_colour = COLOUR(0, 0, 0, 255);

    return turtle;
}

void turtle_forward(struct turtle *turtle, int count)
{
    SDL_SetRenderDrawColor(turtle->renderer, turtle->draw_colour.r, turtle->draw_colour.g, turtle->draw_colour.b, 255);
    SDL_RenderDrawLine(turtle->renderer, turtle->position.x, turtle->position.y, turtle->position.x, turtle->position.y - count);
    // SDL_RenderPresent(turtle->renderer);

    turtle->position.y -= count;

    // turtle->distance_traveled += count;
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

#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "SDL2/SDL_render.h"
#include "common.h"
#include "turtle.h"

SDL_Window      *window;
SDL_Renderer    *renderer;

ATTRIBUTE(constructor)
void init(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Turtle Lab", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

int main(int argc, char *argv[])
{
    

    struct turtle turtle = create_turtle(window, renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    bool exit;
    while (!exit) {
        ON_EVENT(SDL_QUIT) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Goodbye!", "Cya later!", window);
            exit = true;
            break;
        }
        
        /* A */
        turtle_forward(&turtle, 64);
        turtle_right(&turtle, 32);
        turtle_backwards(&turtle, 64);

        turtle_forward(&turtle, 48);
        turtle_left(&turtle, 32);
        turtle_right(&turtle, 32);

        turtle_backwards(&turtle, 48);

        /* SEPERATOR */ 
        turtle.draw_colour = COLOUR_WHITE;
        turtle_right(&turtle, 32);
        turtle.draw_colour = COLOUR_BLACK;

        /* B */
        
        turtle_forward(&turtle, 64);

        turtle_right(&turtle, 32);
        turtle_backwards(&turtle, 32);
        turtle_left(&turtle, 32);

        turtle_backwards(&turtle, 8);

        turtle_right(&turtle, 32);
        turtle_backwards(&turtle, 24);
        turtle_left(&turtle, 32);

        SDL_RenderPresent(renderer);
        printf("Done!\n");
    }
}

ATTRIBUTE(destructor)
void destructor(void)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

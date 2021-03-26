#include <iostream>
#include "SDL2/SDL.h"
#include "logic/Snake.h"
#include "screen/EventHandler.h"
#include "logic/FoodSpawner.h"
#include "screen/FoodRenderer.h"

using namespace std;


void MainLoop(SDL_Renderer &sdlRenderer) {
    SDL_SetEventFilter(EventHandler::EventFilter, nullptr);

    Boundaries windowBoundaries = {0, GRID_HEIGHT-1 , GRID_WIDTH-1, 0};

    auto *foodSpawner = new FoodSpawner(windowBoundaries);
    auto *snake = new Snake(windowBoundaries, foodSpawner);
    auto *snakeRenderer = new SnakeRenderer(&sdlRenderer, snake);
    auto *foodRenderer = new FoodRenderer(foodSpawner, &sdlRenderer);
    foodSpawner->SpawnFood();
    snake->StartMoving();
    while (true) {
        SDL_Event sdlEvent;
        if(SDL_PollEvent(&sdlEvent) > 0){
            if(sdlEvent.type == SDL_QUIT){
                break;
            }
            else{
                EventHandler::HandleEvent(&sdlEvent, snake);
            }
        }
        SDL_SetRenderDrawColor(&sdlRenderer, WHITE);
        SDL_RenderClear(&sdlRenderer);
        snakeRenderer->RenderSnake();
        foodRenderer->RenderFood();

        SDL_RenderPresent(&sdlRenderer);
        sched_yield();
    }

    snake->StopUpdating();

    delete snakeRenderer;
    delete snake;
    delete foodRenderer;
    delete foodSpawner;
}

void InitializeSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Couldn't init sdl, exiting..." << endl;
        exit(1);
    }
}

int main() {
    InitializeSDL();

    SDL_Window *sdlWindow = SDL_CreateWindow("SDL_Snake", 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);

    MainLoop(*renderer);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();
    return 0;
}

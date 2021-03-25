#include <iostream>
#include "SDL2/SDL.h"
#include "logic/Snake.h"

#define RED 0xFF,0x00,0x00, 0xFF
#define WHITE 0xFF,0xFF,0xFF,0xFF
#define SCREEN_HEIGHT 700
#define SCREEN_WIDTH 700

#define RECT_SIZE 30

using namespace std;

int EventFilter(void * userData, SDL_Event * sdlEvent){
    if(sdlEvent->type == SDL_QUIT || sdlEvent->type == SDL_KEYDOWN){
        return 1;
    }
    return 0;
}


void MovementHandler(SDL_Event *sdlEvent, Snake * snake){
    const char *keyName = SDL_GetKeyName(sdlEvent->key.keysym.sym);
    Direction direction;
    if (strcmp(keyName, "W") == 0) {
        direction = Direction::UP;
    } else if (strcmp(keyName, "S") == 0) {
        direction = Direction::DOWN;
    } else if (strcmp(keyName, "D") == 0) {
        direction = Direction::RIGHT;
    } else if (strcmp(keyName, "A") == 0) {
        direction = Direction::LEFT;
    } else {
        return;
    }
    snake->ChangeDirection(direction);
}

void Iteration(SDL_Renderer &renderer, Snake &snake) {
    SDL_SetRenderDrawColor(&renderer, WHITE);
    SDL_RenderClear(&renderer);

    SDL_SetRenderDrawColor(&renderer, RED);

    const BodyLink *currLink = snake.getHeadLink();
    const BodyLink *tailLink = snake.getTailLink();

    do {
        SDL_Rect sdlRect = SDL_Rect(
                {RECT_SIZE * tailLink->getLinkLocation().x, RECT_SIZE * tailLink->getLinkLocation().y, RECT_SIZE,
                 RECT_SIZE});
        SDL_RenderFillRect(&renderer, &sdlRect);
        tailLink = tailLink->getNextLink();
    } while (tailLink != nullptr);

    SDL_RenderPresent(&renderer);
}

void MainLoop(SDL_Renderer &renderer) {
    SDL_SetEventFilter(EventFilter, nullptr);
    auto *snake = new Snake(SCREEN_WIDTH / RECT_SIZE, SCREEN_HEIGHT / RECT_SIZE);
    snake->StartMoving();
    while (true) {
        SDL_Event sdlEvent;
        if(SDL_PollEvent(&sdlEvent) > 0){
            if(sdlEvent.type == SDL_KEYDOWN){
                MovementHandler(&sdlEvent, snake);
            }
            else if(sdlEvent.type == SDL_QUIT){
                break;
            }
        }

        Iteration(renderer, *snake);
        sched_yield();
    }
    delete snake;
}

void InitializeSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Couldn't init sdl, exiting..." << endl;
        exit(1);
    }
}

int main() {
    InitializeSDL();

    SDL_Window *sdlWindow = SDL_CreateWindow("Testing", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);


    MainLoop(*renderer);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();
    return 0;
}

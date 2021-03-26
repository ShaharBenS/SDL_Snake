//
// Created by Shahar on 3/26/2021.
//

#ifndef SDL_SNAKE_FOODRENDERER_H
#define SDL_SNAKE_FOODRENDERER_H

#include "SDL2/SDL.h"
#include "../logic/FoodSpawner.h"

class FoodRenderer {
private:
    FoodSpawner * foodSpawner;
    SDL_Renderer * renderer;
public:
    FoodRenderer(FoodSpawner *foodSpawner, SDL_Renderer *renderer);
    void RenderFood();
};


#endif //SDL_SNAKE_FOODRENDERER_H

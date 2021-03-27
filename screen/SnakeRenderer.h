//
// Created by shahar on 25/03/2021.
//

#ifndef TRYINGOUTSDL_RENDERER_H
#define TRYINGOUTSDL_RENDERER_H

#include "SDL.h"
#include "../logic/Snake.h"

class SnakeRenderer {
private:
    Snake * theSnake;
    SDL_Renderer * renderer;

public:
    SnakeRenderer(SDL_Renderer * renderer, Snake * snake);
    void RenderSnake();
};


#endif //TRYINGOUTSDL_RENDERER_H

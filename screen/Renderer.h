//
// Created by shahar on 25/03/2021.
//

#ifndef TRYINGOUTSDL_RENDERER_H
#define TRYINGOUTSDL_RENDERER_H

#include "SDL2/SDL.h"

class Renderer {
private:
    SDL_Renderer * renderer;
    void RenderFrame();
    void MainLoop();

public:
    Renderer(SDL_Renderer * renderer);
    void StartRendering();
};


#endif //TRYINGOUTSDL_RENDERER_H

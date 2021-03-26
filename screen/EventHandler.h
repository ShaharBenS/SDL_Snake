//
// Created by shahar on 25/03/2021.
//

#ifndef TRYINGOUTSDL_EVENTHANDLER_H
#define TRYINGOUTSDL_EVENTHANDLER_H


#include "SnakeRenderer.h"

class EventHandler {
public:
    static int EventFilter(void * userData,  SDL_Event *sdlEvent);
    static void HandleEvent(SDL_Event * sdlEvent, Snake * snake);
};


#endif //TRYINGOUTSDL_EVENTHANDLER_H

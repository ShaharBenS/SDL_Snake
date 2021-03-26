//
// Created by shahar on 25/03/2021.
//

#include "EventHandler.h"

int EventHandler::EventFilter(void *userData, SDL_Event *sdlEvent) {
    if(sdlEvent->type == SDL_QUIT || sdlEvent->type == SDL_KEYDOWN){
        return 1;
    }
    return 0;
}

void EventHandler::HandleEvent(SDL_Event *sdlEvent, Snake *snake) {
    if(sdlEvent->type == SDL_KEYDOWN){
        const char *keyName = SDL_GetKeyName(sdlEvent->key.keysym.sym);
        Direction direction;
        if (strcmp(keyName, "W") == 0 || strcmp(keyName, "Up") == 0) {
            direction = Direction::UP;
        } else if (strcmp(keyName, "S") == 0 || strcmp(keyName, "Down") == 0) {
            direction = Direction::DOWN;
        } else if (strcmp(keyName, "D") == 0 || strcmp(keyName, "Right") == 0) {
            direction = Direction::RIGHT;
        } else if (strcmp(keyName, "A") == 0 || strcmp(keyName, "Left") == 0) {
            direction = Direction::LEFT;
        } else {
            return;
        }
        snake->ChangeDirection(direction);
    }
}

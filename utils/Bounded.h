//
// Created by Shahar on 3/26/2021.
//

#ifndef SDL_SNAKE_BOUNDED_H
#define SDL_SNAKE_BOUNDED_H

#include "Consts.h"

/**
 * A bounded class has its boundaries and needs to consider it
 */
class Bounded {
protected:
    const Boundaries boundaries;
public:
    Bounded(Boundaries boundaries): boundaries(boundaries){};
};


#endif //SDL_SNAKE_BOUNDED_H

//
// Created by shahar on 23/03/2021.
//

#ifndef TRYINGOUTSDL_SNAKE_H
#define TRYINGOUTSDL_SNAKE_H

#include "SDL2/SDL.h"
#include "AutoUpdated.h"
#include "../utils/Utils.h"
#include "../utils/Consts.h"
#include "../utils/Link.h"
#include "../utils/Bounded.h"
#include "FoodSpawner.h"

class Snake : public AutoUpdated, public Bounded {
private:
    int Length;
    bool DirectionChanged; // This flag ensures that the snake direction can be changed only once per update
    Link<Location> *HeadLink;
    Link<Location> *TailLink;
    Direction CurrentDirection;
    FoodSpawner * foodSpawner;

public:
    Snake(Boundaries boundaries, FoodSpawner * foodSpawner);
    ~Snake();
    void StartMoving();
    void ChangeDirection(Direction direction);

    const Link<Location>* getHeadLink() const;
    const Link<Location>* getTailLink() const;

    void Update() override;
};


#endif //TRYINGOUTSDL_SNAKE_H

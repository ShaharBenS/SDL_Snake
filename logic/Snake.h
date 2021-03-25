//
// Created by shahar on 23/03/2021.
//

#ifndef TRYINGOUTSDL_SNAKE_H
#define TRYINGOUTSDL_SNAKE_H

#include "SDL2/SDL.h"
#include "AutoUpdated.h"
#include "../utils/Utils.h"
#include "BodyLink.h"

#define UPDATE_INTERVAL_MILLISECONDS 100

class Snake : public AutoUpdated {
private:
    Size GridSize{};
    int Length;
    BodyLink *HeadLink;
    BodyLink *TailLink;
    Direction CurrentDirection;


public:
    Snake(int gridVerticalSize, int gridHorizontalSize);
    ~Snake();
    void StartMoving();
    void ChangeDirection(Direction direction);
    struct Size GetGridSize();

    const BodyLink* getHeadLink() const;

    const BodyLink* getTailLink() const;

    void Update() override;

};


#endif //TRYINGOUTSDL_SNAKE_H

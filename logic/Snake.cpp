//
// Created by shahar on 23/03/2021.
//

#include "Snake.h"

Snake::Snake(int gridVerticalSize, int gridHorizontalSize) : AutoUpdated(UPDATE_INTERVAL_MILLISECONDS) {
    this->Length = 1;
    this->GridSize = {gridVerticalSize, gridHorizontalSize};
    this->CurrentDirection = Direction::DOWN;

    this->HeadLink = new BodyLink(Location({gridVerticalSize / 2, gridHorizontalSize / 2}));
    this->TailLink = new BodyLink({gridVerticalSize / 2, gridHorizontalSize / 2 + 1});
    this->TailLink->setNextLink(this->HeadLink);
}

Snake::~Snake() {
    this->StopUpdating();
    auto * current = this->TailLink;
    do{
        auto * toDelete = current;
        current = current->getNextLink();
        delete toDelete;
    }
    while(current != nullptr);
}

void Snake::ChangeDirection(Direction direction) {
    this->CurrentDirection = direction;
}

Size Snake::GetGridSize() {
    return this->GridSize;
}

void Snake::Update() {
    Location prevHeadLocation = this->getHeadLink()->getLinkLocation();

    // Updating Body links
    BodyLink * nextTail = this->TailLink->getNextLink();
    this->TailLink->setNextLink(nullptr);
    this->HeadLink->setNextLink(this->TailLink);
    this->HeadLink = this->TailLink;
    this->TailLink = nextTail;

    // Updating new head Location
    Location newLocation = prevHeadLocation;
    switch(this->CurrentDirection){
        case UP:
            newLocation.y--;
            break;
        case DOWN:
            newLocation.y++;
            break;
        case RIGHT:
            newLocation.x++;
            break;
        case LEFT:
            newLocation.x--;
            break;
    }
    this->HeadLink->setLinkLocation(newLocation);
}

const BodyLink* Snake::getHeadLink() const {
    return HeadLink;
}

const BodyLink* Snake::getTailLink() const {
    return TailLink;
}

void Snake::StartMoving(){
    this->StartUpdating();
}

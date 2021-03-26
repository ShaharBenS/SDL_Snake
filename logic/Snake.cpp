//
// Created by shahar on 23/03/2021.
//

#include "Snake.h"

Snake::Snake(Boundaries boundaries, FoodSpawner *foodSpawner) : AutoUpdated(SNAKE_UPDATE_INTERVAL_MILLISECONDS),
                                                                Bounded(boundaries), foodSpawner(foodSpawner) {
    this->CurrentDirection = Direction::DOWN;

    Location startingLocation = Location(
            {(boundaries.right - boundaries.left) / 2, (boundaries.bottom - boundaries.top) / 4});
    this->HeadLink = new Link<Location>(startingLocation);
    startingLocation.y--;
    this->TailLink = new Link<Location>(startingLocation);
    this->TailLink->setNextLink(this->HeadLink);
    this->DirectionChanged = false;
}

Snake::~Snake() {
    auto *current = this->TailLink;
    do {
        auto *toDelete = current;
        current = current->getNextLink();
        delete toDelete;
    } while (current != nullptr);
}

void Snake::ChangeDirection(Direction direction) {
    if (this->CurrentDirection + direction != 0 && !DirectionChanged) {
        this->CurrentDirection = direction;
        DirectionChanged = true;
    }
}

void Snake::Update() {
    DirectionChanged = false;
    Location prevHeadLocation = this->getHeadLink()->getData();

    // Updating Body links
    Link<Location> *nextTail;

    // Copying current tail if head is on food
    if(this->HeadLink->getData() == foodSpawner->getCurrentFood()->FoodLocation) {
        nextTail = new Link<Location>(*this->TailLink);
        this->foodSpawner->SpawnFood();
    }
    else{
        nextTail = this->TailLink->getNextLink();
    }

    this->TailLink->setNextLink(nullptr);
    this->HeadLink->setNextLink(this->TailLink);
    this->HeadLink = this->TailLink;
    this->TailLink = nextTail;

    // Updating new head Location
    Location newLocation = prevHeadLocation;
    switch (this->CurrentDirection) {
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
    this->HeadLink->setData(newLocation);

}

const Link<Location> *Snake::getHeadLink() const {
    return HeadLink;
}

const Link<Location> *Snake::getTailLink() const {
    return TailLink;
}

void Snake::StartMoving() {
    this->StartUpdating();
}

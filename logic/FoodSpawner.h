//
// Created by Shahar on 3/26/2021.
//

#ifndef SDL_SNAKE_FOODSPAWNER_H
#define SDL_SNAKE_FOODSPAWNER_H

#include "AutoUpdated.h"
#include "../utils/Consts.h"
#include "../utils/Bounded.h"
#include "../utils/Utils.h"
#include <memory>

using namespace std;

class Food{
public:
    Location FoodLocation;
    Food(Location foodLocation): FoodLocation(foodLocation){}
};

class FoodSpawner: public Bounded{
private:
    unique_ptr<Food> currentFood;
public:
    FoodSpawner(Boundaries boundaries);
    void SpawnFood();

    const Food* getCurrentFood() const;
};


#endif //SDL_SNAKE_FOODSPAWNER_H

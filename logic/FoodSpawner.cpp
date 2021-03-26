//
// Created by Shahar on 3/26/2021.
//

#include "FoodSpawner.h"

FoodSpawner::FoodSpawner(Boundaries boundaries) : Bounded(boundaries) {}

void FoodSpawner::SpawnFood() {
    this->currentFood = std::make_unique<Food>(Location(
            {
                    random_int(boundaries.left, boundaries.right),
                    random_int(boundaries.top, boundaries.bottom)
            }
    ));
}

const Food* FoodSpawner::getCurrentFood() const {
    return currentFood.get();
}

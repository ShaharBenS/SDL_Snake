//
// Created by Shahar on 3/26/2021.
//

#include "FoodRenderer.h"

FoodRenderer::FoodRenderer(FoodSpawner *foodSpawner, SDL_Renderer *renderer) : foodSpawner(foodSpawner),
                                                                               renderer(renderer) {}

void FoodRenderer::RenderFood() {
    SDL_SetRenderDrawColor(renderer, ROSE_EBONY);
    Location foodLocation = foodSpawner->getCurrentFood()->FoodLocation;
    SDL_Rect foodRect = {foodLocation.x * GRID_CELL_SIZE + FOOD_PADDING, foodLocation.y * GRID_CELL_SIZE + FOOD_PADDING,
                         GRID_CELL_SIZE - FOOD_PADDING * 2, GRID_CELL_SIZE - FOOD_PADDING * 2};
    SDL_RenderFillRect(renderer, &foodRect);
}

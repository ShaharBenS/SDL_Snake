//
// Created by shahar on 25/03/2021.
//

#include "SnakeRenderer.h"

SnakeRenderer::SnakeRenderer(SDL_Renderer *renderer, Snake *snake) : renderer(renderer), theSnake(snake) {}

void SnakeRenderer::RenderSnake() {
    SDL_SetRenderDrawColor(this->renderer, RED);

    // const Link<Location> *currLink = this->theSnake->getHeadLink();
    const Link<Location> *tailLink = this->theSnake->getTailLink();

    do {
        SDL_Rect sdlRect = SDL_Rect(
                {(GRID_CELL_SIZE * tailLink->getData().x) + SNAKE_RECT_PADDING,
                 (GRID_CELL_SIZE * tailLink->getData().y) + SNAKE_RECT_PADDING, GRID_CELL_SIZE - SNAKE_RECT_PADDING * 2,
                 GRID_CELL_SIZE - SNAKE_RECT_PADDING * 2});
        SDL_RenderFillRect(this->renderer, &sdlRect);
        tailLink = tailLink->getNextLink();
    } while (tailLink != nullptr);
}

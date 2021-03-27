//
// Created by Shahar on 3/26/2021.
//

#ifndef SDL_SNAKE_CONSTS_H
#define SDL_SNAKE_CONSTS_H


/* Structs */
struct Location{
    int x;
    int y;
};


inline bool operator==(const Location &loc1, const Location &loc2){
    return loc1.x == loc2.x && loc1.y == loc2.y;
}

struct Boundaries{
    int top;
    int bottom;
    int right;
    int left;
};


/* Enums */
enum Direction{
    UP = 1,
    DOWN = -1,
    RIGHT = 2,
    LEFT = -2
};


/* Colors */
#define RED 0xFF,0x00,0x00,0xFF
#define WHITE 0xFF,0xFF,0xFF,0xFF
#define ROSE_EBONY 0x5F,0x46,0x4B,0xFF

/* Screen */
#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 900
#define GRID_CELL_SIZE 30
#define GRID_WIDTH (SCREEN_WIDTH / GRID_CELL_SIZE)
#define GRID_HEIGHT (SCREEN_HEIGHT / GRID_CELL_SIZE)

/* Snake */
#define SNAKE_UPDATE_INTERVAL_MILLISECONDS 1000
#define SNAKE_RECT_PADDING 1

/* Food */
#define FOOD_PADDING 10

#endif //SDL_SNAKE_CONSTS_H




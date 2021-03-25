//
// Created by shahar on 23/03/2021.
//

#ifndef TRYINGOUTSDL_STRUCTS_H
#define TRYINGOUTSDL_STRUCTS_H

#include <chrono>
#include <thread>

void m_sleep(unsigned int m_seconds);

/* Structs */
struct Location{
    int x;
    int y;
};

struct Size{
    int w;
    int h;
};

enum Direction{
    UP,
    DOWN,
    RIGHT,
    LEFT
};

#endif //TRYINGOUTSDL_STRUCTS_H

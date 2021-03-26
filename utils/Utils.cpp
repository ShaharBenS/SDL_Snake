//
// Created by Shahar on 3/26/2021.
//

#include "Utils.h"

void m_sleep(unsigned int m_seconds){
    std::this_thread::sleep_for(std::chrono::milliseconds(m_seconds));
}

/**
 * Generates a random int: [a,b]
 * @param a start int
 * @param b end int
 * @return random int
 */
int random_int(int a, int b){
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(a, b);
    return dist(mt);
}
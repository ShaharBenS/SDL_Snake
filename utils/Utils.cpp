//
// Created by Shahar on 3/26/2021.
//

#include "Utils.h"

void m_sleep(unsigned int m_seconds){
    std::this_thread::sleep_for(std::chrono::milliseconds(m_seconds));
}
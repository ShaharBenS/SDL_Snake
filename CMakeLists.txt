cmake_minimum_required(VERSION 3.17)

set(PROJECT_NAME SDL_Snake)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)


message("-- Finding Packages")
find_library(SDL2_LIBRARY NAME SDL2)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


message("-- Adding Executable")
add_executable(${PROJECT_NAME} main.cpp logic/AutoUpdated.cpp logic/Snake.cpp screen/EventHandler.cpp screen/SnakeRenderer.cpp utils/Utils.cpp utils/Consts.h utils/Link.h logic/FoodSpawner.cpp logic/FoodSpawner.h utils/Bounded.cpp utils/Bounded.h screen/FoodRenderer.cpp screen/FoodRenderer.h)


message(-- Linking)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads PUBLIC ${SDL2_LIBRARY})
add_definitions(-DSDL_MAIN_HANDLED)
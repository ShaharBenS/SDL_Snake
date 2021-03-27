cmake_minimum_required(VERSION 3.17)

set(PROJECT_NAME SDL_Snake)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)
set(SDL2_PATH "C:\\sdl2\\x86_64-w64-mingw32")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories( ${SDL2_INCLUDE_DIR})


add_executable(${PROJECT_NAME} main.cpp logic/AutoUpdated.cpp logic/Snake.cpp screen/EventHandler.cpp screen/SnakeRenderer.cpp utils/Utils.cpp utils/Consts.h utils/Link.h logic/FoodSpawner.cpp logic/FoodSpawner.h utils/Bounded.cpp utils/Bounded.h screen/FoodRenderer.cpp screen/FoodRenderer.h)


target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARY})
add_definitions(-DSDL_MAIN_HANDLED)
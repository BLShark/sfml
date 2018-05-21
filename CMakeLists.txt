cmake_minimum_required(VERSION 2.8)
project(sfmlTest)

#file(GLOB_RECURSE SOURCES "*.cpp" "*.h" "*.hpp")
set(CMAKE_BUILD_TYPE Debug)



add_executable(${PROJECT_NAME} main.cpp game.h game.cpp)

target_link_libraries(${PROJECT_NAME}
    -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio)

cmake_minimum_required(VERSION 2.8)
project(snakeGame)

#file(GLOB_RECURSE SOURCES "*.cpp" "*.h" "*.hpp")
set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} snakeGame.cpp snake.h snake.cpp panel.cpp
    panel.h exceptions.h mainMenu.h mainMenu.cpp objects.h centertext.h button.h statemachine.h apple.h apple.cpp )

target_link_libraries(${PROJECT_NAME}
    -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio)

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void clearMovements();

private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;

    bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;

    static constexpr float PlayerSpeed = 5000.f;
};

#endif // GAME_H

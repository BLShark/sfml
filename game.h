#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "fps.h"

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

    void CollisionDetect();

    Fps mfps;

private:
    sf::RenderWindow mWindow;
//    sf::CircleShape mPlayer;

    sf::Texture mTexture;
    sf::Sprite mPlayer;
    sf::Font mFont;
    sf::Text mText;

    sf::RectangleShape mWall;

    bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;

    static constexpr float PlayerSpeed = 50.f;
};

#endif // GAME_H

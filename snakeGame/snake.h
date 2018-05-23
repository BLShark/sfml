#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <functional>

#include "objects.h"
#include "apple.h"

class Snake : public Objects
{
private:

    static constexpr float PlayerSpeed = 0.15f;

    std::function<void()> mUpdateScore;

    Apple apple;


    sf::Texture headTexture;
    sf::Sprite snakeHead;

    bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;

public:
    Snake(const std::function<void()>&& UpdateScore, const sf::RenderWindow &window);
    virtual ~Snake(){
    }

    void Draw(sf::RenderWindow &window) override;
    void processEvent(sf::Event events) override;

    bool Init(std::shared_ptr<StateMachine> ptr) override;

    void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed = true);

    void Update();

    void ColisionDetect();

    void run(){

    }
};

#endif // SNAKE_H

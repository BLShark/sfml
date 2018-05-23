#include "snake.h"

#include "exceptions.h"

Snake::Snake(const std::function<void()> &&UpdateScore,
             const sf::RenderWindow &window)
    : Objects(eStates::eMainGame),
      apple({static_cast<float>(window.getSize().x),
             static_cast<float>(window.getSize().y)})
{
    mWindow = &window;
    mUpdateScore = UpdateScore;
}

void Snake::Draw(sf::RenderWindow &window)
{
    Update();
    apple.Draw(window);
    window.draw(snakeHead);
}

void Snake::processEvent(sf::Event events)
{
    // apple.InitNewApple();
    switch (events.type)
    {
    case sf::Event::KeyPressed:
        HandlePlayerInput(events.key.code, true);
        break;
    case sf::Event::KeyReleased:
        // handlePlayerInput(events.key.code);
        break;
    }
}

bool Snake::Init(std::shared_ptr<StateMachine> ptr)
{
    mState = ptr;
    apple.Init();

    if (!headTexture.loadFromFile("../font/snake-head.png"))
    {
        throw std::runtime_error(excep::CannotLoadSnakeHead);
    }
    snakeHead.setTexture(headTexture);
    snakeHead.setPosition(mWindow->getSize().x / 2, mWindow->getSize().y / 2);

    return true;
}

void Snake::HandlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}

void Snake::Update()
{
    static sf::Vector2f velocity;
    //    if (mIsMovingUp)
    //        movement.y -= PlayerSpeed;
    //    if (mIsMovingDown)
    //        movement.y += PlayerSpeed;
    //    if (mIsMovingLeft)
    //        movement.x -= PlayerSpeed;
    //    if (mIsMovingRight)
    //        movement.x += PlayerSpeed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        velocity.y = -PlayerSpeed;
        velocity.x = 0;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        velocity.y = PlayerSpeed;
        velocity.x = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity.x = -PlayerSpeed;
        velocity.y = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        velocity.x = PlayerSpeed;
        velocity.y = 0;
    }

    snakeHead.move(velocity);
    ColisionDetect();
}

void Snake::ColisionDetect()
{
    if (apple.GetPosition().intersects(snakeHead.getGlobalBounds()))
    {
        apple.InitNewApple();
        mUpdateScore();
    }
}

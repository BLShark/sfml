#include "game.h"
#include <chrono>
#include <thread>

Game::Game() : mWindow(sf::VideoMode(800, 600), "SFML Application"),
    mTexture(),
    mPlayer(),
    mFont(),
    mText(),
    mWall(),
    mIsMovingUp(false),
    mIsMovingDown(false),
    mIsMovingLeft(false),
    mIsMovingRight(false)
{

    if(!mTexture.loadFromFile("../30579c4ec5bb980.jpg"))
    {
        //EROR
        std::cout<<"Cannot load picture"<<std::endl;
    }

    if (!mFont.loadFromFile("../font/Stoehr Numbers.ttf"))
    {
        std::cout<<"Cannot load font"<<std::endl;
    }

    mText.setFont(mFont);
    mText.setPosition(600.f, 50.f);
    mText.setFillColor(sf::Color::Black);
    mText.setStyle(sf::Text::Bold);
    mText.setCharacterSize(20);


    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(0.f, 0.f);
    //mPlayer.setOrigin(mPlayer.getGlobalBounds().width/2, mPlayer.getGlobalBounds().height/2);

//    mPlayer.setRadius(40.f);
//    mPlayer.setPosition(100.f, 100.f);
//    mPlayer.setFillColor(sf::Color::Cyan);
//    mPlayer.setOrigin(40.f,40.0f);

    mWall.setSize({10,480});
    mWall.setPosition({400,0});
    mWall.setFillColor(sf::Color::White);
}
void Game::run()
{
    sf::Clock clock;
    auto TimePerFrame = sf::seconds(1.f / 60.f);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;


    while (mWindow.isOpen())
    {
        mfps.update();
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {

            timeSinceLastUpdate -= TimePerFrame;
            processEvents();

            update(TimePerFrame);
        }


        mText.setString(std::to_string(mfps.get()));
        render();

    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp)
        movement.y -= PlayerSpeed;
    if (mIsMovingDown)
        movement.y += PlayerSpeed;
    if (mIsMovingLeft)
        movement.x -= PlayerSpeed;
    if (mIsMovingRight)
        movement.x += PlayerSpeed;

    //std::cout << "delta time " << deltaTime.asSeconds() << std::endl;
    mPlayer.move(movement * deltaTime.asSeconds());

    CollisionDetect();
}

void Game::render()
{
    mWindow.clear(sf::Color::Yellow);
    mWindow.draw(mPlayer);
    mWindow.draw(mWall);
    mWindow.draw(mText);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
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

void Game::CollisionDetect()
{
//    auto position = mPlayer.getPosition().x + mPlayer.getRadius();
//    if (position > mWall.getPosition().x &&
//            position < mWall.getPosition().x + mWall.getSize().x)
//        mPlayer.setPosition(mWall.getPosition().x - mPlayer.getRadius(), mPlayer.getPosition().y);


}

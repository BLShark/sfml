#include "apple.h"

#include <random>
#include "exceptions.h"

Apple::Apple(sf::Vector2f cordinates) : mTableCordinates(cordinates)
{

}

bool Apple::Init()
{
    if (!appleTexture.loadFromFile("../font/apple.png"))
    {
        throw std::runtime_error(excep::CannotLoadApple);
    }
    mApple.setTexture(appleTexture);
}

void Apple::InitNewApple()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> xCord(0 + mApple.getGlobalBounds().width, mTableCordinates.x - mApple.getGlobalBounds().width);
    std::uniform_int_distribution<> yCord(0 + mApple.getGlobalBounds().height , mTableCordinates.y - mApple.getGlobalBounds().height );
    mApple.setPosition(xCord(gen),yCord(gen));
}

sf::FloatRect Apple::GetPosition()
{
    return mApple.getGlobalBounds();
}

void Apple::Draw(sf::RenderWindow &window)
{
    window.draw(mApple);
}

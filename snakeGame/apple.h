#ifndef APPLE_H
#define APPLE_H

#include <SFML/Graphics.hpp>

class Apple
{
private:

    sf::Texture appleTexture;
    sf::Sprite mApple;

    sf::Vector2f mTableCordinates;

public:
    Apple(sf::Vector2f cordinates);
    ~Apple(){}

    bool Init();

    void InitNewApple();
    void RemoveApple(){};

    sf::FloatRect GetPosition();

    void Draw(sf::RenderWindow& window);

};

#endif // APPLE_H

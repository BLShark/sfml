#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include "objects.h"
#include "button.h"

class MainMenu : public Objects
{
    sf::Font font;
    sf::Texture background;
    sf::Texture buttonTexture;
    sf::Texture logoTexture;
    sf::Sprite mainMenu;
    sf::Sprite logo;
    Button mButton;


public:
    MainMenu(sf::RenderWindow& window);
    virtual ~MainMenu(){}

    void Draw(sf::RenderWindow& window) override;
    void processEvent(sf::Event event) override;
    bool Init(std::shared_ptr<StateMachine> ptr) override;
};

#endif // MAINMENU_H

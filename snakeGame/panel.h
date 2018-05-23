#ifndef PANEL_H
#define PANEL_H

#include <SFML/Graphics.hpp>
#include <functional>

#include "objects.h"
#include "button.h"

class Panel : public Objects
{
private:
    sf::RectangleShape mPanel;

    /** default score font*/
    sf::Font mFont;
    /** draw score object */
    sf::Text mScore;
    /** overall score */
    int64_t m_overallScore;

    sf::Texture buttonTexture;

    Button btnBackButton;
    Button btnPause;

public:
    Panel(const sf::RenderWindow &window);
    virtual ~Panel(){}

    void UpdateScore();
    void Draw(sf::RenderWindow &window) override;
    void processEvent(sf::Event event) override;
    bool Init(std::shared_ptr<StateMachine> ptr) override;
};

#endif // PANEL_H

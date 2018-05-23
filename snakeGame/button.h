#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>
#include "centertext.h"

class Button
{
public:

    void AddImage(sf::Sprite img)
    {
        mImage = img;
    }

    void SetOnClick(const std::function<void()>& onClick)
    {
        mOnClick = onClick;
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(mImage);
        window.draw(mText);
    }

    void HandleEvent(const sf::Event& event)
    {
        //if(sf::Mouse::isButtonPressed(sf::Mouse::Button"))
        if(event.type == sf::Event::MouseButtonReleased &&
           event.mouseButton.button == sf::Mouse::Button::Left)
        {
            if ( mImage.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) )
            {
                if(mOnClick != nullptr)
                {
                    mOnClick();
                }
            }
        }
    }

    void SetText(const std::string& text)
    {
        mText.setString(text);
        CenterSFMLText( mText );
    }

    sf::Sprite mImage;
    sf::Text mText;
private:
    std::function<void()> mOnClick;
};


#endif // BUTTON_H

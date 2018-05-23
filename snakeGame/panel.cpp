#include "panel.h"
#include "exceptions.h"

Panel::Panel(const sf::RenderWindow &window)
    : Objects (eStates::eMainGame), mPanel(), mFont(), mScore(), m_overallScore(0)
{
    mWindow = &window;
}

void Panel::UpdateScore()
{
    mScore.setString(std::to_string(++m_overallScore));
}

void Panel::Draw(sf::RenderWindow &window)
{
    window.draw(mPanel);
    window.draw(mScore);
    btnPause.draw(window);
    btnBackButton.draw(window);
}

void Panel::processEvent(sf::Event event)
{
    btnBackButton.HandleEvent(event);
    btnPause.HandleEvent(event);
}

bool Panel::Init(std::shared_ptr<StateMachine> ptr)
{
    mPanel.setSize({(float)mWindow->getSize().x, 100.f});
    mPanel.setPosition(0.f, 600.f);
    mPanel.setFillColor(sf::Color(254, 198, 135));

    if (mFont.loadFromFile("../font/Stoehr_Numbers.ttf") == false)
    {
        throw std::runtime_error(excep::CannotOpenFont);
    }
    mScore.setFont(mFont);
    mScore.setCharacterSize(30);
    mScore.setPosition(
        {(float)mWindow->getSize().x - 100, (float)mWindow->getSize().y - 130});
    mScore.setFillColor(sf::Color::White);
    mScore.setString(std::to_string(0));

    if (!buttonTexture.loadFromFile("../font/theButton.png"))
    {
        throw std::runtime_error(excep::CannotLoadBackground);
    }
    sf::Sprite pause, back;
    pause.setTexture(buttonTexture);
    back.setTexture(buttonTexture);

    pause.setOrigin(pause.getGlobalBounds().width / 2,
                    pause.getGlobalBounds().height / 2);
    pause.setPosition(mWindow->getSize().x / 2 - 200, (mWindow->getSize().y / 2) + 270);
    pause.setScale(0.15f, 0.15f);

    back.setOrigin(back.getGlobalBounds().width / 2,
                   back.getGlobalBounds().height / 2);
    back.setPosition(mWindow->getSize().x / 2 - 400,
                     (mWindow->getSize().y / 2) + 270);
    back.setScale(0.15f, 0.15f);

    btnPause.AddImage(pause);
    btnPause.SetOnClick([this]()
    {
        mState->SetState(eStates::eMainMenu);
    });
    btnPause.mText.setFont(mFont);
    btnPause.mText.setPosition(pause.getPosition());
    btnPause.SetText("Pause");

    btnBackButton.AddImage(back);
    btnBackButton.SetOnClick([this]()
    {
        mState->SetState(eStates::eMainMenu);
    });
    btnBackButton.mText.setFont(mFont);
    btnBackButton.mText.setPosition(back.getPosition());
    btnBackButton.SetText("Back");

    mState = ptr;

    return true;
}

#include "mainMenu.h"
#include "exceptions.h"

MainMenu::MainMenu(sf::RenderWindow &window) : Objects(eStates::eMainMenu), background()
{
    mWindow = &window;
}

void MainMenu::Draw(sf::RenderWindow &window)
{
    window.draw(mainMenu);
    window.draw(logo);
    mButton.draw(window);
}

void MainMenu::processEvent(sf::Event event)
{
    mButton.HandleEvent(event);
}

bool MainMenu::Init(std::shared_ptr<StateMachine> ptr)
{
    if (!background.loadFromFile("../font/green-grass-background_1373-333.jpg"))
    {
        throw std::runtime_error(excep::CannotLoadBackground);
    }

    mainMenu.setTexture(background);
    mainMenu.setPosition(0.f, 0.f);
    mainMenu.setScale(2.f, 2.f);

    if (!buttonTexture.loadFromFile("../font/theButton.png"))
    {
        throw std::runtime_error(excep::CannotLoadBackground);
    }

    sf::Sprite buttonImage;
    buttonImage.setTexture(buttonTexture);

    buttonImage.setOrigin(buttonImage.getGlobalBounds().width / 2, buttonImage.getGlobalBounds().height / 2);
    buttonImage.setPosition(mWindow->getSize().x / 2, (mWindow->getSize().y / 2) + 200 );
    buttonImage.setScale(0.25f, 0.25f);

    mButton.AddImage(buttonImage);
    mButton.SetOnClick([this]()
    {
        mState->SetState(eStates::eMainGame);
    });

    if (!font.loadFromFile("../font/Stoehr_Numbers.ttf"))
    {
        throw std::runtime_error(excep::CannotLoadBackground);
    }

    mButton.mText.setFont(font);
    mButton.mText.setPosition(buttonImage.getPosition());
    mButton.SetText("Start Game");

    if (!logoTexture.loadFromFile("../font/snake_image.png"))
    {
        throw std::runtime_error(excep::CannotLoadBackground);
    }

    logo.setTexture(logoTexture);
    logo.setPosition(mWindow->getSize().x/2 , mWindow->getSize().y/2 - 50);
    logo.setOrigin(logo.getGlobalBounds().width/2, logo.getGlobalBounds().height/2);
    logo.setScale(0.5f, 0.5f);

    mState = ptr;

    return true;
}

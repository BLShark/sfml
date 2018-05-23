#include <SFML/Graphics.hpp>
#include <exception>
#include <iostream>

#include "mainMenu.h"
#include "objects.h"
#include "panel.h"
#include "snake.h"
#include "statemachine.h"
#include <memory>

int main()
{

    try
    {
        sf::RenderWindow mWindow(sf::VideoMode(1024, 768), "Snake game");


        std::shared_ptr<Objects> mMainMenu =
            std::make_shared<MainMenu>(mWindow);
        std::shared_ptr<Objects> mPanel = std::make_shared<Panel>(mWindow);
        std::shared_ptr<Objects> mSnake = std::make_shared<Snake>([mPanel]() {
            reinterpret_cast<Panel *>(mPanel.get())->UpdateScore();
        }, mWindow);

        std::vector<std::shared_ptr<Objects>> objects = {mSnake, mPanel,
                                                         mMainMenu};

        std::shared_ptr<StateMachine> mCurrState = std::make_shared<StateMachine>();

        for (auto x : objects)
            x->Init(mCurrState);


        while (mWindow.isOpen())
        {

            mWindow.clear();

            sf::Event event;
            while (mWindow.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    mWindow.close();

                for (auto x : objects)
                {
                    if (x->GetSubscriber() == mCurrState->GetCurrState())
                    {
                        x->processEvent(event);
                    }
                }
            }

            for (auto x : objects)
            {
                if (x->GetSubscriber() == mCurrState->GetCurrState())
                {
                    x->Draw(mWindow);
                }
            }
            // Snake.run(mWindow, event);
            mWindow.display();
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }

    return 0;
}

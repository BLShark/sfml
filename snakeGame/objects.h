#ifndef OBJECTS_H
#define OBJECTS_H

#include <SFML/Graphics.hpp>

#include <memory>
#include "statemachine.h"

class Objects
{
protected:

    const sf::RenderWindow* mWindow;

    std::shared_ptr<StateMachine> mState;
    eStates mSubscriber;


public:
    Objects(eStates subscriber): mSubscriber(subscriber){}
    virtual ~Objects(){
        delete mWindow;
    }

    virtual bool Init(std::shared_ptr<StateMachine> ptr) = 0;
    virtual void Draw(sf::RenderWindow& window) = 0;
    virtual void processEvent(sf::Event event) = 0;

//    void SetEnabled(bool enable) {
//        isEnabled = enable;
//    }

    eStates GetSubscriber() {
        return  mSubscriber;
    }
};

#endif // OBJECTS_H

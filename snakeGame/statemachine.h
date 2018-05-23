#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <stdint.h>

enum class eStates : uint8_t
{
    eMainMenu = 0,
    eMainGame,
    eGamePaused,
    eGameOver
};

class StateMachine
{

private:
    eStates currState;

public:
    StateMachine(): currState(eStates::eMainMenu){
    }
    ~StateMachine(){}



    void SetState(eStates newState)
    {
        currState = newState;
    }

    eStates GetCurrState()
    {
        return currState;
    }
};

#endif // STATEMACHINE_H

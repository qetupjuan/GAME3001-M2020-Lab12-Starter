#pragma once
#ifndef __STATE_MACHINE__
#define __STATE_MACHINE__
#include "BehaviourState.h"

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update();
private:

	BehaviourState m_currentState;

};



#endif /* defined (__STATE_MACHINE__) */
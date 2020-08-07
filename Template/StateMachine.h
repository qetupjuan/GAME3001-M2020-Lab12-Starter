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

	BehaviourState m_currentOuterState;
	BehaviourState m_currentInnerState;

};



#endif /* defined (__STATE_MACHINE__) */
#pragma once
#ifndef __STATE_MACHINE__
#define __STATE_MACHINE__
#include "BehaviourState.h"
#include "DisplayObject.h"

class StateMachine
{
friend DisplayObject;

public:
	StateMachine();
	~StateMachine();

	void Update(DisplayObject* object);
	
	//getters
	BehaviourState getOuterState();
	BehaviourState getInnerState();
	
	//setters
	void setOuterState(BehaviourState new_state);
	void setInnerState(BehaviourState new_state);

private:

	BehaviourState m_currentOuterState;
	BehaviourState m_currentInnerState;

	//actions
	void m_moveToLOS(DisplayObject* object);
	void m_meleeAttack(DisplayObject* object);
	void m_flee(DisplayObject* object);
};



#endif /* defined (__STATE_MACHINE__) */
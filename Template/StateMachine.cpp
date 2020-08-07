#include "StateMachine.h"

StateMachine::StateMachine(): m_currentOuterState(FLIGHT), m_currentInnerState(PATROL)
{
}

StateMachine::~StateMachine()
= default;

void StateMachine::Update(DisplayObject object)
{
	switch (m_currentOuterState)
	{
	case FIGHT:

		switch (m_currentInnerState)
		{
		case PATROL:
			// patrol action
			break;
		case MEELE_ATTACK:
			m_meleeAttack(object);
			// patrol action
			break;
		case RANGED_ATTACK:
			// patrol action
			break;
		case MOVE_TO_LOS:
			m_moveToLOS(object);
			// patrol action
			break;
		case MOVE_TO_MEELE:
			// patrol action
			break;
		case MOVE_TO_RANGED:
			// patrol action
			break;
		case MOVE_TO_COVER:
			// action
			break;
		case WAIT_IN_COVER:
			// action
			break;
		}

		break;
	case FLIGHT:

		// flee action
		m_flee(object);
		break;
	}
}

BehaviourState StateMachine::getOuterState()
{
	return BehaviourState();
}

BehaviourState StateMachine::getInnerState()
{
	return BehaviourState();
}

void StateMachine::setOuterState(BehaviourState new_state)
{
	m_currentOuterState = new_state;
}

void StateMachine::setInnerState(BehaviourState new_state)
{
}

//actions 
void StateMachine::m_moveToLOS(DisplayObject* object)
{
	// get nearest nodee with LOS
}

void StateMachine::m_meleeAttack(DisplayObject* object)
{
	// performs melee attack
}

void StateMachine::m_flee(DisplayObject* object)
{
	// flees
}

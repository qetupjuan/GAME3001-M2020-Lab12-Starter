#pragma once
#ifndef __BEHAVIOUR_STATE__
#define __BEHAVIOUR_STATE__

enum BehaviourState
{
	FLIGHT,
	FIGHT,
	MEELE_ATTACCK,
	RANGED_ATTACK,
	MOVE_TO_LOS,
	MOVE_TO_MEELE,
	MOVE_TO_RANGED,
	PATROL,
	NUM_OF_BEHAVIOUR_STATES
};



#endif /* defined (__BEHAVIOUR_STATE__) */
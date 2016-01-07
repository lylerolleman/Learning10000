#pragma once
#include "State.h"

struct state_reward {
	int reward;
	State sprime;
}; 

state_reward act(State, int);
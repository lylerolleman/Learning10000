#pragma once
#include "State.h"
#include <vector>

class States {
	std::vector<State> states;
public:
	States();
	~States();
	void addState(State);
	int getStateIndex(State);
	State* getState(int);
	int getNumStates();
};


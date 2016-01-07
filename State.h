#pragma once
#include "Actions.h"
class State {
	int dice;
	int invalue;
	int gvalue;
	Actions actions;
	int numactions;
public:
	State();
	State(int, int, int);
	Actions* getValidActions();
	int getDice();
	int getStartingValue();
	int getScore();
	int getStateCode();
	void calculateValidActions();
};
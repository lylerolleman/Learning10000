#include "stdafx.h"
#include "States.h"


States::States() {
	states.push_back(State(0,0,0));
}


States::~States() {
}

void States::addState(State state) {
	state.calculateValidActions();
	int min = 0;
	int max = states.size()-1;
	int mid = 0;

	while (max >= min) {
		mid = (max - min) / 2 + min;
		if (states[mid].getStateCode() == state.getStateCode()) {
			fprintf(stderr, "State already exists, cannot be added again");
			break;
		}
		if (state.getStateCode() > states[mid].getStateCode()) {
			min = mid + 1;
			if (mid + 1 <= states.size()) {
				mid++;
			}
		}
		else {
			max = mid - 1;
		}
	}
	std::vector<State>::iterator it = states.begin();
	states.insert(it+mid, state);
}

int States::getStateIndex(State state) {
	//binary search to get state index, -1 if not found
	return -1;
}

State* States::getState(int index) {
	return &states[index];
}

int States::getNumStates() {
	return states.size();
}
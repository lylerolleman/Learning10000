// Learning10000.cpp : main project file.

#include "stdafx.h"
#include "play10000.h"

#include "State.h"
#include "States.h"
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	States states;
	states.addState(State(1, 0, 0));

	states.addState(State(3, 0, 0));

	states.addState(State(2, 0, 0));

	states.addState(State(5, 0, 0));
	states.addState(State(4, 0, 0));

	for (int i = 0; i < states.getNumStates(); i++) {
		printf("%d\n", states.getState(i)->getStateCode());
	}
    return 0;
}


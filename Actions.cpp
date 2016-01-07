#include "stdafx.h"
#include "Actions.h"
#include <stdio.h>
#include <stdlib.h>

Actions::Actions() {
	action anaction;
	anaction.action_code = 0;
	anaction.value = 0;
	v_actions.push_back(anaction);
}

void Actions::addAction(int new_action) {
	action anaction;
	anaction.action_code = new_action;
	anaction.value = 0;
	v_actions.push_back(anaction);
}

int Actions::getAction(int index) {
	return v_actions[index].action_code;
}

float Actions::getValue(int index) {
	return v_actions[index].value;
}

void Actions::setValue(int index, float value) {
	v_actions[index].value = value;
}

int Actions::numActions() {
	return v_actions.size();
}

int Actions::argmax() {
	float max = 0;
	int argmax = numActions()-1;
	for (int i = 0; i < numActions(); i++) {
		if (getValue(i) > max) {
			max = getValue(i);
			argmax = i;
		}
	}
	return argmax;
}

#pragma once
#include <vector>

struct action {
	int action_code;
	float value;
};

class Actions {
	std::vector<action> v_actions;
public:
	Actions();
	void addAction(int);
	int getAction(int);
	float getValue(int);
	void setValue(int, float);
	int numActions();
	int argmax();
};


#include "stdafx.h"
#include "State.h"
#include "Actions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

State::State() {
	State(0, 0, 0);
}
State::State(int dice, int invalue, int gvalue) {
	State::dice = dice;
	State::invalue = invalue;
	State::gvalue = gvalue;
}

int State::getStateCode() {
	int code = dice;
	code = code | (invalue << 15);
	code = code | (gvalue << 23);
	return code;
}

int State::getDice() {
	return dice;
}

int State::getStartingValue() {
	return invalue;
}

int State::getScore() {
	return gvalue;
}

Actions* State::getValidActions() {
	return &actions;
}

void State::calculateValidActions() {
	int diemask = 7;
	numactions = 0;
	int* dice_arr = (int*) malloc(5*sizeof(int));
	int* counts = (int*) malloc(7 * sizeof(int));
	memset(dice_arr, 0, 5 * sizeof(int));
	memset(counts, 0, 7 * sizeof(int));

	for (int i = 0, j=0; j <= 5 ; i += 3, j++) {
		int temp = (dice & (diemask << i));
		if (temp != 0) {
			dice_arr[j] = temp >> i;
			counts[temp >> i] += 1;
		}
	}

	for (int i = 0; i < 5; i++) {
		//find 1s and 5s
		if (dice_arr[i] == 1 || dice_arr[i] == 5) {
			actions.addAction(1 << i);
			int oldactions = actions.numActions()-1;
			for (int j = 0; j < oldactions; j++) {
				if (actions.getAction(j) != 0) {
					actions.addAction((1 << i) | actions.getAction(j));
				}
			}
		}
		//find triples, quadruples, etc.
		if (counts[dice_arr[i]] >= 3) {
			int dnum = (int) pow(2, counts[dice_arr[i]])-1;
			actions.addAction(dnum << i);
			int oldactions = actions.numActions() - 1;
			for (int j = 0; j < oldactions; j++) {
				if (actions.getAction(j) != 0) {
					actions.addAction((dnum << i) | actions.getAction(j));
				}
			}
			i += counts[dice_arr[i]];
		}
	}

	//find run
	if ((counts[1] == 1 &&
		counts[2] == 1 &&
		counts[3] == 1 &&
		counts[4] == 1 &&
		counts[5] == 1) ||
		(counts[2] == 1 &&
			counts[3] == 1 &&
			counts[4] == 1 &&
			counts[5] == 1 &&
			counts[6] == 1)) {
		actions.addAction(31);
	}
	free(dice_arr);
	free(counts);
}

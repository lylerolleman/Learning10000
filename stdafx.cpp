// stdafx.cpp : source file that includes just the standard includes
// Learning10000.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

int count = 0;

void init_states() {
	int dice[5] = {1, 1, 1, 1, 1};
	init_states_r(dice, 2, 0);
	printf("%d\n", count);

}

void init_states_r(int dice[], int ndice, int cdice) {
	if ((ndice > 0) && (cdice < ndice)) {
		init_states_r(dice, ndice, cdice + 1);
		count++;
		init_states_r(dice, ndice - 1, 0);
	}
}

void print_dice(int dice[]) {
	printf("{%d, %d, %d, %d, %d}\n", dice[0], dice[1], dice[2], dice[3], dice[4]);
}

int encode_dice(int* dice, int size) {
	int* counts = (int*)malloc(7 * sizeof(int));
	memset(counts, 0, 7 * sizeof(int));
	for (int i = 0; i < size; i++) {
		counts[dice[i]] += 1;
	}
	int dicebits = 0;
	for (int i = 1, j = 0; i < 7;) {
		if (counts[i] != 0) {
			dicebits = dicebits | (i << j);
			counts[i]--;
			j += 3;
		}
		else {
			i++;
		}
	}
	free(counts);
	return dicebits;
}


char* int_to_binary(int x) {
	int numbits = (int)log2(UINT_MAX) + 1;
	char* buf = (char*) malloc((numbits+1)*sizeof(char));
	memset(buf, 0, (numbits+1)*sizeof(char));
	unsigned int mask = (int)pow(2, numbits);
	
	for (int i = 0; i<numbits; i++) {
		if ((x & (mask >> i)) == 0) {
			buf[i] = '0';
		}
		else {
			buf[i] = '1';
		}
	}

	return buf;
}
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#include <limits.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// TODO: reference additional headers your program requires here
int encode_dice(int*, int);
char* int_to_binary(int);
void init_states();
void init_states_r(int[], int, int);
void print_dice(int[]);

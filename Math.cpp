/**
 * 5/19/2021
 **/
#include "Math.h" 
#include "Types.h"


/* absolute value of float */
float abs(float num) {
	if (num < 0) {
		return num - num - num;
	}
	return num;
}

/* absolute value of int */
int abs(int num) {
	if (num < 0) {
		return num - num - num;
	}
	return num;
}

/* power of float */
float pow(float num, float power) {
	float rNum = num;
	for(int i = 1; i < power; i++) {
		rNum = rNum * num;
	}
	return rNum;
}

/* returns larger values */
float Max (float n, float t) {
	if(n > t) {
		return n;
	}
	else if(t > n) {
		return t;
	}
		return n;

}

int Max (int n, int t) {
	if(n > t) {
		return n;
	}
	else if(t > n) {
		return t;
	}
	return n;
}

uint_8 Max (uint_8 n, uint_8 t) {
	if(n > t) {
		return n;
	}
	else if(t > n) {
		return t;
	}
	return n;

}


uint_16 Max (uint_16 n, uint_16 t) {
	if(n > t) {
		return n;
	}
	else if(t > n) {
		return t;
	}
		return n;
}

uint_32 Max (uint_32 n, uint_32 t) {
	if(n > t) {
		return n;
	}
	else if(t > n) {
		return t;
	}
	return n;

}

float Min (float n, float t) {
	if(n < t) {
		return n;
	}
	else if(t < n) {
		return t;
	}
	return n;

}









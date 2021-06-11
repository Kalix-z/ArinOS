/**
 * 5/19/2021
 **/

#include "Types.h"
#include "Math.h"
#pragma warning(disable)

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

bool ArrayComparison(char ar1[], char ar2[]) {
	int lenOf1 = (sizeof(ar1) / sizeof(ar1[0]));
	int lenOf2 = (sizeof(ar2) / sizeof(ar2[0]));
	/* The 2 arrays cant be equal if they both have different sizes */
	if(lenOf1 != lenOf2) {
		return false;
	}

	for(int i = 0; i < lenOf1; i++) {
		if(ar1[i] != ar2[i]) {
			return false;
		}
	}
	/* All Elements of the 2 arrays are identical */
	return true;
}

bool ArrayComparison(char ar1[], const char ar2[]) {
	int lenOf1 = (sizeof(ar1) / sizeof(ar1[0]));
	int lenOf2 = (sizeof(ar2) / sizeof(ar2[0]));
	/* The 2 arrays cant be equal if they both have different sizes */
	if(lenOf1 != lenOf2) {
		return false;
	}

	for(int i = 0; i < lenOf1; i++) {
		if(ar1[i] != ar2[i]) {
			return false;
		}
	}
	/* All Elements of the 2 arrays are identical */
	return true;
}

bool ArrayComparison(int ar1[], int ar2[]) {
	int lenOf1 = (sizeof(ar1) / sizeof(ar1[0]));
	int lenOf2 = (sizeof(ar2) / sizeof(ar2[0]));
	/* The 2 arrays cant be equal if they both have different sizes */
	if(lenOf1 != lenOf2) {
		return false;
	}

	for(int i = 0; i < lenOf1; i++) {
		if(ar1[i] != ar2[i]) {
			return false;
		}
	}
	/* All Elements of the 2 arrays are identical */
	return true;
}

bool ArrayComparison(float ar1[], float ar2[]) {
	int lenOf1 = (sizeof(ar1) / sizeof(ar1[0]));
	int lenOf2 = (sizeof(ar2) / sizeof(ar2[0]));
	/* The 2 arrays cant be equal if they both have different sizes */
	if(lenOf1 != lenOf2) {
		return false;
	}

	for(int i = 0; i < lenOf1; i++) {
		if(ar1[i] != ar2[i]) {
			return false;
		}
	}
	/* All Elements of the 2 arrays are identical */
	return true;
}

bool ArrayComparison(double ar1[], double ar2[]) {
	int lenOf1 = (sizeof(ar1) / sizeof(ar1[0]));
	int lenOf2 = (sizeof(ar2) / sizeof(ar2[0]));
	/* The 2 arrays cant be equal if they both have different sizes */
	if(lenOf1 != lenOf2) {
		return false;
	}

	for(int i = 0; i < lenOf1; i++) {
		if(ar1[i] != ar2[i]) {
			return false;
		}
	}
	/* All Elements of the 2 arrays are identical */
	return true;
}

bool ArrayComparison(long ar1[], long ar2[]) {
	int lenOf1 = (sizeof(ar1) / sizeof(ar1[0]));
	int lenOf2 = (sizeof(ar2) / sizeof(ar2[0]));
	/* The 2 arrays cant be equal if they both have different sizes */
	if(lenOf1 != lenOf2) {
		return false;
	}

	for(int i = 0; i < lenOf1; i++) {
		if(ar1[i] != ar2[i]) {
			return false;
		}
	}
	/* All Elements of the 2 arrays are identical */
	return true;
}

bool ArrayComparison(bool ar1[], bool ar2[]) {
	int lenOf1 = (sizeof(ar1) / sizeof(ar1[0]));
	int lenOf2 = (sizeof(ar2) / sizeof(ar2[0]));
	/* The 2 arrays cant be equal if they both have different sizes */
	if(lenOf1 != lenOf2) {
		return false;
	}

	for(int i = 0; i < lenOf1; i++) {
		if(ar1[i] != ar2[i]) {
			return false;
		}
	}
	/* All Elements of the 2 arrays are identical */
	return true;
}

bool ArrayComparison(uint_8 ar1[], uint_8 ar2[]) {
	int lenOf1 = (sizeof(ar1) / sizeof(ar1[0]));
	int lenOf2 = (sizeof(ar2) / sizeof(ar2[0]));
	/* The 2 arrays cant be equal if they both have different sizes */
	if(lenOf1 != lenOf2) {
		return false;
	}

	for(int i = 0; i < lenOf1; i++) {
		if(ar1[i] != ar2[i]) {
			return false;
		}
	}
	/* All Elements of the 2 arrays are identical */
	return true;
}

bool ArrayComparison(uint_16 ar1[], uint_16 ar2[]) {
	int lenOf1 = (sizeof(ar1) / sizeof(ar1[0]));
	int lenOf2 = (sizeof(ar2) / sizeof(ar2[0]));
	/* The 2 arrays cant be equal if they both have different sizes */
	if(lenOf1 != lenOf2) {
		return false;
	}

	for(int i = 0; i < lenOf1; i++) {
		if(ar1[i] != ar2[i]) {
			return false;
		}
	}
	/* All Elements of the 2 arrays are identical */
	return true;
}

bool ArrayComparison(uint_32 ar1[], uint_32 ar2[]) {
	int lenOf1 = (sizeof(ar1) / sizeof(ar1[0]));
	int lenOf2 = (sizeof(ar2) / sizeof(ar2[0]));
	/* The 2 arrays cant be equal if they both have different sizes */
	if(lenOf1 != lenOf2) {
		return false;
	}

	for(int i = 0; i < lenOf1; i++) {
		if(ar1[i] != ar2[i]) {
			return false;
		}
	}
	/* All Elements of the 2 arrays are identical */
	return true;
}


bool ArrayContains(char array[], char check[]) {
	int arraySize = sizeof(array);
	int checkSize = sizeof(check);

	/* The array must be greater than or equal to the check array */
	if(checkSize < arraySize) { return false;}

	if(checkSize == arraySize) {
		if(ArrayComparison(array, check)) { 
			return true;
		}
		return false;
	}
	return true;

}


/* Credit to @Lakshya Raj on Stack Overflow */ 
int Floor(float x)                                              
{
    float xcopy=x<0?x*-1:x;
    unsigned int zeros=0;
    float n=1;
    for(n=1;xcopy>n*10;n*=10,++zeros);
    for(xcopy-=n;zeros!=-1;xcopy-=n)
        if(xcopy<0)
        {
            xcopy+=n;
            n/=10;
            --zeros;
        }
    xcopy+=n;
    return (int)x<0?(xcopy==0?x:x-(1-xcopy)):(x-xcopy);
}





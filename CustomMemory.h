#include "Types.h"
void *operator new(unsigned int n)throw();

void operator delete(void * p);

void *operator new[](unsigned int s)throw();

void operator delete[](void *p);

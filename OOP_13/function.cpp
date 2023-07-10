#include "function.h"

int summa(int k, ...)
{
	int* ptr = &k;
	int summa = 0;
	while (k)
	{
		ptr++;
		summa += *ptr;
		k--;
	}

	return summa;
}

double summa_double(int k, ...)
{
	int* ptr = &k;
	ptr++;
	double* ptrd = (double *)ptr;

	double summa = 0.;

	for (; k--;ptrd++)
	{
		summa += *ptrd;
	}

	return summa;
}

// Library of helpfull function for svd
#include <malloc.h> 
#include <math.h>
#include "nrutil.h"

// Memory allocation vector 
double* vector(int FirstIndex, int LastIndex)
	{
	double *ptr;
	extern char *sErrorMsg;
	ptr=(double*)calloc(LastIndex+1,sizeof(double));
	if (ptr==NULL) sErrorMsg="Out of memory";
	return ptr;
	}

// Remove vector from memory
void free_vector (double* ptr, int FirstIndex, int LastIndex)
	{
	free(ptr);
	return;
	}      


// (a^2+b^2)^(1/2)
double pythag(double a, double b)
	{
	double absa,absb;
	absa=fabs(a);
	absb=fabs(b);
	if (absa>absb) return absa*sqrt(1.0+SQR(absb/absa));
	else return (absb == 0.0 ? 0.0 : absb*sqrt(1.0+SQR(absa/absb)));
	}

// Error messege 
void nrerror(char* ErrMsg)
	{
	extern char *sErrorMsg;
	sErrorMsg=ErrMsg;
	return;
	}

#define NULL    ((void *)0)
// Memory allocation vector 
double* vector(int FirstIndex, int LastIndex);
// Remove vector from memory
void free_vector (double* ptr, int FirstIndex, int LastIndex);
#define SIGN(a,v) ((v)>=0 ? (a) : (-1*(a)))
#define FMAX(a,b) ((a)>(b) ? (a) : (b))
#define IMIN(a,b) ((a)<(b) ? (a) : (b))
#define SQR(a) ((a)*(a))
// (a^2+b^2)^(1/2)
double pythag(double a, double b);
// Error messege 
void nrerror(char* ErrMsg);

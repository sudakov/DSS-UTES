//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Approximation class interface
//---------------------------------------------------------------------------
#ifndef DSSLIB_APPROX_H
#define DSSLIB_APPROX_H

#define SIGN(a,v) ((v)>=0 ? (a) : (-1*(a)))
#define FMAX(a,b) ((a)>(b) ? (a) : (b))
#define IMIN(a,b) ((a)<(b) ? (a) : (b))
#define SQR(a) ((a)*(a))

class CApprox
{
public:
	void RemoveMatrix(int m, int n, double** a);
	CApprox();
	~CApprox();
	void SetNumPoints(int m);
	void SetDimention(int n);
	void LoadPoints(double** x, double* W);
	double GetPref(double* xn);
	double** Matrix(int m, int n);
private:
	int m_n,m_m;
	double* m_Q;
	char* m_sErrorMsg;

	// Memory allocation vector 
	double* vector(int FirstIndex, int LastIndex);
	// Remove vector from memory
	void free_vector (double* ptr, int FirstIndex, int LastIndex);
	// (a^2+b^2)^(1/2)
	double pythag(double a, double b);
	// Error messege 
	void nrerror(char* ErrMsg);

	int svdcmp(double **a, int m, int n, double* w, double **v);

};

#endif // DSSLIB_APPROX_H
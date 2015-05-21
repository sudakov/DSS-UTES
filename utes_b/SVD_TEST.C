// This program make test SVD procedure
int svdcmp(double **a, int m, int n, double w[], double **v);

#include <stdio.h>     
#include <stdlib.h>
#include <malloc.h>
#include <time.h>	
#include <math.h>			 

double dRandom(double a, double b)
	{
   	static int i=1;        
   	double r=(double)RAND_MAX;
   	if (i) 
   		{
   		srand((unsigned)time(NULL));
        i=0;
        }
    return (((double)rand())/r)*pow(10.0,(((double)rand())/r)*7.0);
	}


//Matrix creation
double** Matrix(int m, int n, int IsRand)
	{
	int i,j;      
	double **a;
	a=(double**)calloc(m+1,sizeof(double*));
	for (i=1;i<=m;i++)
		a[i]=(double*)calloc(n+1,sizeof(double));
	if (IsRand==1)
		{
		for (j=1;j<=m;j++)
			for (i=1; i<=n; i++) a[j][i]=dRandom(0.0,1.0e7);
		}
	else
		{
		for (j=1;j<=m;j++)
			for (i=1; i<=n; i++) a[j][i]=0.0;
		if (IsRand)
			{
			for (i=1; i<=n; i++) a[i][i]=dRandom(0.0,1.0e7);
			if (IsRand==3)
				for (j=2;j<=m;j++)
				    for (i=1;i<n;i++) a[j][i]=a[i][j]=dRandom(0.0,1.0e7);
		    }
		}
	return a;
	}

//Matrix transponation
void Transp(double **a, int m, int n, double **aT)
	{
	int i,j;
	for (j=1;j<=n;j++)
		for (i=1;i<=m;i++) aT[j][i]=a[i][j];
	return;
	}

//Matrix copy
void Copy(double **a, int m, int n, double **b)
	{
	int i,j;
	for (j=1;j<=m;j++)
		for (i=1;i<=n;i++) b[j][i]=a[j][i];
	return;
	}

//Matrix multiplication  A * B => C 
//                      mxn nxq  mxq
void Mult(double **a, double **b, double **c, int m, int n, int q)
	{
	int i,j,k;
	double s;
	for (j=1;j<=m;j++)
		for (k=1;k<=q;k++)
			{
			s=0.0;
			for (i=1;i<=n;i++) s += a[j][i]*b[i][k];
			c[j][k]=s;
			}
	return;
	}
	
//Matrix substraction  A - B => C 
//size A,B,C: mxn    
void Substr(double **a, double **b, double **c, int m, int n)
	{
	int i,j;
	for (j=1;j<=m;j++)
		for (i=1;i<=n;i++) c[j][i]=a[j][i]-b[j][i];
	return;
	}         

//Input matrix A(mxn) from Stream
void ReadMtr(FILE *Stream, double **a, int m, int n)
	{
	int i,j;
	double buf;
	for (j=1;j<=m;j++)
		{
		for (i=1;i<=n;i++) 
			{
			fscanf(Stream,"%lf", &buf);
			a[j][i]=buf;
			}
	    fscanf(Stream,"\n");
	    }
	return;
	}	   

//Output matrix A(mxn) to Stream
void PrintMtr(FILE *Stream, double **a, int m, int n)
	{
	int i,j;
	for (j=1;j<=m;j++)
		{
		for (i=1;i<=n;i++) fprintf(Stream,"% 5e ",a[j][i]);
		fprintf(Stream,"\n");
		}
	return;
	}

double fMaxD(double **a, double **b, int m, int n)
	{
	double max, c;
	int i,j;
	max=fabs(a[1][1]-b[1][1]);
	for (j=1;j<=m;j++)
		for (i=1;i<=n;i++)
			{
			c=fabs(a[j][i]-b[j][i]);
			if (c>max) max=c;
			}
	return max;
	}

double fAvrD(double **a, double **b, int m, int n)
	{
	double c=0.0;
	int i,j;
	for (j=1;j<=m;j++)
		for (i=1;i<=n;i++)
			c+=(a[j][i]-b[j][i])*(a[j][i]-b[j][i]);
	return sqrt(c);
	}		

FILE *InF, *OutF, *TabF;        
double **A, **U, W[101], **V, **Vt, **Ac, **Ut, **I, **D;
int Row,Colm,D_F0_R1;
double MaxD[3],AvrD[3];
char Comments[30];

void main()
	{
	int i,j;
	extern char *sErrorMsg;
	
	printf("Способ задания матрицы (0-файл/1-датчик):"); scanf("%i",&D_F0_R1); 
   	printf("Row:="); scanf("%i",&Row); 
   	printf("Colm:="); scanf("%i",&Colm); 
    printf("Comments:"); scanf("%s",Comments);
    A=Matrix(Row,Colm,D_F0_R1);
	U=Matrix(Row,Colm,0);
	V=Matrix(Colm,Colm,0);
	Vt=Matrix(Colm,Colm,0);
	Ac=Matrix(Row,Colm,0);
 	Ut=Matrix(Colm,Row,0); 
 	if (!D_F0_R1)
 		{
 		InF=fopen("source.mtr","r");
 		ReadMtr(InF,A,Row,Colm);
 		}           
 	I=Matrix(Colm,Colm,0);
 	for (i=1;i<=Colm;i++) I[i][i]=1.0;
	OutF=fopen("s_test.mtr","a");
	TabF=fopen("table.tr","a");
	fprintf(OutF,"\n%s\n",Comments);
	fprintf(OutF,"A=\n");
	PrintMtr(OutF,A,Row,Colm);
	Copy(A,Row,Colm,U);
	
	if (svdcmp(U,Row,Colm,W,V)) 
		printf("\nThere is some mystake in SVD:\n%s\n",sErrorMsg);
	fprintf(OutF,"\nU=\n");
	PrintMtr(OutF,U,Row,Colm);
	fprintf(OutF,"\nV=\n");
	PrintMtr(OutF,V,Colm,Colm);
	fprintf(OutF,"\nW=");
	for (i=1;i<=Colm;i++) fprintf(OutF,"% 4e ",W[i]);
	
	Transp(V,Colm,Colm,Vt);
	Mult(V,Vt,Ac,Colm,Colm,Colm);
	MaxD[0]=fMaxD(I,Ac,Colm,Colm);
	AvrD[0]=fAvrD(I,Ac,Colm,Colm);
	fprintf(OutF,"\n\nV*V^T=I=\n");
	PrintMtr(OutF,Ac,Colm,Colm);
	
	Transp(U,Row,Colm,Ut);
	Mult(Ut,U,Ac,Colm,Row,Colm);
	MaxD[1]=fMaxD(I,Ac,Colm,Colm);
	AvrD[1]=fAvrD(I,Ac,Colm,Colm);
	fprintf(OutF,"\nU^T*U=I=\n");
	PrintMtr(OutF,Ac,Colm,Colm);

	for (i=1;i<=Colm;i++)
		for (j=1;j<=Row;j++) U[j][i] *= W[i];
	Mult(U,Vt,Ac,Row,Colm,Colm);
    MaxD[2]=fMaxD(A,Ac,Colm,Colm);
	AvrD[2]=fAvrD(A,Ac,Colm,Colm);
	fprintf(OutF,"\nAc=\n");
	PrintMtr(OutF,Ac,Row,Colm);
	fprintf(OutF,"\n-----------------------------------------------------\n");
	
	fprintf(TabF,"\n%25s\t%3i\t%3i\t",Comments,Row,Colm);
	for (i=0;i<3;i++) fprintf(TabF,"%10e\t%10e\t",MaxD[i],AvrD[i]);
	
	fclose(TabF);
	fclose(OutF);
	fclose(InF);
	return;
	}
	
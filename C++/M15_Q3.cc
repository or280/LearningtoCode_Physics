#include <iostream>
#include <math.h>
using namespace std;

int main()
{

int N = 2000;
 double A[N][N], x[N], y[N], f[N], g[N],h;

 int i,j,k;

for (i = 0; i < N; i++)
{
  x[i] = cos(i+1);
  y[i] = cos(2*(i+1));

  for (j = 0; j < N; j++)
    {
      A[i][j]=sin(i-j+1);
    }
}

cout<<"Initialised"<<endl;

for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
      {
	f[i] = f[i]+A[i][j]*x[j];
      }
  }

 for (j = 0; j < N; j++)
  {
    for (i = 0; i < N; i++)
      {
	g[j] = g[j]+y[i]*A[j][i];
      }
  }

  for (k = 0; k < N; k++)
    {
      h = h+f[k]*g[k];
    }
  

 cout<<"Problem solved for: "<< N << ". Answer is: " << h << endl;

}

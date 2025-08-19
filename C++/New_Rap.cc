//New_Rap.cc Program to calculate the root of a function f(x), given an initial guess at the root. This is found using the Newton-Raphson iterative  method.

#include <iostream>
#include <math.h>
using namespace std;

float Better_Root(float square);
float F(float x);
float dFdx(float x);


int main()
{

  float c, b, s, h, l;

  cout << "Please enter a range for which you believe will contain your roots. Enter the lower bound first then the upper bound." << endl;
  cin >> l >> h;

  s = (h - l)/100.0;
  c = l;

  for(int i = 0; i < 100; i++)
    {
     b = Better_Root(c);
     c = c + s;
     cout << "Root: " << b << "\t" << c << endl;
    }

}


float F(float x)
{
  float f;
  
  f = pow(x,2) - 4.345*x - 5.0;
  return f;
	
}


float dFdx(float x)
{
  float dfdx;
  
  dfdx = 2.0*x - 4.345;
  return dfdx;
	
}


float Better_Root(float root)
{
    
  for(int i = 0; i < 60; i++)
    {
      root = root - (F(root)/dFdx(root));
    }
  
  return root;
	
}


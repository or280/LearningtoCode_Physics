// Program to calculate the square root of a number between 1 and 100 to 5 dp, usign iterative  methods.


#include <iostream>
#include <math.h>
using namespace std;

float MySquareRoot(float square);

int main()
{

  float c, squareroot;

  cout << "Please enter a number you would like the square root of. It must be between 0.01 and 100:" << endl;
  cin >> c;

  squareroot = MySquareRoot(c);
  
  cout << "The square root is: " << squareroot << endl;
  
}


float MySquareRoot(float square)
{

  float lower = 0.1, upper = 10.1, root, sign;
    
  for(int i = 0; i < 20; i++)
    {
      root = (lower + upper)/2;
      sign = (square - pow(root,2)) * (square - pow(lower,2));
      if (sign > 0)
	lower = root;
      else
	upper = root;
    }
  
  return root;
	
}
   

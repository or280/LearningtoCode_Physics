// Program to output the sequence where you do one plus over the last term.
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  
  float N = 1;
  
  cout << N << ", ";

  for(int i = 0; i < 20; i++)
    {
      N = pow((1 + pow(N,0.5)),0.5);
      cout << N << ", ";
    }

  return 0;
}


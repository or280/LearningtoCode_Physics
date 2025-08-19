// ln2.cc  Program to estimate ln(2) using a Monte Carlo method.

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

// As in the example, I shall define ranf() to give a random number in the interval [0,1], which will be useful later.

#define ranf() \
  ((double)rand()/(1.0+RAND_MAX))

int main(int argc, char* argv[])
{
  int outcome, N, count_in = 0, seed = 83743, x = 2;
  double fraction_in;

  if(argc>1)
    {
      sscanf( argv[1], "%d", &seed); // first input in argument is the seed
    }
  if(argc>2)
    {
      sscanf( argv[2], "%d", &x); // second input in argument is x, the number of decimal points you want
    }
  
  srand(seed);


  // Error in ln(2) using this method goes as 1/N. So, if we want x decimal points, and as the number is of the order of 10^0, the fractional error will be of the order of 10^-x. We can then calculate N, the number of repeats, which will be 1 over the fractinal error then squared.

  N = pow(pow(10,x),2);
  

  for(int n = 1; n <= N; n++)
    {
      double x = ranf() + 1;  // random number in [1,2]
      double y = ranf();      // random number in [0,1]
      outcome = (y < 1/x) ? 1 : 0;
      count_in += outcome;
      fraction_in = static_cast<double>(count_in)/n;
      //cout << "Location" << outcome << "\t" << x << "\t" << y << "\t" << count_in << "\t" << n << "\t" << fraction_in << endl;
    }

  cout << endl << endl;
  cout << "You have selected a seed = " << seed << " and a number of decimal points of " << x << "." << endl << endl;
  cout.precision(x);
  cout << "The value of ln(2) to this number of deicmal points is " << fraction_in << ". Thanks for using this program to calculate ln(2)." << endl << endl;
  
  return 0;
}

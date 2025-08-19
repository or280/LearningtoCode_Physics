// Program to output the sequence where you do one plus over the last term.
#include <iostream>
using namespace std;

int main()
{
  float N = 1, x = 0;

  cout << "Please input a non zero number tor this sequence to start:" <<endl;
  cin >> x;
  N = x;
  cout << x << ", ";

  for(int i = 0; i < 20; i++)
    {
      N = x + 1/N;
      cout << N << ", ";
    }

  return 0;
}

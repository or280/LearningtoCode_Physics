// Program to sum first N odd numbers.
#include <iostream>
using namespace std;

int main()
{
  int N = 0, total = 0;

  cout << "Enter an integer up to which you want the odd numbers summed:" << endl;
  cin >> N;

  for(int i = 1; i <= N; i += 2)
    {
      total += i;
    }

  cout << "The sum of the odd integers up to N is " << total << endl;

  return 0;
}

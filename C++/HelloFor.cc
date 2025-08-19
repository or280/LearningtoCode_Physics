// HelloFor.cc

#include <iostream>
using namespace std;

int main()
{

  int loop, lucky;

  cout << "Enter first number of times you want to say hello, and then which hello will be your lucky one." << endl;
  cin >> loop >> lucky;
  
  for (int i=1; i<=loop; i++) {
    cout << i << " hello world" << endl ;
    if ( i == lucky ) {
     cout << "that was lucky!" << endl ; }
    else {
      cout << endl ;
    }
  }
}

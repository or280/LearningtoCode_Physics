// Swallow.cc  A test to calculate the velocity of an swallow.

#include <iostream>
using namespace std;

int main()
{

  int origin, load;

  cout << "This is a test to calculate the airspeed velocity of a swallow. (If you wanted the test to find out if you are the holy saviour, please email brian@hesaverynaughtyboy.co.uk, and for the test for whether you can stomach a wafer thin mint, please email creosote@explosion.com)." << endl;
  cout << "Please enter the number 1 if your swallow is African and 0 if it is European" << endl;
    cin >> origin;
  if (origin == 0) {
    cout << "Is your swallow unladen (enter 0), or, in fact, gripping by the husk a cocunut to carry from the tropics to Mercia to be used to make a horse noise (enter 1)." << endl;
    cin >> load;
    if (load == 0) {
      cout << "The airspeed velocity of the an unladen European Swallow is 11m/s, which it maintains by beating its wings 43 times per second (actually about 8 but who's counting). Now you have enough information to successfully cross the bridge of death by answerng the bridgekeepers questions three. Good luck." << endl; }
    else {
      cout << "The velocity is 0. Its a simple question of weight ratios, a 5 ounce bird cannot carry a 1 pound cocunut." << endl; }
  }
  else {
     cout << "Is your swallow unladen (enter 0), or, in fact, gripping by the husk a cocunut to carry from the tropics to Mercia to be used to make a horse noise (enter 1)." << endl;
    cin >> load;
    if (load == 0) {
      cout << "The airspeed velocity of the an unladen African Swallow had not been intensively studied by the 6th century and so no value could be obtained." << endl; }
    else {
      cout << " The cocunut could be carried by an African swallow yes, but then of course, African swallows are non-migratory, so who really cares what their airspeed velocity is." << endl; } 
  }

  cout << "..." << endl;
  cout << "Wait a minute, supposing two migrating European swallows carried it together, using a strand held underneath their dorsal guiding feathers, surely that would work?" << endl;
    
}

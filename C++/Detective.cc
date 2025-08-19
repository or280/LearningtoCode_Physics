// Detective.cc  A game where you, as Detective Tiger, have to guess what the crime was, who did it and why, based on the initial clues.

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  cout << endl << "Hello there, you are Detective Tiger, the first detective on the scene after the crime that has been committed. You don't know what the crime was, who did it or why, becuase a cocunut fell on the head of the witness before they could tell you what happened. (The cocunut, it transpires, was dropped by two migrating European Swallows, who were holding it on a string tucked underneath their dorsal guiding feathers)." << endl << endl << "When arriving on the crime scene, you find a flat patch of grass beside a half cut down tree, a very dented salmon and a few plant pots." << endl;

  int lives = 1, crime, who, why;


  while(lives >= 0)
    {
      cout << "What was the crime?" << endl << "1. Murder" << endl << "2. Robbery" << endl << "3. Insurance fraud" << endl << "4. There was no crime?" << endl;
      cin >> crime;
      
      switch (crime)
	{
	case 1:
	  cout << "Great detective work, this was indeed murder. The body had been moved before you got there." << endl << "You must now decide who did it. Was it:" << endl << "1. The sexy vicar off of Fleabag" << endl << "2. The knights who say 'ni'." << endl <<  "3. The black knight (presumably by biting their legs off)." << endl << "4. The killer rabbit" << endl;
	  cin >> who;

	  switch (who)
	    {
	    case 1:
	      cout << "No, unfortunatly this was not the sexy vicar. Have another go!" << endl;
	      lives -= 1;
	      break;

	    case 2:
	      cout << "Correct! The knights who say 'ni' have been at it again. They have used their wicked word to force a man to chop down the mightiest tree in the forest with ... a salmon, who has evidently died of exhaustion (the man, although the salmon is proabably fairly exhausted as well)." << endl << "Finally, why did the knights do this to this poor man." << endl << "1. Because he got on their nerves by not going away." << endl << "2. Because he tried to pass through the knights land without a permit." << endl << "3. He provided a inadequate shrubbery to the knights, and hence required punishment." << endl;
	      cin >> why;

		switch (why)
		  {
		  case 1:
		    cout << "No, although likely, this is not the reason they murdered him. Have another go." << endl;
		    lives -= 1;
		    break;

		  case 2:
		    cout << "The man did try to pass through the knights land, but they wouldn't kill for such a petty offence. Have another go." << endl;
		    lives -= 1;
		    break;

		  case 3:
		    cout << "Yes, the shrubery was completely unacceptable and he had what was coming." << endl << "Congratulations! You have solved the mystery, the knights who say 'ni' have been rounded up by saying 'it' and put in jail.";
		    return 0;

		  default:
		    cout << "This was not an option, the game has been terminated!" << endl;
		    return -1;
	    
		  }

	      break;

	    case 3:
	      cout << "The black night is still tending to his flesh wounds by the river. It wasn't him. Have another go." << endl;
	      lives -= 1;
	      break;

	    case 4:
	      cout << "The killer rabbit was desposed off using the Holy Hand Grenade of Antioch only last week. It can't have been it. Have another go." << endl;
	      lives -= 1;
	      break;

	    default:
	      cout << "This was not an option, the game has been terminated!" << endl;
	      return -1;
	    
	    }
	  
	  break;

	case 2:
	  cout << "This was not in fact robbery, have another go!" << endl;
	  lives -= 1;
	  break;
     
        case 3:
	  cout << "Despite initial impressions, this was not insurance fraud, have another go!" << endl;
	  lives -= 1;
	  break;

	case 4:
          cout << "No, I don't like it, seems to obvious to be true. Have another go!" << endl;
	  lives -= 1;
	  break;

	default:
	  cout << "This was not an option, the game has been terminated!" << endl;
	  return -1;

	}
    }

  cout << " You have run out of guesses and the criminal has escaped the country and will live out the remainder of their life in a villa looking after a herd of llamas.";
  return -1;
}

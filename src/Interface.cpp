#include <Interface.h>

// Constructor
InvInterface::InvInterface(){

	}

// Destructor
InvInterface::~InvInterface(){

	}

void InvInterface::Run(){
	// PRE:		The N.O. InvInterface is valid
	// POST:	The program is finished running.
	
	// Flag for when we are done running
	bool done;
	
	int choice;
	
	// Intialize main loop
	done = false;

	while(done){
		
		
		}
	}
	
int InvInterface::GetMenuChoice(){
	//PRE:	The N.O. InvInterface is valid
	//POST:	This method will get user input and return
	//		an integer.
	int input;
	
	// Promp Input
	cout << "Enter Menu Option" << endl;
	
	// Get input
	cin >> input;
	
	// Data validation
	while(!cin.good() || input < 1 || input > numMenuOptions){
		// Clear flags and buffers
		cin.clear();
		cin.ignore(80, '\n');
		
		// Prompt for new input
		cout << "Bad Input" << endl << "Enter Menu Option" << endl;
		
		cin >> input;
		}
		
	// Return menu choice
	return input;
	}
#include <Interface.h>

// Constructor
InvInterface::InvInterface(){
	//TODO:
	// If the Inventory books initializes it's self we may not need this
	// constructor, or the destructor. 
	}

// Destructor
InvInterface::~InvInterface(){
	//TODO: See comment about the constructor
	}

void InvInterface::Run(){
	// PRE:		The N.O. InvInterface is valid
	// POST:	The program is finished running.
	
	// Flag for when we are done running
	bool done;
	
	// Menu Choice
	int choice;
	
	// Intialize main loop
	done = false;

	while(!done){
		
		// Get user input for menu.
		choice = GetMenuChoice();
		
		// take action with user input. 
		switch(choice){
			//User has chosen to display book inventory
			case MenuOption::View:
				break;
				
			// User has chosen to sell books in inventory
			case MenuOption::Sell:
			
				break;
				
			// User has chosen to order more books
			case MenuOption::Order:
			
				break;
				
			// user has chosen to exit program.
			case MenuOption::Exit
				done = true;
				break;
			
			}
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
	
	// Clear Input stream
	cin.ignore();
		
	// Return menu choice
	return input;
	}
	
string GetTitle(){
	// This is a helper function that returns a string for a book title. 
	//PRE:	None
	//POST:	None
	//Prompt and get input
	cout << "Enter the title of the book you would like to remove." << enld;
	getline(cin, title);
	
	// Datat validation
	while(!cin.good()){
		cout << "Error: Invalid Title" << endl;
		cout << "Enter the title of the book you would like to remove." << enld;
		getline(cin, title);
		}
	
	return title;
	}
	
void InvInterface::ViewInventory(){
	//PRE:	The N.O. InvInterface is valid
	//POST:	The N.O. InvInterface will be unchange
	//		and the inventory will have been displayed.
	books.Display();
	}
	
void InvInterface::SellBook(){
	//PRE:	The N.O. InvInterace is valid.
	//POST:	The N.O. will be valid. If a book of with title given by the user
	//		is in the inventory it will be removed, other wise the user	
	//		will have been told the book doesn't exist.
	string title;
	
	// Get a title
	title = GetTitle();
	
	// remove the book from inventory.
	books.RemoveBook(title);
	
	}
	
void InvInterace::OrderBook(){
	//PRE:	The N.O. InvInterface is valid. 
	//POST:	The user will be prompted for a title, if that title is in the inventory
	//		a number of books will be added to reach that books maxInv, otherwise the
	//		user will be prompted for the information to create a new book. 
	string title;
	
	// Get a title
	title = GetTitle();
	
	// remove the book from inventory
	books.RemoveBook(title);
	}
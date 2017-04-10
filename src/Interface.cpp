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
	MenuOption choice;
	
	// Intialize main loop
	done = false;

	while(!done){
		
		// Get user input for menu.
		DisplayMenu();
		choice = GetMenuChoice();
		
		// take action with user input. 
		switch(choice){
			//User has chosen to display book inventory
			case MenuOption::View:
					ViewInventory();
				break;
				
			// User has chosen to sell books in inventory
			case MenuOption::Sell:
					SellBook();
				break;
				
			// User has chosen to order more books
			case MenuOption::Order:
					if(OrderBook())
						cout << "The requested books have been ordered." << endl;
					else
						cout << "The requested book was not found in the system." << endl;
				break;
				
			// user has chosen to exit program.
			case MenuOption::Exit
				done = true;
				break;
			
			}
		}
	}
void InvInterface::DisplayMenu(){
	//PRE:	The N.O. is valid
	//POST:	The N.O. is unchanged and menu text is displayed.
	cout << "Menu:" << endl;
	cout << MenuOption.View << ". View Inventory" << endl;
	cout << MenuOption.Sell << ". Sell Book" << endl;
	cout << MenuOption.Order << ". Order Book" << endl;
	cout << MenuOption.Exit << ". Exit" << endl;
	
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
	
string InvInterface::GetTitle(){
	// This is a helper function that returns a string for a book title. 
	//PRE:	None
	//POST:	None
	//Prompt and get input
	getline(cin, title);
	
	// Datat validation
	while(!cin.good()){
		cout << "Error: Invalid Input" << endl;
		getline(cin, title);
		}
	
	return title;
	}

long long InvInterface::InputISBN(){
	bool inputGood;
	string s_ISBN;
	
	do{
		cout << "Enter a 10 digit ISBN:"
		getline(cin, s_ISBN);
	
		inputGood = true;
	
		// set inputGood to false and clean up cin if it is bad.
		if(!cin.good()){
			inputGood = false;
			cin.clear();
			cin.ignore(80, '\n');
		}
	
		if(s_ISBN.size() != 10)
			inputGood = false;
		else
			// Check for non digit characters
			for(int i = 0; i < s_ISBN.size(); i++)
				if(s_iSBN[i] < 48 || s_ISBN[i] > 57)
					inputGood = false;
	
	}while(!inputGood);
	
	// convert string to a long long and return;
	return stoll(s_ISBN);
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
	cout << "Enter Title:";
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
	cout << "Enter the title of the book you would like to remove." << enld;
	title = GetTitle();
	
	// remove the book from inventory
	if(!books.orderBook(title)){
		cout << "Book - \"" << title << "\" was not found in inventory" << endl;
		cout << "Would you like to add it to inventory?";
		char input;
		
		cout << "Type Y/N:";
		cin.get(input);
		while(input != 'Y' && input != "N" && input != 'y' && input != 'n'){
			cout << "Bad input!" << endl;
			cin.get(input);
			}
		
		// User chose to not add a new book.
		if(input == 'N' || iput == 'n'){
			return;
		}
		// User chose to add new book
		else{
			int minStock = 5;
			int maxStock = 20;
			int price;
			long long ISBN;
			Book *obj = new Book();
			
			// Enter Title
			obj.setName(title);
			
			// Enter Publisher
			cout << "Enter the name of the Publisher.";
			obj.setPublisher(getTitle());
			
			// Enter ISBN
			ISBN = InputISBN();
			obj.setISBN();
			
			// Enter Price
			//TODO: change price to a float and check for extra floating point
			cout << "Enter Price:";
			cin >> price;
			while(!cin.good()){
				cin.clear();
				cin.ignore(80, '\n');
				
				cin >> price;
			}
			obj.setPrice(price);
			
			obj.setStock(maxStock);
			obj.setMinStock(minStock());
			obj.setMaxStock(maxStock();
			
			if(books.addBook(obj))
			}
		}
	}

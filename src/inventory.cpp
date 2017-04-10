//inventory.cpp

#include <inventory.h>
#include "book.h"

//#include <vector>

//constructor
inventory::inventory(){}
//deconstructor
inventory::~inventory(){}

bool inventory::addBook(book obj){
    //PRE: the stock must not be full
    //POST: a book will be added to the current stock
	list.push_back(obj);
	std::sort(list.begin(), list.end());
	return true;
    }

bool inventory::orderBook(string title){
    //PRE: none
    //POST: the list size will be incremented and a new book will be in stock
	bool found = false;
	while(!found){
		// Check if title is the same as that of the current book.
		if(title.compare(list[i]) == 0){
			found = true;
			
			list[i].setStock(list[i].getMaxStock());
			}
		}
	return found;
    }

void inventory::sellStock(string title){
    //PRE: the book must be available and not out of stock
    //POST: the book removed must also be removed from the list of books available
    bool found = false;
	while(!found){
		// Check if title is the same as that of the current book.
		if(title.compare(list[i]) == 0){
			found = true;
			
			// only sell if we have at least 1 book.
			if(list[i].getStock() > 0)
				list[i].setStock(list[i].getStock()-1);
			else
				cout << "Book - \"" << title << "\" is out of stock" << endl;
			
			//Check for low on hand.
			lowOnHandAlert();
			}
		}
	if(!found)
		cout << "Book - \"" << title << "\" was not found in inventory." << endl;
    }

void inventory::lowOnHandAlert(){
	//PRE: The N.O. inventory and list must be valid
	//POST: none
	//this will prompt the user when there aren't enough books
	for(int i = 0; i < list.size(); i++){
		// If we are low on stock of a book, display warning, title of book,
		// and current stock.
		if( list[i].getStock() < list[i].getMinStock() ){
			cout << "Low on hand: " << list[i].getTitle();
			cout << " - " list[i].getStock() << endl;
			}
		}
	}

//not exactly sure what to display
void inventory::display(){
    //PRE:
    //POST:
    }

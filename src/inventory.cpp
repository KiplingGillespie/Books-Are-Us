//inventory.cpp

#include "inventory.h"
#include "book.h"
//needed for the std::sort to work here
#include <algorithm>

//#include <vector>

//may not need these but we'll see
//constructor
inventory::inventory(){}
//deconstructor
inventory::~inventory(){}


bool inventory::TitleCompare(book i, book j){
    return (i.getName() > j.getName());
    }

void inventory::addBook(book obj){
    //PRE: none
    //POST: a book will be added to the list of books
    books.push_back(obj);
    //sort the list using the std sort
    std::sort(books.begin(), books.end(), TitleCompare);
    }

//used to add new books
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
    //POST: decreasing the stock of the book by 1
    bool found = false;
	while(!found){
		//check if the book titles are the same
		if(title.compare(list[i]) == 0){
			found = true;
			
			//only sell if we have it
			if(list[i].getStock() > 0){
				list[i].setStock(list[i].getStock() - 1);
                
                //check if our stock of that book is low
                lowOnHandAlert();
                }
			else
				cout << title << " is out of stock." << endl;
            }
		}
	}

//prompt
void inventory::lowOnHandAlert(int index){
    //PRE: the stock must not be full
    //POST: none
    //this will prompt the user there aren't enough books
    stock = list[index].getStock();
    min = list[index].getMinStock();
    
    if(stock < min){
        cout << list[index].getName() << "Low on stock, please restock." << endl;
        }
    }

//displays the current inventory
void inventory::display(){
    //PRE:
    //POST:
    }

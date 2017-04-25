//inventory.cpp

#include "inventory.h"

//needed for the std::sort to work here
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//may not need these but we'll see
//constructor
inventory::inventory(){
	cout << "Inventory Constructor start" << endl;
	ifstream inputStream(_FILENAME_); 
	Book * temp;
	int size;
	int lenName;
	int lenPub;
	string name;
	string publisher;
	long long isbn;
	int price;
	int stock;
	int minStock;
	int maxStock;
	char * buffer;

	//Test file upon opening
	if (inputStream.fail()) 
		cout << "This file does not exist" << endl;

	// The file opens
	if(inputStream.good()) {
		inputStream.read(reinterpret_cast<char*>(&size), sizeof(size));
		for(int i = 0; i < size; i++){
			temp = new Book();

			//name
			inputStream.read(reinterpret_cast<char*>(&lenName), sizeof(lenName));
			buffer = new char [lenName];
			inputStream.read(buffer, lenName);
			name = string(buffer);
			delete[] buffer;

			//publisher
			inputStream.read(reinterpret_cast<char*>(&lenPub), sizeof(lenPub));
			buffer = new char [lenPub];
			inputStream.read(buffer, lenPub);
			publisher = string(buffer);
			delete[] buffer;

			// isbn
			inputStream.read(reinterpret_cast<char*>(&isbn), sizeof(long long));
			// price
			inputStream.read(reinterpret_cast<char*>(&price), sizeof(int));
			//stock
			inputStream.read(reinterpret_cast<char*>(&stock), sizeof(int));
			inputStream.read(reinterpret_cast<char*>(&minStock), sizeof(int));
			inputStream.read(reinterpret_cast<char*>(&maxStock), sizeof(int));

			temp -> setName(name);
			temp -> setPublisher(publisher);
			temp -> setISBN(isbn);
			temp -> setPrice(price);
			temp -> setStock(stock);
			temp -> setMinStock(minStock);
			temp -> setMaxStock(maxStock);
			AddBook(temp);
			temp = NULL;
		}
	}
}
//deconstructor
inventory::~inventory(){
	cout << "Inventory Destructor start" << endl;

	// Save out file information
	ofstream of(_FILENAME_);
	// TODO: Replace with better error checking.
	if( of.is_open() ){
		cout << "File" << _FILENAME_ << " is open." << endl;

		// write out the number of books we need to save.
		int listSize = list.size();
		of.write( reinterpret_cast<const char*>(&listSize), sizeof(listSize) );

		int nameLen;
		int pubLen;
		string name;
		string pub;
		long long isbn;
		int price;
		int Stock;
		int minStock;
		int maxStock;

		// Write out each book in the inventory
		for(int i = 0; i < listSize; i ++){
			cout << "Book " << i << endl;
			name = list[i]->getName();
			nameLen = name.size();
			pub = list[i]->getPublisher();
			pubLen = pub.size();

			of.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
			of.write(name.c_str(), nameLen);
			of.write(reinterpret_cast<const char*>(&pubLen), sizeof(pubLen));
			of.write(pub.c_str(), pubLen);

			isbn = list[i]->getISBN();
			price = list[i]->getPrice();
			Stock = list[i]->getStock();
			minStock = list[i]->getMinStock();
			maxStock = list[i]->getMaxStock();
			of.write(reinterpret_cast<const char*>(&isbn), sizeof(long long));
			of.write(reinterpret_cast<const char*>(&price), sizeof(int));
			of.write(reinterpret_cast<const char*>(&Stock), sizeof(int));
			of.write(reinterpret_cast<const char*>(&minStock), sizeof(int));
			of.write(reinterpret_cast<const char*>(&maxStock), sizeof(int));
			}
		}

	//Loop through list and delete each object.
	for(int i = 0; i < list.size(); i++){
		// check for valid memory
		if(list[i])
			delete list[i];
		}

		cout << "Inventory Destructor End" << endl;
		cin.get();
	}


bool TitleCompare(const Book *i, const Book *j){
    if( i->getName().compare(j->getName()) < 0)
       return true;
    else
    	return false;
    }

void inventory::AddBook(Book *obj){
	//PRE: none
	//POST: a book will be added to the list of books
	list.push_back(obj);

	//sort the list using the std sort
	std::sort(list.begin(), list.end(), TitleCompare);
	}

//used to add new books
bool inventory::OrderBook(string title){
    //PRE: none
    //POST: the list size will be incremented and a new book will be in stock
    bool found = false;
    int i = 0;
    int size = list.size();

    while(!found && i < size){
        // Check if title is the same as that of the current book.
        if(title.compare(list[i]->getName()) == 0){
            found = true;
            list[i]->setStock(list[i]->getMaxStock());
            }

	i++;
        }

    return found;
    }

void inventory::SellStock(string title){
    //PRE: the book must be available and not out of stock
    //POST: decreasing the stock of the book by 1
    bool found = false;

	int i = 0;
	int size = list.size();

	// Tell user inventory doesn't contain any books.
	if(size > 1){
		cout << "No Books In Inventory." << endl;
		return;
		}

	while(!found && i < size){
		//check if the book titles are the same
		if(title.compare(list[i]->getName()) == 0){
			found = true;
			//only sell if we have it
			if(list[i]->getStock() > 0){
				list[i]->setStock(list[i]->getStock() - 1);
                		cout << "One copy of " <<  title << " sold." << endl;
				//check if our stock of that book is low
                		lowOnHandAlert(i);
                	}
			else
				std::cout << title << " is out of stock." << std::endl;
            		}
		// increase iterator
		i++;
		}

	// Tell them if the book was not found.
	if(!found)
		cout << title << " is not in the system." << endl;

	}

//prompt
void inventory::lowOnHandAlert(int index){
    //PRE: the stock must not be full
    //POST: none
    //this will prompt the user there aren't enough books

    int stock = list[index]->getStock();
    int min = list[index]->getMinStock();

    if(stock < min){
        cout << list[index]->getName() << ": Low on hand, please restock." << endl;        }
    }

//displays the current inventory
void inventory::display(){
	//PRE: inventory must be valid
   	//POST: the inventory will be displayed
	cout << left << setw(20) << "Book Title";
	cout << setw(20) << "ISBN";
	cout << setw(15) << "Publisher";
	cout << setw(10) << "Stock";
	cout << endl;

	//display the inventory
	for(int i = 0; i < list.size(); i++){
		cout << setw(20) << list[i]->getName();
		cout << setw(20) << list[i]->getISBN();
		cout << setw(15) << list[i]->getPublisher();
		cout << setw(10) << list[i]->getStock();
		cout << endl;
       }
}

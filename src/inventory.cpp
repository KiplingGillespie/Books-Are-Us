//inventory.cpp

#include <inventory.h>
#include <book.h>

//#include <vector>

//constructor
inventory::inventory(){}
//deconstructor
inventory::~inventory(){}

bool inventory::addBook(book obj){
    //PRE: the stock must not be full
    //POST: a book will be added to the current stock
    }

void inventory::orderBook(string title){
    //PRE: none
    //POST: the list size will be incremented and a new book will be in stock
    }

void inventory::sellStock(string title){
    //PRE: the book must be available and not out of stock
    //POST: the book removed must also be removed from the list of books available
    
    }

void inventory::lowOnHandAlert(){
    //PRE: the stock must not be full
    //POST: none
    //this will prompt the user there aren't enough books
    }

//not exactly sure what to display
void inventory::display(){
    //PRE:
    //POST:
    }

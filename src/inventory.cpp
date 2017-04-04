//inventory.cpp

#include <invetory.h>
#include <book.h>

//#include <vector>

//constructor
inventory::inventory(){}
//deconstructor
inventory::~inventory(){}

bool inventory::addBook(book obj){
    //PRE: none
    //POST: a book will be added to the list of books available
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
    //PRE: the user selects a book that is either running low
    //POST: none
    //prompt the user there arent any books available at the time
    }

//not exactly sure what to display
void inventory::display(){
    //PRE:
    //POST:
    }

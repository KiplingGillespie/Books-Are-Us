#include <invetory.h>

//constructor
inventory::inventory(){}
//deconstructor
inventory::~inventory(){}

void inventory::addBook(Book){
    //PRE: none
    //POST: the book added must also be added to the list of books available
    }

void inventory::remove(Book){
    //PRE: the book must be available and not out of stock
    //POST: the book removed must also be removed from the list of books available
    }

//should i call this method something else?
//or add another method for the books that are out of stock?
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

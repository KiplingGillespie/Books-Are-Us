#include "book.h"

//Constructor
Book::Book(){
}

//Destructor
Book::~Book() {
}

//PRE: The N.O. Book is valid
//POST: The private data member name is returned
string Book::getName() const {
	return name;
}

//PRE:The N.O. Book is valid
//POST: publisher is returned
string Book::getPublisher() {
	return publisher;
}

//PRE: The N.O. Book is valid
//POST: price is returned
int Book::getPrice() {
	return price;
}

//PRE: The N.O. Book is valid
//POST: ISBN is returned
long long Book::getISBN(){
	return ISBN;
}

//PRE: The N.O. Book is valid
//POST: stock is returned
int Book::getStock(){
	return stock;
}

//PRE: The N.O. Book is valid
//POST: minStock is returned
int Book::getMinStock(){
	return minStock;
}

//PRE: The N.O. Book is valid
//POST: maxStock is returned
int Book::getMaxStock() {
	return maxStock;
}
// Mutators
void Book::setName(string bookName){
	name = bookName;
}
void Book::setPublisher(string bookPublisher){
	publisher = bookPublisher;
}
void Book::setISBN(long long bookISBN) {
	ISBN = bookISBN;
}
void Book::setPrice(int bookPrice) {
	price = bookPrice;
}
void Book::setStock(int bookStock){
	stock = bookStock;
}
void Book::setMinStock(int min){
	minStock = min;
}
void Book::setMaxStock(int max){
	maxStock = max;
}

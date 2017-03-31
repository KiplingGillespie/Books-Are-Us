#include <Book.h>

//Constructor
void Book::Book(){
}

//Destructor
void Book::~Book() {
}

//PRE: The N.O. Book is valid
//POST: The private data member name is returned
string Book::getName() {
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
int Book::getISBN(){
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
	bookName = name;
}
void Book::setPublisher(string bookPublisher){
	bookPublisher = publisher;
}
void Book::setISBN(int bookISBN) {
	bookISBN = ISBN;
}
void Book::setPrice(int bookPrice) {
		bookPrice = price;
}
void Book::setStock(int bookStock){
	bookStock = stock;
}
void Book::setMinStock(int min){
		min = minStock;
}
void Book::setMaxStock(int max){
	max = maxStock;
}
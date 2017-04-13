//book.h
#ifndef _BOOK_H_
#define _BOOK_H_

#include <string>
using namespace std;

class Book {
	private:
		string name;
		string publisher;
		long long ISBN;
		int price;
		int stock;
		int minStock;
		int maxStock;
	public:
		//constructor
		Book();
		
		//destructor
		~Book();
		
		//accessors 
		string getName();
		string getPublisher();
		long long getISBN();
		int getPrice();
		int getStock();
		int getMinStock();
		int getMaxStock();
		
		//mutators
		void setName(string);
		void setPublisher(string);
		void setISBN(long long);
		void setPrice(int);
		void setStock(int);
		void setMinStock(int);
		void setMaxStock(int);
};

#endif

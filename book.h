//book.h
#include <Book.h>
class Book {
	private:
		string name;
		string publisher;
		int ISBN;
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
		int getISBN();
		int getPrice();
		int getStock();
		int getMinStock();
		int getMaxStock();
		
		//mutators
		void setName(string);
		void setPublisher(string);
		void setISBN(int);
		void setPrice(int);
		void setStock(int);
		void setMinStock(int);
		void setMaxStock(int);
};
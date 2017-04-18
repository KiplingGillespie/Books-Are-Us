//inventory.h
#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include "book.h"
#include <vector>

class inventory{

    private:
        //vector reffering to the class Book from book.h
        std::vector<Book*> list;

        //any variables needed

    public:
        //consructor
        inventory();
        //deconstructor
        ~inventory();

        //static bool TitleCompare(const Book &i, const Book &j) {return ( i.getName() > j.getName()); }
	void AddBook(Book *obj);
        bool OrderBook(string title);
        void SellStock(string title);
        void lowOnHandAlert(int position);
        void display();
    };

#endif

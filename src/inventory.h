//inventory.h
#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include "inventory.h"
#include "book.h"
#include <vector>

class inventory{
    
    private:
        //vector reffering to the class Book from book.h
        vector<Book> list;
    
        //any variables needed
        
    public:
        //consructor
        inventory();
        //deconstructor
        ~inventory();
    
        bool TitleCompare(book i, book j)
        void addBook(book obj);
        bool orderBook(string title);
        void sellStock(string title);
        void lowOnHandAlert();
        void Display();

    };

#endif

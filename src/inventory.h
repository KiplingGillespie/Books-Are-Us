//inventory.h

#def _INVENTORY_H_
#indef _INVENTORY_H_

#include <inventory.h>

class inventory{
    //List:Vector(Book)?
    private:
        //any variables needed
        
    public:
        //consructor
        inventory();
        //deconstructor
        ~inventory();
    
        //the parameter "Book" is temporary
        void addBook(Book);
        void removeBook(Book);
        void lowOnHandAlert();
        void display();
    
        //should I add this?
        //void outOfStock();
    
    };

#endif
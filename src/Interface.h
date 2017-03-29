#ifndef _INVINTERFACE_H_
#define _INVINTERFACE_H_

#include <Inventory.h>

class InvInterface{
	private:
		// The inventory of our books
		Inventory books;
		
		enum MenuOption {}
		const int numMenuOptions = 5;
	public:
		// Constructors
		InvInterface();
		
		// Desctructors
		~InvInterface();
		
		//
		void Run();
		int GetMenuChoice();
};

#endif
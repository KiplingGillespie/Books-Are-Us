#ifndef _INVINTERFACE_H_
#define _INVINTERFACE_H_

#include <Inventory.h>
#include <string>

class InvInterface{
	private:
		// The inventory of our books
		Inventory books;
		
		enum MenuOption {View, Sell, Order, Exit};
		
		// Set numMenuOptions equal to the last value in the MenuOption enum
		const int numMenuOptions = Exit;
		
	public:
		// Constructors
		InvInterface();
		
		// Desctructors
		~InvInterface();
		
		//
		void Run();
		
		void DisplayMenu();
		int GetMenuChoice();
		
		string GetTitle();
		
		// User actions
		void ViewInventory();
		void SellBook(string title);
		bool OrderBook(string title);
		
};

#endif
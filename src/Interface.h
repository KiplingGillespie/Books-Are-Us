#ifndef _INVINTERFACE_H_
#define _INVINTERFACE_H_

#include "inventory.h"
#include <string>

class InvInterface{
	private:
		// The inventory of our books
		inventory books;
		enum MenuOption {View = 1, Sell, Order, Exit};

		// Set numMenuOptions equal to the last value in the MenuOption enum
		const int numMenuOptions = Exit;
	public:
		// Constructors
		InvInterface();

		// Desctructors
		~InvInterface();

		//Main looping funciton
		void Run();

		void DisplayMenu();

		// Assist methods
		int GetMenuChoice();
		string GetTitle();
		long long InputISBN();

		// User actions
		void ViewInventory();
		void SellBook();
		void OrderBook();

};

#endif

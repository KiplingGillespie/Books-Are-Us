#makefile
BooksAreUs: main.o
	g++ -o BooksAreUs main.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Interface.o: Interface.cpp Interface.h
	g++ -std=c++11 -c Interface.cpp 
Inventory.o: inventory.cpp inventory.h
	g++ -std=c++11 -c inventory.cpp
Book.o: book.cpp book.h
	g++ -std=c++11 -c book.cpp
	#EndOfFile
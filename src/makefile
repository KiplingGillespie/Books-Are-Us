#makefile
BooksAreUs: main.o
	g++ -o BooksAreUs main.o Interface.o inventory.o book.o 
main.o: main.cpp Interface.o
	g++ -std=c++11 -c main.cpp
Interface.o: Interface.cpp Interface.h inventory.o
	g++ -std=c++11 -c Interface.cpp 
inventory.o: inventory.cpp inventory.h book.o
	g++ -std=c++11 -c inventory.cpp
book.o: book.cpp book.h
	g++ -std=c++11 -c book.cpp	
#EndOfFile

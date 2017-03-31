#include <iostream>
#include <Interface.h>

using namespace std;

void main(){
	
	// Initailize
	InvInterface program = new InvInterface();
	
	// Run 
	program.Run();
	
	// Clearn up
	delete program;
	
	// Exit
	return;
}
#include <iostream>
#include "Interface.h"

using namespace std;

int main(){

	// Initailize
	InvInterface *program = new InvInterface();

	// Run
	program->Run();

	// Clearn up
	delete program;

	// Exit
	return 0;
}

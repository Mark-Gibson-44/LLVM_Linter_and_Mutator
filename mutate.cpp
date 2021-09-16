#include <iostream>

#include "Mutator.h"
#include "parse.cpp"

int main(int argv, char** argc){
	if(argv == 1){
		std::cout << "ERROR: Expected Bitcode Filename Argument\n";
		return 1;
	}
	LLVMContext theContext;
	SMDiagnostic err;
	auto parsed = ParseFile(argc[1], theContext, err);
	if(parsed == nullptr){
		std::cout << "ERROR: Invalid FileName\n";
		return 1;
	}

	
	auto mutate = Mutator(std::move(parsed));
	
	
	/*
	 * Code
	 */
	return 0;
}


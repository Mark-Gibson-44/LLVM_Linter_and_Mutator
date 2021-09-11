#include <iostream>

#include "Linter.h"
#include "parse.cpp"

int main(int argv, char** argc){
	if(argv == 1){
		std::cout << "Expected Bitcode Filename Argument\n";
		return 1;
	}
	auto parsed = ParseFile(argc[1]);
	auto linting = Linter(std::move(parsed));
	
	linting.dumpInfo();
	/*
	 * Code
	 */
	return 0;
}


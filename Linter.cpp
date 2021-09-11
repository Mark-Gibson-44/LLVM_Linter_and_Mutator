#include "Linter.h"

#include <iostream>

#define MAX_ARGS 4

void Linter::lintFunctions(){
	auto funcIter = m->begin();
	while(funcIter != m->end()){
		int argNum = 0;
		auto argIter = funcIter->arg_begin();
		while(argIter != funcIter->arg_end()){
			argNum++;
			argIter++;
		}
		if(argNum > MAX_ARGS)
			std::cout << "Function contains large number of arguments, consider making the function more modular." << std::endl;

		funcIter++;
	}
}

void Linter::dumpInfo(){
	std::cout << "#################" << std::endl;
	std::cout << "General Analysis" << std::endl;
	std::cout << "#################" << std::endl;
	std::cout << "Instruction Count" << m->getInstructionCount(); << std::endl;
	
}

void Linter::tidy(){

}

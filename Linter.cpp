#include "Linter.h"

#include <iostream>

#define MAX_ARGS 4

void Linter::lintFunctions(){
	auto funcIter = M->begin();
	while(funcIter != M->end()){
		std::cout << "Function Name after Mangling: " << funcIter->getGlobalIdentifier() << std::endl;
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
	std::cout << "Instruction Count" << M->getInstructionCount() << std::endl;
	
}

void Linter::tidy(){
	auto funcIter = M->begin();
	while(funcIter != M->end()){
		for(auto& BB: *funcIter){
			for(auto& stmt : BB){
				std::cout << stmt.getOpcodeName() << std::endl;
				if(stmt.isBinaryOp())
					std::cout << "BINOP\n";
				
			}
		}
		funcIter++;
	}
}

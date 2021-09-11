#pragma once
#include <memory>

#include "llvm/IR/Module.h"

class Linter{
	std::unique_ptr<llvm::Module> M;
public:
	Linter(std::unique_ptr<llvm::Module> M) : M(std::move(M)){}
	
	void lintFunctions();//Runs over Functions, Checks Arg number and branches
	void dumpInfo();//Prints General Information for the Module
	void tidy();//WIP

};

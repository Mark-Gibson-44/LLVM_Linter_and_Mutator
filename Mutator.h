#pragma once
#include <memory>

#include "llvm/IR/Module.h"



class Mutator{
	std::unique_ptr<llvm::Module> M;
public:
	Mutator(std::unique_ptr<llvm::Module> M) : M(std::move(M)){}
	
	void mutateBinaryExpr();
	void mutateUnaryExpr();
	void mutateParameterOrder();
	void mutateInstructionOrder();
	
};	

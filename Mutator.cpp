#include "Mutator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Type.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/IRBuilder.h"

#include <iostream>


using namespace llvm;

void Mutator::mutateBinaryExpr(){
	auto funcIter = M->begin();
	std::vector<Instruction*> remove;
	std::vector<BasicBlock*> insert;

	//Iterate over Instructions and record BinOps for manipulation
	while(funcIter != M->end()){
		for(auto& BB: *funcIter){
			for(auto& stmt : BB){
				
				if(stmt.isBinaryOp()){
					
					
					remove.push_back(&stmt);					
					
					
				}
			}
		}
		funcIter++;
	}
	
	std::cout << "Instruction Count Before Removal: " << M->getInstructionCount() << std::endl;
	
	
	for(auto& r: remove){

		
		auto builder = std::make_unique<IRBuilder<>>(r);
		builder->CreateFAdd(r->getOperand(0), r->getOperand(1), "addtmp");
	
		r->eraseFromParent();
	}
	
	std::cout  << "Instruction Count After Removal: " << M->getInstructionCount() << std::endl;

}
void Mutator::mutateUnaryExpr(){
	auto funcIter = M->begin();
	while(funcIter != M->end()){
		for(auto& BB : *funcIter){
			/*if(stmt.isUnaryOp()){

			}*/
		}
	}
}

void Mutator::mutateParameterOrder(){

}

void mutateInstructionOrder(){

}

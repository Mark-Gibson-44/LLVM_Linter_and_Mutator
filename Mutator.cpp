#include "Mutator.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Type.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Value.h"

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
		switch(r->getOpcode()){
			case Instruction::Add:
				builder->CreateSub(r->getOperand(0), r->getOperand(1), "Mutate_neg");
				break;
			case Instruction::Mul:
				builder->CreateUDiv(r->getOperand(0), r->getOperand(1), "Mutate_Mul");
				break;
			case Instruction::Sub:
				builder->CreateAdd(r->getOperand(0), r->getOperand(1), "Mutate_add");
			case Instruction::UDiv:
				builder->CreateMul(r->getOperand(0), r->getOperand(1), "Mutate_Mul");
				
		}
		
	
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

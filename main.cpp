#include <iostream>
#include "base.h"
#include "container.h"
#include "decorator.h"
using namespace std;

int main(int argv, char** argc) {
	Op* op7=new Op(7.2);
	Op* op4=new Op(4);
	Op* op3=new Op(3);
	Op* op2=new Op(2);
	Op* F=new Op(-28.6);
	Mult* A=new Mult(op7, op4);
	Add* B=new Add(op3,A);
	Sub* C=new Sub(B, op2);
	Sqr* D=new Sqr(C);
	Ceil* Cd=new Ceil(F);
	Floor* Fd=new Floor(F);
	Floor* Fe=new Floor(A);
	Absolute* Ad=new Absolute(F);
	Absolute* Ae=new Absolute(Fd);
	Ceil* Ce=new Ceil(Ad);
	std::cout<<Cd->evaluate()<<","<< Ce->evaluate()<<std::endl;
	std::cout<<Fd->evaluate()<<"," <<Fe->evaluate()<<","<<Ad->evaluate()<<","<<Ae->evaluate()<<std::endl;
	
};

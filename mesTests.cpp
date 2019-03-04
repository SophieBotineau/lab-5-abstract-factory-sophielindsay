#include "base.h"
#include "decorator.h"
double ceilling(Node* n)
{
	Ceil* c=new Ceil(n);
	double res=(double)c->evaluate();
	return res;
};

double floor(Node* n)
{
	Floor* f=new Floor(n);
	double res=(double)f->evaluate();
	return res;
};

double absolute(Node* n)
{
	Absolute* a=new Absolute(n);
	double res=(double)a->evaluate();
	return res;
}



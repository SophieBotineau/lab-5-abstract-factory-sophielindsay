#include <math.h>




class Decorateur : public Node {
	protected :
		Node* noeud;

	public:
		Decorateur(Node* n):Node(n, NULL){};
	
		virtual double evaluate()=0;
};

class Ceil: public Decorateur
{
	
	public :
		
		Ceil(Node* noeud):Decorateur(noeud){};

		double evaluate(){
			return ceil(Ceil::leftChild->evaluate());
		};
};
class Floor:public Decorateur
{
	public:
		Floor(Node* noeud):Decorateur(noeud){};
		
		double evaluate(){
			return floor(Floor::leftChild->evaluate());
		};
};

class Absolute:public Decorateur
{
	public:
		Absolute(Node* noeud):Decorateur(noeud){};

		double evaluate(){
			return abs(Absolute::leftChild->evaluate());
		};
};
			

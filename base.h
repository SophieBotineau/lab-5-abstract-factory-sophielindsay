
class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
};

class Node : public Base {
	protected:
		    Base* leftChild;
		    Base* rightChild;
	public:
			Node() : Base(){
				    this->leftChild = NULL;
				    this->rightChild = NULL;
			};
			Node(Base* lc, Base* rc) : Base(){		
				this->leftChild = lc;
				this->rightChild = rc;
			}
};

class Sqr : public Node{
	public:
		/* Constructors */            
		Sqr(Node* Child):Node(Child, NULL) {};	            
		/* Pure Virtual Functions */	          
	      	double evaluate() {
			return Sqr::leftChild->evaluate() * Sqr::leftChild->evaluate();	
		};
};

class Add : public Node{
	public:
		Add(Node* child1, Node* child2) : Node(child1, child2){};
		double evaluate(){
			return Add::leftChild->evaluate() + Add::rightChild->evaluate();
		}
};

class Sub : public Node{
	public:
		Sub(Node* child1, Node* child2) : Node(child1, child2) {};
		double evaluate(){
			return Sub::leftChild->evaluate() - Sub::rightChild->evaluate();
		}
};

class Div : public Node{
	public: 
		Div(Node* child1, Node* child2) : Node(child1, child2) {};
		double evaluate() {
			return Div::leftChild->evaluate() / Div::rightChild->evaluate();
		}
};

class Mult : public Node{
	public:
		Mult(Node* child1, Node* child2) : Node(child1, child2) {};
		double evaluate() {
			return Mult::leftChild->evaluate() * Mult::rightChild->evaluate();
		}
};

class Op : public Node{
	protected: 
		double value;
	public:
		Op(double val) : Node(NULL,NULL)
	{
		this->value = val;
	}
		double evaluate(){
			return value;
		}
};


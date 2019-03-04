#include <list>
#include <vector>
#include <iostream>


class Base; 
class BasePrint;
class BaseFactory;
class Container;
class Sort {
	public:
		Sort(){};
		virtual void sort(Container* container) = 0;
};

class Container {
    protected:
        Sort* sort_function;
	BaseFactory* print_function;

    public:
	    /* Constructors */
        Container() : sort_function(NULL){this->print_function = NULL;};
        Container(Sort* function, BaseFactory* f) : sort_function(function) {this->print_function = f;};

        /* Non Virtual Functions */
        void set_sort_function(Sort* sort_function){
		this->sort_function = sort_function;
	}; // set the type of sorting algorithm

	void set_print(BaseFactory* print_f)
	{
		this->print_function = print_f;
	};
        /* Pure Virtual Functions */
	    // push the top pointer of the tree into container
        virtual void add_element(Base* element) = 0;
        // iterate through trees and output values
	//
	
        virtual void print() = 0;
        // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
        virtual void sort() = 0;

        /* Essentially the only functions needed to sort */
        //switch tree locations
        virtual void swap(int i, int j) = 0;
        // get top ptr of tree at index i
        virtual Base* at(int i) = 0;
        // return container size
        virtual int size() = 0;
};


class bubbleSort;
class selectionSort;

class VectorContainer : public Container
{
	protected: 
		std::vector<Base*> vectorTree;
	public:
		VectorContainer():Container()
		{
			this->vectorTree = {};	
		};
		VectorContainer(Sort* function):Container(function, NULL)
		{
			this->vectorTree = {};
		};
		VectorContainer(Sort* function, std::vector<Base*> vtree):Container(function, NULL)
		{
	      		 this->vectorTree = vtree;
		};

		void add_element(Base* element) { 
			vectorTree.push_back(element); 
		};
//switch tree locations
	 	void swap(int i, int j) 
		{
			Base* a = this->vectorTree[i];		
			this->vectorTree[i] = this->vectorTree[j];        						
			this->vectorTree[j] = a;
		};
		Base* at(int i) 
		{
			return this->vectorTree[i];
		};
		// return container size	         
		int size() 
		{ 
			return vectorTree.size();
	       	};	
		void print() {
		
			/*for (int i=0; i<this->vectorTree.size(); i++){
			
				std::cout<<this->vectorTree[i]->evaluate()<<std::endl;

			}*/
				for (int i=0; i<this->vectorTree.size(); i++){
				double r = this->vectorTree[i]->evaluate();
				
				((this->print_function)->generatePrint(r))->print();
			}
		};
		void sort(){
			this->sort_function->sort(this);	
		};		
};


class selectionSort : public Sort {
	public:			
		selectionSort():Sort(){};			
		void sort(Container* container) 
		{									
			for( int i = 0 ; i < container->size(); i++)
			{																
				int min = i;
				for(int j = i+1; j< container->size() ; j++)
				{					
					if(container->at(j)->evaluate() < container->at(min)->evaluate())								
					{
						min = j;
					}
				}
				if(min != i)
				{
					container->swap(i,min);
				}
			}
		};
};

class bubbleSort : public Sort {
	public:
		bubbleSort():Sort(){};
		void sort(Container* container){
		
			for( int i = container->size() - 1 ; i >= 0; i--)
			{
				for(int j = 0; j< i-1 ; j++)
				{
					if(container->at(j+1)->evaluate() < container->at(j)->evaluate())
					{
						container->swap(j,j+1);
					}
				}
			}
		};
};

class ListContainer : public Container {
	protected:
		std::list<Base*> listTree;
	public:
		ListContainer():Container(){};
		ListContainer(Sort* function):Container(function, NULL){};
		ListContainer(Sort* function, std::list<Base*> lt):Container(function, NULL){
			this->listTree = lt;
		}
	void add_element(Base* element) { listTree.push_back(element); };
	Base* at(int i) {
		std::list<Base*> copy;
	    	copy.assign(this->listTree.begin(), this->listTree.end());
		for (int j = 0; j < i; j++) {
			copy.pop_front();
		}
		return copy.front();
	};
	//switch tree locations
        void swap(int i, int j) {
		std::list<Base*>::iterator element_i = std::next(this->listTree.begin(), i);
		std::list<Base*>::iterator element_j = std::next(this->listTree.begin(), j);
		int k = 0;
	 	std::list<Base*> copy;	
		while(k!=this->listTree.size()){
			if(k==j)
			{
				copy.push_back(*element_i);
				k++;
			}
			if(k==i)
			{
				copy.push_back(*element_j);
				k++;
			}
			else
			{
				std::list<Base*>::iterator it = std::next(this->listTree.begin(), k);
				copy.push_back(*it);
				k++;
			}
		}
		this->listTree.assign(copy.begin(), copy.end());		
	};						        			  
	// return container size
	int size() { return this->listTree.size(); };
	void print() {
		for(int i=0; i<this->listTree.size(); i++){
			std::list<Base*>::iterator it = std::next(this->listTree.begin(), i);
			std::cout<<(*it)->evaluate()<<std::endl;
		}
	};
	void sort(){};
	
};


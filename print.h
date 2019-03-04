#include <iostream>
#include <bitset>
class BasePrint {        
	protected:		
		double value;		
	public:			
		BasePrint();	
		BasePrint(double value)
		{	
			this->value = value;		
		};		
		virtual void print() = 0;
};

class DoublePrint : public BasePrint {
	        public:		
			DoublePrint();		
			DoublePrint(double value) : BasePrint(value){};					               
		       	void print() {								
				std::cout << this->value << std::endl;				
			};
};

class SciPrint : public BasePrint {
	        public:	               
		       	SciPrint();		
			SciPrint(double value) : BasePrint(value){};
							            
		    	void print() {		
				std::cout << std::scientific << this->value << std::endl;				
				std::cout << std::defaultfloat;
			};
};

class BinaryPrint : public BasePrint {
	public:
		BinaryPrint();
		BinaryPrint(double value) : BasePrint(value){};

		void print() {
			std::bitset<16> val (this->value);
			std::cout << val << std::endl;
		};
};

class BaseFactory {
	public:
		BaseFactory(){};
		virtual BasePrint* generatePrint(double value) =0;
};

class DoubleFactory : public BaseFactory {
	public:
		DoubleFactory():BaseFactory(){};
		DoublePrint* generatePrint(double value) {
			DoublePrint* dp = new DoublePrint(value);
			return dp;
		};
};

class SciFactory : public BaseFactory {
	public:
		SciFactory():BaseFactory(){};
		SciPrint* generatePrint(double value){
			SciPrint* hp = new SciPrint(value);
			return hp;
		};
};

class BinaryFactory : public BaseFactory {
	public:
		BinaryFactory():BaseFactory(){};
		BinaryPrint* generatePrint(double value) {
			BinaryPrint* bp = new BinaryPrint(value);
			return bp;
		};
};

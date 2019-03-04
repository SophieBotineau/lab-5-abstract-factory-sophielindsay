#include <string>
#include "print.h"
#include "gtest/gtest.h"
#include "mesTests.cpp"
#include "oldcontainer.h"
/*Op* O1=new Op(17.35);
Op* O2= new Op(45.2);
Op* O3=new Op(-25.45);
Op* O4=new Op(-6.0);
Absolute* A1=new Absolute(O3);
Ceil* C1=new Ceil(O3);
Floor* F1=new Floor(O3);
TEST(CeillingTest, PositiveCeil)
{
	ASSERT_EQ(18, ceilling(O1));
	ASSERT_EQ(46, ceilling(O2));
};
TEST(CeillingTest, NegativeCeil)
{
	ASSERT_EQ(-25, ceilling(O3));
	ASSERT_EQ(-6, ceilling(O4));
};
TEST(FloorTest, PositiveFloor)
{
	ASSERT_EQ(17, floor(O1));
	ASSERT_EQ(45,floor(O2));
};
TEST(FloorTest, NegativeFloor)
{
	ASSERT_EQ(-26, floor(O3));
	ASSERT_EQ(-6,floor(O4));
};
TEST(AbsoluteTest, PositiveAbs)
{
	ASSERT_EQ(17.35, absolute(O1));
	ASSERT_EQ(45.2,absolute(O2));
};
TEST(AbsoluteTest, NegativeAbs)
{
	ASSERT_EQ(25.45, absolute(O3));
	ASSERT_EQ(6.0, absolute(O4));
};
TEST(Combination, AbsCeil)
{
	ASSERT_EQ(26,ceilling(A1));
	ASSERT_EQ(25, absolute(C1));
};
TEST(Combination, AbsFloor)
{
	ASSERT_EQ(25, floor(A1));
	ASSERT_EQ(26, absolute(F1));
};
TEST(Combination, CeilFloor)
{
	ASSERT_EQ(-25, floor(C1));
	ASSERT_EQ(-26, ceilling(F1));
};
*/
TEST(doubleprint, DoubleTest)
{
	DoublePrint* DP=new DoublePrint(12.1);
	testing::internal::CaptureStdout();
	DP->print();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ("12.1\n",output);
};

TEST(sciprint, SciTest)
{
	SciPrint* HP = new SciPrint(12.1);
	testing::internal::CaptureStdout();
	HP->print();
	std::string output = testing::internal::GetCapturedStdout();
	testing::internal::CaptureStdout();
	std::cout << std::scientific << 12.1 << "\n";
	std::string t = testing::internal::GetCapturedStdout();
	std::cout << std::defaultfloat;
	ASSERT_EQ(t, output);
}

TEST(binaryprint, BinaryTest)
{
	BinaryPrint* BP = new BinaryPrint(12.1);
	testing::internal::CaptureStdout(); 
	BP->print(); 
	std::string output = testing::internal::GetCapturedStdout(); 
	std::bitset<16> t (12.1); 
	std::string t2 = t.to_string() + std::string("\n");
	ASSERT_EQ(t2, output);
}

TEST(doublefactory, BFTest)
{
	DoubleFactory* DF = new DoubleFactory();
	DoublePrint* DP = DF->generatePrint(12.1);
	testing::internal::CaptureStdout(); 
	DP->print(); 
	std::string outpu2t = testing::internal::GetCapturedStdout();
	ASSERT_EQ("12.1\n", outpu2t);
}

TEST(scifactory, SFTest)
{ 
	SciFactory* HF = new SciFactory();
	SciPrint* HP = HF->generatePrint(12.1);
	testing::internal::CaptureStdout(); 
	HP->print(); 
	std::string output = testing::internal::GetCapturedStdout(); 
	testing::internal::CaptureStdout(); 
	std::cout << std::scientific << 12.1 << "\n"; 
	std::string t = testing::internal::GetCapturedStdout(); 
	std::cout << std::defaultfloat; 
	ASSERT_EQ(t, output);
}

TEST(binaryfactory, BinaryTest)
{ 
	BinaryFactory* BF = new BinaryFactory();
	BinaryPrint* BP = BF->generatePrint(12.1); 
	testing::internal::CaptureStdout(); 
	BP->print(); 
	std::string output = testing::internal::GetCapturedStdout(); 
	std::bitset<16> t (12.1);
	std::string t2 = t.to_string() + std::string("\n"); 
	ASSERT_EQ(t2, output);
}
TEST(vectorprint, VPTest)
{
	Op* op7=new Op(7);
	Op* op4=new Op(4);
	Op* op3=new Op(3);
	Op* op2=new Op(2);
	Mult* A=new Mult(op7, op4);
	Add* B=new Add(op3,A);
	Sub* C=new Sub(B, op2);
	Sqr* D=new Sqr(C);
	VectorContainer* container = new VectorContainer();
	container->add_element(A);
	container->add_element(B);
	container->add_element(C);
	container->add_element(D);
	DoubleFactory* BF = new DoubleFactory();
	container->set_print(BF);
	testing::internal::CaptureStdout();
	container->print();	        
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ("28\n31\n29\n841\n", output);

}



int main(int argc, char **argv) {
	  ::testing::InitGoogleTest(&argc, argv);
	    return RUN_ALL_TESTS();
}

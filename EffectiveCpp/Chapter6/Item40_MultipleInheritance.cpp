#include "StdAfx.h"
#include "gtest/gtest.h"

class MultipleInheritance : public ::testing::Test
{};


class BorrowableItem {
public:
	void checkOut() {
		std::cout << "BorrowableItem::checkOut" << std::endl;
	}
};


class ElectronicGadget {
private:
	bool checkOut() 	{
		std::cout << "ElectronicGadget::checkOut" << std::endl;
	}
};

class Mp3Player :
	public BorrowableItem,
	public ElectronicGadget
{};



TEST_F(MultipleInheritance, To_resolve_ambiguity_you_have_to_explicit_specify_which_base_class_s_function_to_call)
{
	Mp3Player mp;
	mp.BorrowableItem::checkOut();
	// mp.checkOut(); //  error C2385: ambiguous access of 'checkOut'
	// mp.ElectronicGadget::checkOut(); // cannot access private member declared in class 'ElectronicGadget'
}
// Jake Stocker
// Test file for stringLength
//



#include "string.hpp"
#include <cassert>

int main()
{

	{
	//-----------------------------------
	//  SETUP FIXTURE
	
	//  TEST
	String str;

	//  VERIFY
	assert(str.length() == 0);
	}

	{

	//  SETUP
	String str("a");

	// Verify
	//assert(str.length() == 1);
	assert (str.length() == 1);
	}

	{

	//  Test
	String str("this is a test phrase");

	// Verify
	assert(str.length() == 21);
	}

	std::cout<<"All string length asserts have passed"<<std::endl;
}	

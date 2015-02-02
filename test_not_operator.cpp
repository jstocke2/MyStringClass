// Jake Stocker
//
//
// Test file for not operator
//



#include "string.hpp"
#include <cassert>
#include <iostream>

int main(){

	{

	// Setup Fixture
	String str1("a"), str2;

	// Verify
	assert(str1 != str2);


	}

	{
	// Setup Fixture
	String str1("abcd"), str2("abcdefgh");
	// Verify
	assert(str1 != str2);



	}

	{
	// Setup fixture
	String str1("abc"), str2("abc");

	// Verify
	assert (!(str1 != str2));






	}

	std::cout << "All not operators have passed asserts"<<std::endl;
}

//  Jake Stocker
//
//  Test file for default char array constructor
//  --------------------------------------------------
#include "string.hpp"
#include <cassert>
#include <iostream>


int main()
{
	{

	//-------------------------------------------------
	//  SETUP FIXTURE
	
	// TEST
	String str('a');
		
	// Verify
	assert(str == "a");
	assert(str.capacity() == DEFAULT_STRING_CAPACITY);
	}

	{
	// TEST
	String str("browns");


	assert(str == "browns");
	}

	std::cout << "Done testing c_string construction."<<std::endl;

}

	

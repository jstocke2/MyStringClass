// Jake Stocker
//
//
// Tests findstr method of class String


#include "string.hpp"
#include <iostream>
#include <cassert>


int main(){

	{

	// Setup fixture
	String str1("this is a test phrase");
	String str2("is");
	String str3("this");
	// Test fixture
	assert (str1.findstr(str2)== 2 );
	assert (str1.findstr(str3)==1);

	}
	
	
	{


	// Setup fixture
	String str1("abc");
	String str2("bc");
	

	// Test fixture
	assert(str1.findstr(str2)== 1);

	}

	{

	// Setup fixture

	// Test fixture
	std::cout << "Done testing findstr method all asserts passed"<<std::endl;

	}
}

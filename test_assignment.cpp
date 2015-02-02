// Test file for assignment operator
// Jake Stocker
//
//


#include "string.hpp"
#include <cassert>


int main(){
	{

	String str1("abcdef"),str2;
	str2=str1;
	assert("abcdef"==str2);

	}
	{

	char str1[100]= "Testing";
	String str2=str1;

	assert("Testing"==str2);
	}

	
	std::cout<<"Done testing assignment operator"<<std::endl;








}

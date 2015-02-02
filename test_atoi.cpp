// Test file for atoi.cpp
//
//
//Jake Stocker
//



#include "string.hpp"
#include <cassert>



int main(){



	// Create fixture
	int number, number1, number2;

	// test
	number= atoi("0");
	number1= atoi("1");
	number2 = atoi ("54321");



	// verify
	assert(number == 0);
	assert(number1 == 1);
	assert(number2 == 54321);




	std:: cout<< "All atoi tests have passed\n";



}

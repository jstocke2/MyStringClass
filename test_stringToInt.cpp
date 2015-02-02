// Test file for atoi.cpp
//
//
//Jake Stocker
//



#include "string.hpp"
#include <cassert>



int main(){



	// Create fixture
	int number, number1, number2, number3;

	// test
	number= stringtoInt("0");
	number1= stringtoInt("1");
	number2 = stringtoInt("54321");
	number3 = stringtoInt("20");


	// verify
	assert(number == 0);
	assert(number1 == 1);
	assert(number3 == 20);
	assert(number2 == 54321);




	std:: cout<< "All stringtoInt tests have passed\n";



}

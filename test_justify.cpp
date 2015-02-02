// Jake Stocker
//
// Test justify.cpp
// 
//


#include "string.hpp"
#include <cassert>


int main() {

	//create fixture

	String str1("one two three");
	String result;
	result=str1.justify(15);
	String str2("bad ass ");
	String result2 = str2.justify(13);
	// Test
	assert(result == "one  two  three");
	assert(result2 == "bad    ass   ");

	std::cout<<"All justify tests have passed"<<std::endl;
}

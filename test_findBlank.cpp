// Test file for findBlank
// Jake Stocker
//



#include "string.hpp"
#include <cassert>



int main(){

	{	
	// Setup Fixture
	String str("This is a test");
	

	// Test 
	assert(str.findBlank(3)==4);
	assert(str.findBlank(8)==9);
	assert(str.findBlank(13)==-1);






	}


	std::cout<<"All findBlank(int) method tests have passed"<<std::endl;
}

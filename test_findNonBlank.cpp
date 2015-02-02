// findNonBlank(int) method test
//
// Jake Stocker
//
//


#include "string.hpp"
#include <cassert>



int main(){

{

	// Create Fixture
	String str("   tu abuelo estuve excelente en la cama");

	
	// Test and Verify
	assert(str.findNonBlank(0)==3);
	assert(str.findNonBlank(5)==6);
	assert(str.findNonBlank(8)==8);




	std::cout<<"Finished testing findNonBlank(int) method"<<std::endl;







}











}

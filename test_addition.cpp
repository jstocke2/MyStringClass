// Jake Stocker
//
//
// Test file for string cacatenation
#include "string.hpp"
#include <cassert>
#include <ostream>
using std::cout;
using std::cerr;

int main()
{
	{
		// Setup fixture
		String str1, str2, result;

		// Test
		result = str1 + str2;


		// Verify
		assert(str1 == "\0");
		assert(str2 == "\0");
		assert(result == "\0");
	}

	{
		// Setup Fixture
		String str1, str2('a'), result;
		assert(str2=="a");
		// Test
		result=str1+str2;

		// Verify
		assert(str1 == "\0");
		assert(str2 == 'a');
		assert(result=='a');
		std::cout<< "Testing addition"<<std::endl;

	}
	{

		// Setup Fixture
		String str1("abc"), str2("zxy"), result;

		// Test
		result= str1+ str2;

		// Verify
		assert(result=="abczxy");
				

	}
	std::cout << "Done testing addition" <<std::endl;
}

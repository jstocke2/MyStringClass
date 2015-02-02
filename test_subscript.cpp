//  Jake Stocker
//
//  Testfile for subscript operator of string
//

#include "string.hpp"

#include <cassert>

int main() {
	{

	// Setup fixture
	String str1("abcde");

	// Test fixture
	assert(str1[1] == 'b');

	}

	{

	// Setup fixture
	String str1("a");

	// Test fixure
	assert(str1[0] == 'a');	

	}

	std::cout << "Subscript operator tests have passed\n";

}

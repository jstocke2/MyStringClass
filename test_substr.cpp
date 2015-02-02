// Jake Stocker
//
// Tests substr Method

#include "string.hpp"
#include <cassert>

	int main()
{
	{

		// Setup
		String str1 = "abcdefghijk",
			result1,
			result2, result3,
			result4;

		// Test
		result1 = str1.substr(0,10);
		result2 = str1.substr(1,10);
		result3 = str1.substr(0,3);
		result4 = str1.substr(1,10);

		// Verify
		assert(str1 == "abcdefghijk");
		assert(result1 == "abcdefghijk");
		assert(result2 == "bcdefghijk");
		assert(result3 == "abcd");
		assert(result4 == "bcdefghijk");


		// Setup
		String str = "Test String";

		// Test & verify
		assert(str.substr(0,4) == "Test ");
		assert(str.substr(5,7) == "Str");
	

		std::cout<<"All substr tests have passed\n";
	}
}

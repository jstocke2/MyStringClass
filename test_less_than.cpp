// Jake Stocker
//
// Test program
//

#include "string.hpp"
#include <cassert>

int main()
{
	{
		//Setup
		String str1="a", str2="ab";

		// Test 
		assert(str1 < str2);
	}

	{
		// Setup
		String str2 = "a", str1 = "x";

		// Test
		assert(str1 < str2);

	}

	{

		// Setup
		String str2 = "zz";
		String str1 = "a";

		// Test
		assert(str2 < str1);
	}

	{

		// Setup
		String str2 = "aaz";
		String str1 = "aaa";

		// Test
		assert(str2 < str1);

	}

		// Setup
		String str2 = "aaa";
		String str1 = "aaa";

		// Test
		assert(!(str2<str1));

	std::cout << "Done testing greater than operator" <<std::endl;
}

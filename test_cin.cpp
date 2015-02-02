// Jake Stocker

// Test file for cin

#include "string.hpp"
#include <iostream>

using std::endl;
using std::cout;
using std::cerr;
int main(){

	{

	// Setup Fixture
	
	String str1;
	cout << "Enter a string with no spaces"<<endl;
	std::cin >> str1;

	// Verify
	cout << endl;
	cout << "You entered ";
	cout<<endl;
	cerr << str1;
	cout << endl;

	cout << "If Input string and Output string match input has passed"
	<< endl;
	}
}

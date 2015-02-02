// Jake Stocker
// input stream test
//



#include "string.hpp"
#include <fstream>



int main(){

	std::ifstream in;

	in.open("input.txt");
	String words;
	in >> words;
	std::cout <<"TESTING FILE STREAM\n";
	std::cout << words;

	if (!in){

		std::cerr << "could not read file";


	}



	in.close();








}

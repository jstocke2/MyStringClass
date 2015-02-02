// Justify.cpp's file
//
// Jake Stocker

#include "string.hpp"
#include <fstream>

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//FUNCTION HEADERS FOR LOCAL FUNCTIONS

String justifyFile(std::ifstream&,  int, int);
String insertSpaces(int);
void help();
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



int main(int argc, char const* argv[]){


	// proper number of input values if less than 4 error
	if (argc < 4) {
		std::cerr << "there is an error the argument is greater than 4 " << std::endl;
		help();
	}

	// use input file
	std::ifstream in;
	in.open (argv[3]);

	if (!in){
		std::cerr << "can't open" << argv[3] << "Try again" << std::endl;
		help();
	}


	int left = stringtoInt(argv[1]);
	int right = stringtoInt(argv[2]);


	// check the range
	if(left < 0 ||right > 99 || left >= right) {
		std::cerr <<"L R range was outside of bounds" <<std::endl;
		help();

	}


	//Justify
	String result = justifyFile(in, left, right);

	// if output file isn't specified output to console
	if (argc == 4) {
		std::cout << result<< std::endl;
	// if output specified output to console
	}else if (argc == 5) {
		std::ofstream out;
		out.open(argv[4]);

	if (!out) {
		std::cerr << "There is an error!" << argv[4] << "Try again" << std::endl;
		help();
	}
	

	out << result;
	out.close();
	}

	in.close();

	return 0;
	
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//LOCAL FUNCTION DEFINITION




//  Precondition: takes a file to write in from a left spacing and right spacing
//  Postcondition:  Returns a String containing entire file of text spaced accordingly to left and right parameters

String justifyFile(std::ifstream& in, int left, int right) {

	char word[200];

	String result;

	int width = right - left + 1;  //  specified method of creating indentation

	String currentLine, currentWord;

	while (!in.eof()) {
		in >> word;
		// converts the character array to a string
		currentWord = String(word);

		if (in.eof()) {
			break;
		}

		if(currentWord.length() + currentLine.length() + 1 <= width) {  // adds up Word and line and compares them to width
			if (currentLine == ""){
				currentLine = currentWord;      // If currentLine empty assign currentWord
			}else{
				currentLine =currentLine + ' ';
				currentLine = currentLine +currentWord;      // otherwise give a space to currentLine and add the currentWord
			}
			}else{
				currentLine = currentLine.justify(width);   // calls justify on line with dervied width
				result = result+ insertSpaces(left);        // insert spaces into result string from left margin amt specified
				result = result+currentLine;                //  adds currentline now that its justified to result with its left margin
				result = result+ '\n';                      // adds a blank line at the end of result
				currentLine = currentWord;                 //  currentline is reset to currentWord value so next word may be read in

			}
		}

		return result;
	}

String insertSpaces(int x)           // inserts spaces into left margin x times
{
	String result;

	for (int i = 0; i < x; ++i) {
		result = result + ' ';
	}

	return result;

}

void help()   // brings up help menu of required parameters to be input from CLI
{
	std::cout << "Usage: " << std::endl;

	std::cout << "\t.justify [left] [right] [input] [output]" << std::endl;
	std::cout<< "\tleft: integer value of the left offset." << std::endl;
	std::cout << "\tright: integer value of the right offset." <<std::endl;
	std::cout << "\tinput: file of text to be justified. " <<std::endl;
	std::cout<< "\toutput: optional file where justified text will be written.  If not specified text will exit(1)";
}
	






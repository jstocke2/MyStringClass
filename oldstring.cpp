// Jake Stocker
// string.cpp
// Contains the class definitions for the string class
//
//
//

#ifndef STRING_CPP
#define STRING_CPP


#include "string.hpp"

// Default constructor for String
// PRECONDITION:  Constructor takes an int for size of array otherwise set to CONST defined in .hpp
// POSTCONDTION:  Creates dyanamically allocated array strLength to zero and creates empty array

String::String(const int size){
	capacity = size;
	strLength=0;
	s= new char[capacity];
	s[0] = '\0';
	
}
/*
String::String(char x){
	capacity=MAX_SIZE;
	strLength=1;
	s= new char[capacity];
	s[0] = x;
	s[1] = '\0';

}
*/

// Default constructor for String
// PRECONDTION:  Constructor takes a char and an int to define size of array other than default
// POSCONDTION:  Creates empty array with null character char is put at 0 index of array
String::String(const char x, const int size){

	capacity = size;
	s = new char[capacity];
	strLength=1;
	s[0]=x;
	s[1]='\0';

}
//  Default constructor for String
//  PRECONDITION:  Constructor teakes char array and an int defining size of an entire array
//  POSTCONDITION: Creates a new dynamically allocated string array with null character containing char array
//  if array capacity is found to be more than what is allocated constructor automatically allocates more array space


String::String(const char x[], const int size){
	capacity = size;
	s = new char[capacity];

	do {
		int i = 0;

		for (; x[i]!= '\0'; ++i){

			s[i]=x[i];
			

		}	
		strLength=i;

		if (capacity < strLength) {
			delete [] s;
			capacity *=2;
			s = new char [capacity];
			strLength = capacity;

		}

	} while (capacity < strLength);

	s[strLength] = '\0';

}



// Comparison operator for 2 Strings




String String::operator= (String rhs){
	
	pointerSwap(rhs);


	return *this;



}

//  Deconstructor for String destroys dynamic array priavte member variable
	
String::~String(){
	strLength=0;
	delete [] s;



}

//  Swap member method
//  PRECONDITION:  takes a String
//  POSTCONDITION: swaps lhs pointer and rhs array pointers

void String::pointerSwap(String& rhs){
	char *temp = s;
	s=rhs.s;
	rhs.s=temp;

}
// Copy Constructor for String
// Creates a new array for string to use in function calls


String::String(const String& str, const int cap)
{
	if (cap <= str.strLength)
		capacity= str.strLength + 1;
	else
		capacity=cap;

	s = new char[capacity];

	do {
		int i = 0;

		for (; str[i] != '\0'; ++i) {
			s[i] = str[i];
		}

		strLength = i;

	}while (capacity < strLength);

	s[strLength] = '\0';

}

/*	
bool operator== (const char x[], const String& z){
	int size=0;
	for (int i=0; x[i] != '\0'; ++i){
		size=i;


	}

	if (!(size == strLength)){
		return false;
		}

	else {

		for (int i=0; i<size;++i){
			if (x[i]!=z[i]){
				return false;
			}
		}
		return true;
	}
}


bool operator== (char x, const String& z){
	int size=0;
	for (int i=0; z[i] != '\0'; ++i) {
		size=i;


	}
	
	if (size > 1) {
		return false;
	}
	
	else {
		if (char x == z[0]){
			return true;
		}
	return false;
	}
}
*/

// Comparision operator for String

bool String::operator == (const String& rhs) const
{
	if (strLength==rhs.strLength){

		for (int i = 0; s[i] != '\0' && rhs[i] != '\0'; ++i) {
			if (s[i] != rhs[i]) {
				return false;
			}
		}
		return true;
	}

	return false;
}

// input stream operator for String

std::istream& operator>>(std::istream& in, const String& str)
{
	in >> str.s;
	return in;
}

// Less than operator for string
//
bool String::operator< (const String& rhs) const
{
	bool lessThan = false;
	int i = 0;

	for (; (s[i] != '\0') && (rhs[i] != '\0'); ++i){
		if (s[i] > rhs[i]) return false;
	if (s[i] < rhs[i]) lessThan = true;
	}

	if (lessThan && (s[i] == '\0') && (rhs[i] == '\0')) return true;
	if (lessThan && (rhs[i] == '\0')) return true;
	if (!lessThan && (s[i] == '\0') && (rhs[i] == '\0')) return false;
	if (s[i] == '\0') return true;
	return false;
}

// Concatenation of Strings

String String::operator + (const String& rhs) const
{
	int i = strLength;
	String result(*this, i + rhs.strLength + 1);

	for (int j = 0; rhs[j] != '\0'; ++i, ++j){
		result[i] = rhs[j];
	}
	
	result.strLength = i, result[i] = '\0';
	return result;
}

std::ostream& operator << (std::ostream& out, const String& str)
{	
	
	out << str.s;
	return out;
}

/*int String::findstr(const String& find) const {
	int falseMatches=0;
	int times=0;
	int match=0;
	
	// Make consecutive matches ==1 if it gets through j than set condition true
	if (strLength >= find.strLength) {

		for (int i =0; i < strLength; ++i) {
			
			for (int j=0; j < find.strLength; ++j){
				if (s[i]==s[j]){
					++match;
					
					falseMatches=0;
	
				}
				if (s[i] != s[j]){
					++falseMatches;	
				}
				if (falseMatches==(find.strLength*find.strLength)){
					
					match=0;
					falseMatches=0;
				}
				if (match==find.strLength){
					++times;
					match=0;
					falseMatches=0;	
				}
				
					
		
			}
		}		
	return times;
	}
	else 
	return 0;
}*/

//  findstring method
//  PRECONDITION: takes a String
//  POSTCONDITION:  searches lhs string for occurances of rhs string returns an int of the first occurance

int String::findstr(const String& find) const {
	int times=0;

	if (strLength>= find.strLength) {
		for (int i = 0, j=0;  i < strLength; ++i, j = 0){
			while (s[i + j] == find.s[j] && j <= find.strLength) {
				++j;

				if (j == find.strLength) {
					++times;
					i= i + j;
				}
			}
		}
	}

	return times;

}
// findchar method
// PRECONDTION:  takes a character and an int of starting index of array
// POSTCONDITION:  returns an int of the index containing the char in the String array
int String::findchar(const char ch, const int start) const
{

	String temp = substr(start );
	int first_index = -1;

	for (int i = 0; i < strLength; ++i) {
		if (temp[i] == ch) {
			return first_index = i + start;
		}
	}

	return first_index;

}
// subtraction operator
// PRECONDITION: takes a const char
// POSTCONDITION:  return a String without the subtracted char
String String::operator - (const char x) {

	String result(strLength + 1);

	for (int i= 0; i < strLength; ++i) {
		if (s[i] != x) {
			result = result + s[i];
		}
	}
	return result;

}
// subtraction operator
// PRECONDITION:  takes a const int
// POSTCONDITION: returns a string with the last int gone of whatever operator the user specifies
String String::operator - (const int x) {
	if (x <= 0) {
		return *this;
	} else if (x >= strLength) {
		String result;
		return result;
	} 
	  else {
		String result(strLength - (x+1));

		for (int i = 0; i <(strLength - x); ++i) {
			result = result+ s[i];
		}
		return result;

	}
}
String String::operator *(const int x) const{
	if (x <= 0) {
		String result;
		return result;
	}  else if (x == 1) {
		return *this;
	} else {
		String result(*this, (strLength *x) +1);

		for (int i =1; i <x; ++i) {
			result = result+ *this;
		}

		return result;

	}
}
// subtraction operator
// PRECONDTION:  takes a string
// POSTCONDITION: returns a sting without rhs indices
String String::operator - (const String& rhs){
	String result(strLength + 1);
	int i = 0;

	for (int j = 0; i < strLength; ++i, j = 0) {
		while (s[i + j] == rhs.s[j] && j <= rhs.strLength) {
			++j;

			if (j == rhs.strLength) {
				i = i +j;
			}
		}
		result = result+ s[i];
	}
	return result;
}
// substring method
// PRECONDTION: takes 2 ints 
// POSTCONDTION:  returns a string found between indices of String user calls on
String String::substr(const int left, int right) const {

	if (right < 0 ||  right >strLength) {
		right = strLength;
	}

	if (left == 0) {
		String result = *this;
		return result - (strLength - right);
	} 
	else {
		String result(strLength+ 1);

		for (int i = left; i < right +1; ++i) {
			result =result + s[i];
		}
		return result;
	}
}
#endif

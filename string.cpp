// Jake Stocker
// string.cpp
// Contains the class definitions for the string class
//
//
//

#ifndef STRING_CPP
#define STRING_CPP

#include <cassert>
#include "string.hpp"

// Default constructor for String
// PRECONDITION:  Constructor takes an int for size of array otherwise set to CONST defined in .hpp
// POSTCONDTION:  Creates dyanamically allocated array strLength to zero and creates empty array

String::String(){
	Capacity = DEFAULT_STRING_CAPACITY;
	s= new char[DEFAULT_STRING_CAPACITY];
	s[0] = '\0';
	
}

// Default constructor for String
// PRECONDTION:  Constructor takes a char and an int to define size of array other than default
// POSCONDTION:  Creates empty array with null character char is put at 0 index of array
String::String(int size, const char* x){
	Capacity = size;
	int i=0;
	s=new char[size];
	for (; x[i] != '\0'; ++i){
		s[i]=x[i];
	}
	s[i] = '\0';
}
// string constructor with cap set to int specfied
String::String(int cap){
	Capacity=cap;
	s= new char[cap];
	s[0]='\0';
}
// char pointer string constructor
String::String(const char* x){
	Capacity= DEFAULT_STRING_CAPACITY;
	int i = 0;
	s= new char [DEFAULT_STRING_CAPACITY];
	for (; x[i] != '\0'; ++i){
		s[i]=x[i];
	}
	s[i] = '\0';
}
// char string constructor
String::String(char x){
	Capacity = DEFAULT_STRING_CAPACITY;
	s = new char[DEFAULT_STRING_CAPACITY];
	s[0] = x;
	s[1] = '\0';
}

String& String::operator= (char* x){
	s=x;
	return *this;
}
/*1
char* String::operator= (String rhs){
	return s;
}
*/
// Assignment operator for 2 Strings


String& String::operator= (String rhs){
	
	swap(rhs);
	return *this;

}
/*
String& String::operator= (int rhs){
	String *tmp=new String;
	*tmp= rhs-'0';
	return *tmp;
}
*/

void reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;

	while (start<end)
	{
		std::swap(*(str+start),*(str+end));
		start++;
		end--;
	}
}







char* itoa(int num,char* str, int base){
	//tmp= new String;
	
	
	int i = 0;
	bool isNegative=false;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	if (num <0 && base == 10)
	{
		isNegative = true;
		num = -num;
	}

	while (num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9) ? (rem-10) + 'a' : rem + '0';
		num = num/base;
	}

	if (isNegative)
		str[i++] = '-';

	str[i] = '\0';

	reverse(str,i);

	return str;
}
/*
String String::convertInt(int number)
{
	if (number == 0)
		return "0";
	String tmp = "";
	String returnvalue="";
	while (number>0)
	{
		tmp =tmp+number%10+48;
		number/=10;
	}
	for (int i = 0; i<tmp.length();i++)
		returnvalue=returnvalue+tmp[tmp.length()-i-1];
	return returnvalue;
}	
*/
//  Deconstructor for String destroys dynamic array private member variable
	
String::~String(){
	Capacity=0;
	delete [] s;
}

//  Swap member method
//  PRECONDITION:  takes a String
//  POSTCONDITION: swaps lhs pointer and rhs array pointers

void String::swap(String& rhs){
	char *temp = rhs.s;
	rhs.s=s;
	s=temp;
	int tempInt=rhs.Capacity;
	Capacity=tempInt;
	rhs.Capacity=Capacity;
	
}
// Copy Constructor for String
// Creates a new array for string to use in function calls

void String::resetCapacity(int size){
	String temp(size);
	swap(temp);
}
char& String::operator[] (int spot){
	return s[spot];
}
char String::operator[] (int spot) const{
	return s[spot];
}
// returns the current max size of char array in string
int String::capacity() const{
	return Capacity;
}
// returns the number of chars in array
int String::length()const{
	int size= -1;
	for (int i = 0; s[i] != '\0'; ++i){
		size=i;
	}
	if (size == -1) size = 0;
	else if (size == 0) ++size;
	else if (size > 0) size += 1;
	return size;
}

// converts a string to an int returns 0  if passed invalid string chars
int stringtoInt (const char *c) {

	int value = 0;
	int sign = 1;
	if (*c =='+' || *c == '-') {
		if( *c == '-') sign = -1;
	c++;
	}

	while (isdigit( *c)) {

		value *= 10;
		value += (int) (*c - '0');
		c++;
	}
	return value * sign;
	}

	


// takes an int start point in array
// returns first occurance of blank after start point
int String::findBlank(int start) const {
	
	int i = start;

	while (i <= length())
	{
		if(s[i] == ' ' && (i != start || s[0] == ' '))
		{
			return i;
		}
		else if (i == length())
			return -1;
		++i;
	}
	return -1;


}
// takes a start point for the array
// returns first non blank occurance in array
int String::findNonBlank(int start) const {
	if (start == 0 && s[0] != ' '){
		return 0;
	}
	for (; s[start] != '\0'; ++start) {

		if (s[start] != ' '){
			return start;
		}
	}

	return -1;
}

//Precondition takes an int width 
//Postcondtion:  returns a String that is left and right justified by width

String String::justify(int width)const{

	int i = 0;
	String result= *this;  // copies member string
	
	if(findBlank(0) == -1 || length() > width)  // if there are no blanks or length is bigger than int passed in no change to String
		return *this;

	while (result.length() <  width)      //  adds blanks between each word found in string going evenly from left to right
	{
		i = result.findBlank(i);
		result = result.substr(0,i) + " " +result.substr(i + 1, result.length());
		i = result.findNonBlank(i);
	}

	return result;
}

// Returns the number of occurances of string inside of a string
int String::findstr(String& find) const {

	int times = 0;

	if (length() >= find.length()) {
		for (int i = 0, j = 0; i < length(); ++i, j = 0) {
			while (s[i +j] == find.s[j] && j <= find.length()) {
				++j;

				if (j == find.length()) {
					++times;
					i = i +j;
				}
			}
		}
	}
	return times;
}

// returns extracted part of string

String String::substr(const int start, int end) const
{
	String result;
	assert (end <= length());

	for(int i = start; i <= end; ++i)
		result = result + s[i];

	return result;
}

// Return the number of occurances of a char in a string

int String::findchar(const char ch, const int start) const
{
	String temp = substr(start);
	int first_index = -1;

	for (int i = 0; i < length(); ++i) {
		if (temp[i] == ch) {
			return first_index = i + start;
		}
	}

	return first_index;

}

// Subtacts a char from string

String String::operator - (const char ch) const
{

	String result(length() +1);

	for (int i = 0; i < length(); ++i) {
		if (s[i] != ch) {
			result =result+ s[i];
		}
	}

	return result;

}

// subtracts the length of rhs string from lhs string
String String::operator - (const String& rhs) const
{

	String result(length() +1);
	int i = 0;

	for (int j = 0; i < length(); ++i, j =0) {
		++j;
		while (s[i + j] == rhs.s[j] && j <= rhs.length()) {
			++j;

			if (j == rhs.length()) {
			i = i + j;
			}
	
		}

		

	}
	return result;
}

// copy constructor
String::String(const String& str)
{

	
	s = new char[DEFAULT_STRING_CAPACITY];
	int i=0;
	Capacity = DEFAULT_STRING_CAPACITY;
	for (; str[i] != '\0'; ++i) {
		s[i] = str[i];
	}

	s[i] = '\0';
}

// evaluates a char array and String
bool operator== (const char x[], const String& z){
	int size=0;
	for (int i=0; x[i] != '\0'; ++i){
		size=i;
	}
	++size;
	if (!(size == z.length())){
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


bool operator== (char ch, const String& str){
	int size=0;
	for (int i=0; str[i] != '\0'; ++i) {
		size=i;


	}
	
	if (size > 1) {
		return false;
	}
	
	else {
		if (ch == str[0]){
			return true;
		}
	return false;
	}
}


// Comparision operator for String

bool String::operator == (const String& rhs) const
{
	if (length()==rhs.length()){

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

String String::operator + ( const String& rhs) const
{
	int i = length();
	String result(i + rhs.length() + 1,s);
	result.Capacity = DEFAULT_STRING_CAPACITY;
	for (int j = 0; rhs[j] != '\0'; ++i, ++j){
		result[i] = rhs[j];
	}
	
	result[i] = '\0';
	return result;
}

String operator+ (const char array[], const String& str){

	String temp(array);
	return temp + str;

}

String operator + (char ch, const String& str) {
	String temp(ch);
	return ch + str;
}
bool operator< (const char ch[], const String& str){
	String temp(ch);
	return temp<str;
}

bool operator <= (const String& str1, const String& str2) {
	if (str1 < str2 || str1 == str2){
		return true;
	}
	else {
		return false;
	}
}

bool operator != (const String& str1, const String& str2){
	return (!(str1==str2));

}

bool operator >= (const String& str1, const String& str2){
	return ((!(str1<str2))||(str1==str2));
}

bool operator > (const String& str1, const String& str2){
	return (!(str1<str2));
}
std::ostream& operator << (std::ostream& out, const String& str)
{	
	
	out << str.s;
	return out;
}
/*
String getline(std::istream& in)
{

	String line;
	char ch = '\0';

	for (int i = (in.get(ch), 0); (ch != '\n') && (!in.fail()); ++i, in.get(ch)) {
		
		line = line + ch;

	}

	return line;

}
*/
#endif

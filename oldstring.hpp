//File:        string.hpp
//
//Date:        Fall 2014
//Author:      Dr. J. Maletic
//
//Description: Interface definition of String class for use with test oracle for Part 1.
//
//             String implementation for Project 2 Part 1
//             CS II.  Use this for testing student projects
//             along with test oracles.
//
//

#ifndef STRING_STRING_HPP
#define STRING_STRING_HPP

#include <iostream>
#include <cstdlib>

const int MAX_SIZE = 256; //Or what ever number is specified by the assignment.

class String {
public:
    String        (int size= MAX_SIZE);  // initializes string to null terminator the int will determine string capacity
   // String        (char);  // initalizes char to string
    String        (const char, int size= 2);  // initalizes a char into a string with optional size
    String        (const char[],int size = MAX_SIZE);  // initalizes char array into string with optional size
    String        (const String& str, int cap = MAX_SIZE); //CCONSTRUCTOR
    ~String	  ();  //DESTRUCTOR
    
    String  operator=     (String);  //ASSIGNMENT OPERATOR
    char&   operator[]    (const int spot) 	                 { return s[spot];};  // returns a character from String
    char    operator[]    (const int spot)                const  {return s[spot];};	// returns a character from String
    void    pointerSwap   (String&);         // uses temp to swap two pointers
    int     buffCapacity      ()                        const  {return capacity;};  // returns the size of entire array
    int     length        ()                        const  {return strLength;};          // returns the number of characters
    // PRECONDITION: Method takes a String
    // POSTCONDITION: Method returns an int of the  difference between the two strings
    int     findstr       (const String&)           const;  
    // PRECONDITION: Method takes a character to search for and an int to begin the search from in the array
    // POSTCONDTION: Method returns an int pointing to the position in the array containing specified char
    int     findchar      (const char, const int start=0) const;
    // PRECONDITION: Method takes 2 ints specifying a beginning and ending point of string to search
    // POSTCONDITION:  Method returns a string consisting of the specified beginning and ending points
    String  substr        (const int beginning = 0, int ending = -1)          const;
    bool    operator ==   (const String&)           const;    //  compares 2 strings
    bool    operator !=   (const String& rhs)       const {return !(*this == rhs);};
    bool    operator <    (const String&)           const;	// tests to see if rhs is bigger than lhs string
    bool    operator <=   (const String& rhs)       const {return *this < rhs || *this == rhs;};
    bool    operator >    (const String& rhs)       const {return rhs < *this;};
    bool    operator >=   (const String& rhs)       const {return rhs <= *this;};
    String  operator +    (const String&)           const;      // concatenates 2 strings
    //String operator +=    (const String& rhs)       const {return *this = *this + rhs;};
    String  operator *    (const int)               const;
    String operator *=    (const int x)                   { return *this = *this * x;};
    String operator - (const int);  // subtracts difference between chars of strings
    String operator -=(const int x) { return *this = *this - x; };
    String operator - (const char);
    String operator -=  (const char ch){return *this  = *this - ch;};
    String operator - (const String&);
    String operator -=(const String& str) {return *this = *this - str;};

    friend std::istream& operator >>(std::istream&, const String&);    // input function for string
    friend std::ostream& operator <<(std::ostream&, const String&);  // output function for string

private:
    int strLength;  // ACTUAL CHARS OF STRING
    int capacity;   // SIZE OF ENTIRE ARRAY
    char *s;       // POINTER TO STRING FOR Copy Constructor
    
};




#endif


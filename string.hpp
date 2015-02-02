//File:        string-Part2.hpp   
//       
//Version:     1.0
//Date:        Fall 2014
//Author:      Dr. J. Maletic
//
//Description: Interface definition of String class for use with test oracle for part2.
//
// To use the supplied test oracles you will need to use this interface and namings.
// You must also have all of these methods and functions defined for your string class.
//
// If you add any other members/fields to the class the test oracles will not work.
//
// The I/O operators can be friend functions.
//
// MAKE SURE to name your files:  string.cpp and string.hpp

#ifndef CS23001_P2_STRING_INTERFACE_HPP
#define CS23001_P2_STRING_INTERFACE_HPP

#include <iostream>
#include <cstdlib>

const int DEFAULT_STRING_CAPACITY = 256; //Or what ever number is specified by the assignment.

class String {
public: 
            String        ();               
            String        (char);
            String        (const char*);           
            String        (int, const char*);               //Part 2: String of capacity n with initial value
            String        (int);                            //Part 2: String of capacity n
            String        (const String&);                  //Part 2: Copy constructor
            ~String       ();                               //Part 2: Destructor
    String& operator=     (String);                         //Part 2: Assignment with copy semantics
    void    swap          (String&);                        //Part 2: Constant time swap
    void    resetCapacity (int);                            //Part 2: New capacity, preserving the string values
    String& operator=   (char*);
    //char *  operator=   (String);
    char&   operator[]    (int);                            
    char    operator[]    (int)                     const;  
    //String  itoa(int,int);
    int     capacity      ()                        const;
    int     length        ()                        const;
    //String  itoa(int,int);
    //String    reverse     (int);
    int     findBlank     (int)                     const;
    String  reverse       ();
    int     findNonBlank  (int)                     const;
    String  justify       (int)                     const;
    int     findstr       (String&)                 const;
    String  substr        (const int left = 0, int right = -1)          const;
    int     findchar      (const char, const int start = 0)   const; 
    bool    operator==    (const String&)           const;
    //String&  operator=     (int); 
    //String convertInt     (int);
    bool    operator<     (const String&)           const;
    String  operator+     (const String&)           const;
    String  operator-     (const char)              const;
    String  operator-     (const String&)           const;
    String  justifyFile   (std::ifstream in, std::ofstream& out, int left,int  right);
    friend std::istream& operator>>(std::istream&, const String&);
    friend std::ostream& operator<<(std::ostream&, const String&);
private:
    char *s;
    int  Capacity;
};

void reverse          (char[],int);
char* itoa             (int,char*,int);
String getline          (std::istream&);
int     stringtoInt            (const char *c);
String  operator+       (const char[],  const String&);
String  operator+       (char,          const String&);
bool    operator==      (const char[],  const String&);
bool    operator==      (char,          const String&);
bool    operator<       (const char[],  const String&);
bool    operator<       (char,          const String&);
bool    operator<=      (const String&, const String&);
bool    operator!=      (const String&, const String&);
bool    operator>=      (const String&, const String&);
bool    operator>       (const String&, const String&);

#endif


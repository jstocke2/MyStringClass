//  String class test program
//
//  Tests: default_ctors
//

#include <cassert>
#include "string.hpp"

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str;

        // VERIFY
        assert(str[0] == '\0');
	assert(str == "");
    }

   

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(100);

        // VERIFY
        assert(str[0] == '\0');
	assert(str == "");
    }

 

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing default constuctors." << std::endl;


}


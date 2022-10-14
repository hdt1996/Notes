#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
/*
    Essential Rules for constexpr:
        Meaning: Variable with constexpr guaranteed to have value at COMPILE time
        static const or const could be either COMPILE or RUNTIME
*/



int constexpr_main()
{
    //constexpr const char text[] ="hello"; // declare ARRAY that contains elements of type constexpr const char 
                                            // Note, the ARRAY part is still part of dynamic runtime memory
                                            // Note: constexpr variables are computed at compile time and hard-coded (machine code), no processing at runtime needed
                                            // constexpr values are stored in memory, NOT in heap or stack, within global/static data
                                            // Because of this, if we try to make a pointer to constexpr const char, we get an error because ARRAY belongs to dynamic memory
    constexpr char static text[] ="hello";
    printf("%s\n",text);
    printf("%p\n",text);
    constexpr const char* tptr = text;
    printf("%s\n",tptr);
    return 0;
}
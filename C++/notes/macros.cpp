#include <string>
#include <iostream>

//Use Cases of Macros

/*
    Logging/Debugging 
        memory allocations by line/file with malloc/new or array declarations regarding heap/stack
        define keywords to functions to enable logging depending on debug/release setting
    Calls to applications for feature/error-checking such as openGL or gcc/g++
    Dependency checking/processing for different architecture/software
        can do this by sending definitions to gcc/g++ like gcc -definition_var="SHELL"
        write macros to check for these definitions... enable/disable features that are platform-specific
    Use \<enter> to escape new lines
    Can be used to insert text into script by keyword (Can even include classes / main functions

*/
//#define WAIT //Don't DO THIS, Better use case if LOGGING
//#define HT_DEBUG
#define HT_DEBUG 1
//#ifdef HT_DEBUG //If I want to see if this is defined; works with or without defined value
#if HT_DEBUG == 1
#define WAIT printf("FOUND!\n")
#else
#define WAIT
#endif

int mmain()
{
    WAIT;
    return 0;
}
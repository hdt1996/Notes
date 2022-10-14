/*
Compiler:
    Preprocess code (#preprocessor directives)
    Tokenize/parsing/organizing human language to something compiler understands -> outputs abstract syntax tree
    Convert code into constant data or instructions -> actual machine code that cpu will execute
        Will also store constant variables AKA static/constexpr into machine code (static/i.e. string literals)

    IMPORTANT: constexpr is GUARANTEED to available at runtime, good for templates
               static (depending on placement) are usually available at runtime
    Convert all cpp files fed into compiler, will compile as a "translation unit" -> object files

Linker:
    Responsible for handling function calls by identifying function signatures
    Processes all object files and "links" function calls or variables shared between them
    Leads to error if more than definition (same) is assigned to function name/signature (NOT including natural overloading which is permissible)
*/
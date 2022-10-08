#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>

//Method overloading is straight forward... No notes needed


//OPERATOR overloading
class TestClass {
public:
    friend std::ostream& operator<<(std::ostream& os, TestClass const & tc) {
        return os << "std::ostream& overloaded: " << tc.name << std::endl;
    }
    TestClass(char (*name)[6] ) //receives pointer that stores memory address of array of 6 chars as VALUE
                                // Since pointer is NOT an array, not subject to decay 
                                // -> When we dereference pointer, we are getting value of its stored address which is char[6]
                                // NOTE that char[6] is an array
                                // To print this array using printf("%s",array); we need the 2nd arg to be char*
                                // Luckily for us, once we get the array and pass it in as VALUE, it automatically decays to memory address of first address AKA char*
    {   
        name = name;
        printf("%s\n",*name);
    };
    TestClass(){};

private:
    char (*name)[6] ;
};

class TestClass2 {
public:
    friend std::ostream& operator<<(std::ostream& os, TestClass2 const & tc) {
        return os << "std::ostream& overloaded: " << tc.name << std::endl;
    }
    TestClass2(char **name ) //receives a array of 6 pointers to memory address of char
                             //We are not allowd to pass string literal in through array of pointers, only POINTER to array is allowed!
    {   
        name = name;
    };
    TestClass2(){};

private:
    char **name ;
};

int overloading_main()
{
    TestClass tc((char(*)[6])"BITCH"); //This is pointer to array of 6 characters, in function, value is address of first pointer; array decayed to this memory address
                                        //This pointer is stored in stack (local scope) but value is string literal which is stored in global/static close to text/machine_code

    //TestClass2 tc2((const char *[]){"BITCH2"}); //Error because temporary array. 
                                                  //To pass string literal to function, arg needs to be pointer to something!
                                                  //This is array of pointers established inline (Works in C but not acceptable in C++ -> doesn't allow allocation)
                                                  //Pointers may be stored in local scope/stack and values in global/static since they contain string literals
                                                  //HOWEVER, array itself size or no size is not declared in memory (would have pointer) and no pointer was created
                                                  //Considered a temporary array with no scope
    //TestClass2 tc2(new char*[]{"BITCHY"});
    char** z = new char*[55]; //LVALUE: pointer to pointer to memory address of char
                              //RVALUE: array of size 55 with pointers to char
                              //Notice that z pointer does not have dimensions. 
                              //This is due to array of pointers's value decaying to memory address of first element (first pointer AKA char* type)
    const char* z_txt = "Hello"; 
    z[0] = new char[10]; //Initializes memory of size 10*(sizeof(char)); assigns declaration to each memory block to be type char*//
                         //If we print z[0] or *(z+0) value is 0x0 or NULL;
                         //If we try to assign different type to z's indices, we will get data type error
                         // this new returns pointer to memory address of FIRST element in char[10] array (No dimension data)
    strcpy(z[0],"HELLO"); //Assigns string value to 
                              
    //strcpy(*z,"HELLO WORLD");
    delete z;
    std::cout << tc << std::endl;
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>



namespace structs
{
    struct User
    {   // "public:" not needed since structs implicitly assumes public for properties/methods not assigned under "private:"
        std::string first_name;
        std::string last_name;
        std::string get_status()
        {
            return status;
        }
        private:
            std::string status = "Gold";
        //User()    NOT ALLOWED for structs, no constructors
    };

}
namespace classes
{
    class User //can be instantiated to object
    {
        private: // "private:" not needed since classes implicitly assumes private for properties/methods not assigned under "public:"
            std::string status = "Gold";
        public:
            std::string first_name;
            std::string last_name;
            std::string get_status()
            {
                return status;
            };
            
            User(std::string fn, std::string ln) //C++ by default implements default empty constructor User(){} in public
            {
                first_name=fn;
                last_name=ln;
            };
            User(){}; //default constructor needed when we specify custom constructor

    }; 

    class User_Outside_Constructor //can be instantiated to object
    {
        private: // "private:" not needed since classes implicitly assumes private for properties/methods not assigned under "public:"
            std::string status = "Gold";
        public:
            std::string first_name;
            std::string last_name;
            std::string get_status()
            {
                return status;
            };
            
            User_Outside_Constructor(std::string fn, std::string ln); //Definition of constructor
            User_Outside_Constructor(){}; //default constructor needed when we specify custom constructor

    }; 
    classes::User_Outside_Constructor::User_Outside_Constructor(std::string fn, std::string ln) //C++ by default implements default empty constructor User(){} in public
    {
        first_name=fn;
        last_name=ln;
    };

    constexpr const char* test_word() //returns pointer with value being memory address of char
                                    //"constexpr" means value is computed AT compile time not runtime/dynamic memory
    {
        constexpr const char *pa = "12345678"; //Value wise (not type wise) same as const char pa[] = "12345678";
        return pa;
    }

    /* Even though const char[] decays to same memory address value-wise like const char*, TYPE is different
        We can never return an actual array type due to decay, we need to return a pointer to the array
        
    constexpr const char[] test_word2() //returns const char[] NOT ALLOWED
    {
        constexpr const char *pa = "12345678"; //Value wise (not type wise) const same as char pa[] = "12345678";
        return pa;
    }
    

    constexpr const char* test_word2() //returns pointer with value being memory address of char
    {
        constexpr const char arr[] = "12345678"; WILL NOT WORK because type arr[] is stored in dynamic memory not static!
        constexpr const char *pa = arr; //Value wise (not type wise) same as const char pa[] = "12345678";
        return pa;
    }
    */
    class Uninstantiated_User //cannot be instantiated
    {
        private:
            
            Uninstantiated_User(){ //Constructor placed in private, so WILL NEVER be constructed at all
                printf("\n\n CALLED PRIVATE CONSTRUCTOR");
            };
        public:
            static int i_x; //THIS IS A DECLARATION, NOT A DEFINITION. Need to initialize outside class
                            //This is like an interface with empty body. Definition must match type
            static const int x = 5; //Can initialize static with definition as long as type const
            static constexpr const char* word = test_word(); //To have proper static variable for string, need type of constexpr const char*
            //static const std::string word = "Property"; This does not work because std::string is a class initializer using dynamic memory allocation (Not static)
            //std::string word = "Property"; Even if we declared this public variable, we cannot use it unless we can instantiate the Uninstantiated_User object
            static void print_x()
            {
                printf("%d\n",x);
            }
    };
    int classes::Uninstantiated_User::i_x = 10000000; //Initialize/define static variable i_x outside of declared class

    class User_with_Static //can be instantiated. Can call static methods with object or plain class name
    {
        public:
            static const int x = 5;
            static constexpr const char* word = test_word(); //To have proper static variable for string, need type of constexpr const char*
            //static const std::string word = "Property"; This does not work because std::string is a class initializer using dynamic memory allocation (Not static)
            //std::string word = "Property"; Even if we declared this public variable, we cannot use it unless we can instantiate the Uninstantiated_User object
            static void print_x()
            {
                printf("%d\n",x);
            }
            User_with_Static(){};
        
    };
}


int classes_main()
{
    structs::User s_user;
    s_user.first_name="Hung";
    s_user.last_name="Tran";
    printf("structs::User\n");
    printf("Method status: %s\n",s_user.get_status().c_str());
    printf("Property first_name: %s\n",s_user.first_name.c_str());
    printf("Property last_name: %s\n",s_user.last_name.c_str());
    printf("\n");
    classes::User c_user("Hungzz","Tranzz"); //constructor inside class (Not as legible when wanting keyword arguments)
    //classes::User c_user();
    //c_user.first_name="Hung";
    //c_user.last_name="Tran";
    printf("classes::User\n");
    printf("Method status: %s\n",c_user.get_status().c_str());
    printf("Property first_name: %s\n",c_user.first_name.c_str());
    printf("Property last_name: %s\n",c_user.last_name.c_str());
    printf("\n");

    printf("classes::Uninstantiated_User\n");
    classes::Uninstantiated_User::print_x();
    printf("Static Property word: %s\n",classes::Uninstantiated_User::word);
    printf("Static Property i_x: %d\n",classes::Uninstantiated_User::i_x);
    printf("\n");

    printf("classes::User_with_Static\n");
    classes::User_with_Static user_with_static;
    printf("Static Property word called by child object: %s\n",user_with_static.word);
    printf("Static Property word called by class: %s\n",classes::User_with_Static::word);

    printf("\n");
    printf("classes::User_Outside_Constructor\n");
    classes::User_Outside_Constructor user_outside_constructor("Tedy","Yohanes");
    printf("Method status: %s\n",user_outside_constructor.get_status().c_str());
    printf("Property first_name: %s\n",user_outside_constructor.first_name.c_str());
    printf("Property last_name: %s\n",user_outside_constructor.last_name.c_str());
    printf("\n");

    return 0;
}
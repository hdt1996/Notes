#include <iostream>
    const char x [] = "BAT"; //x variable array is allocated to heap, actual values at memory addresses in heap
    const char* xp= &x[0]; //This pointer is only known at runtime, NOT compile time, allocated to stack

#define TESTT "HELLO WORLD"
void Print(int value)
{
    std::cout << value << std::endl;
}

void Print(std:: string value)
{
    std::cout << value << std::endl;
}

/*
    Templates rules for parameter values
    1) Cannot be string literal
    2) Cannot be typeid
    3) Cannot be temporary object (research...)
    4) Cannot be non-static member, base subobject, or array element of 1-3
    5) Expanding on 4, array element means we cannot subscript or dereference
        -> when passing in a variable NOT only does it need to be stored in global/static
           it also cannot be a direct value, needs to be memory address (CAN'T EVEN BE POINTER, must be address & or arr due to array decay to memory address)

*/
namespace Templates
{
    template<typename T>
    void Print(T value)
    {
        std::cout << value << std::endl;
    };


    template<int N, typename T>
    class Array
    {
        private:
            int my_arr[N];
        public:
            int getSize()
            {
                return N;
            };
            T name;
            Array(T name)
            {
                name = name;
            }
            Array(){}
    };
    template <const char** P>
    class TestPointers
    {
        public:
            TestPointers(){}
            const char** p = P;
    };
    template <const char* P>
    class TestPointers2
    {
        public:
            TestPointers2(){}
            const char* p = P;
            void printP()
            {
                printf("%s",P);
            }
    };
}

void test_str(const char* str)
{
    printf("STR TEST: %s\n", str);
}

int main()
{
    Print(5);
    Print("Hello");
    Print(5.5f);
    printf("\n");
    /*
    const char x [] = "BAT"; //x variable array is allocated to heap, actual values at memory addresses in heap
    const char* xp= &x[0]; //This pointer is only known at runtime, NOT compile time, allocated to stack
     2 lines above since they belong to stack, compiler will not know. WORKS when assigned to global which is stored in static/global
    */
    Templates::Print<int>(5);
    Templates::Print<const char[]>("Hello"); //Same as below
    Templates::Print<const char*>("BBBB");
    Templates::Print<float>(5.5);
    Templates::Array<5, const char*> array("BBBB");

    //printf("%d\n",array.getSize());

    test_str("HELLO WORLD");
    Templates::TestPointers<&xp> testp; 
    Templates::TestPointers2<x> test2; //passing in global array works because its value is memory address of first element which is valid (Array decay)
                                        //When uses for initializing P property, it technically converts to a pointer but I will still keep interpreting it for now
                                        //as memory address to type char

    static const char tarr[] = "Hello World";
    Templates::TestPointers2<tarr> test4; //WORKS! NOTE WE NEED THE STATIC to assign to static memory AKA global/static in data portion
    test2.printP();
    return 0;
}
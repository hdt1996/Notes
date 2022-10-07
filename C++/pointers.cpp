#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

namespace test
{

    void pa(const char *pa ) //same as char a[10]
    {
        printf("String: %s\n",pa);
    }

    void ppa(const char **ppa)   //Same as const char *ppa[]
                            //No dimensional data aside from value data type
    {
        int i = 0;
        int c = 0;
        printf("%s -> Wrong: Trying to print pointer use %%p instead..\n",ppa); //Does not work because arg ppa is first element of original ppa
                            //first element is a POINTER of type char** AKA POINTER to memory address to char
                            //Need to dereference first element to get first address of underlying string array -> type char*
                            //Can dereference again to get actual char values
        printf("Memory address value of pointer: %p\n",(void*)ppa);
        printf("Memory address actual pointer: %p\n",(void*)&ppa);
        printf("%s\n",ppa[i]); //after dereferencing to first address of string array char*; valid for print
        printf("String: %s=%s\n",*(ppa+i),ppa[i]);
        printf("Value: %c=%c\n",*(*(ppa+i)+c),ppa[i][c]);
        printf("Size of Actual Pointer: %lu\n",sizeof(&ppa)); //Need to use & since using ppa by itself signalled char**
                                                            // sizeof needs to be (*) or single level pointer type, using & to achieve this
        printf("Size of 1 Value: %lu\n",sizeof(ppa[i][c]));
    }

    void a(char *a ) //same as char a[10]
    {
        printf("String: %s\n",a);
    }

    void aa(char (*aa)[10] ) //same as char aa[10][10]
                            //VALUE dimensions can be determined with sizeof(aa[i]) or sizeof(*(aa+i))
                            //NOTE: EXACT SAME RESULTS AS aa_ptr2
    {
        int i = 0;
        int c = 0;
        printf("%s\n",aa); //works but flagged warning
        printf("%s\n",aa[i]);
        printf("String: %s=%s\n",*(aa+i),aa[i]);
        printf("Value: %c=%c\n",*(*(aa+i)+c),aa[i][c]);
        printf("Number of Values: %lu\n",sizeof(aa[i]));
    }
    
    void aa_ptr1(char *aa_ptr1) //same as char aa_ptr1[]
                            //VALUE dimensions can be determined with sizeof(aa[i]) or sizeof(*(aa+i))
    {
        int i = 0;
        printf("%s\n",aa_ptr1); //works but flagged warning
        printf("Value: %c=%c\n",*(aa_ptr1+i),aa_ptr1[i]);
        printf("Size of 1 Value: %lu\n",sizeof(aa_ptr1[i]));
    }
    
    void aa_ptr2(char (*aa_ptr2)[10]) //same as char aa_ptr2[10][10]
                                    //pointer to array of size 10 with char
                                    //NOTE: EXACT SAME RESULTS AS aa
    {
        int i = 0;
        int c = 0;
        printf("%s\n",aa_ptr2); //works but flagged warning
        printf("%s\n",aa_ptr2[i]);
        printf("Value: %c=%c\n",*(*(aa_ptr2+i)+c),aa_ptr2[i][c]);
        printf("Size of 1 Value: %lu\n",sizeof(aa_ptr2[i]));
    }

    void aa_ptr3(char (*aa_ptr3)[10][10]) //same as char aa_ptr3[1][10][10]
                                    //pointer to array of size 10 with char
                                    //NOTE: EXACT SAME RESULTS AS aa
    {
        int a = 0;
        int i = 0;
        int c = 0;
        printf("%s\n",aa_ptr3); //works but flagged warning
        printf("%s\n",aa_ptr3[a][i]); //works but flagged warning
        printf("Value: %c=%c\n",*(*(*(aa_ptr3+a)+i)+c),aa_ptr3[a][i][c]);
        printf("Size of Extra: %lu\n",sizeof(aa_ptr3[a]));
        printf("Size of Level 0: %lu\n",sizeof(aa_ptr3[a][i]));
        printf("Size of 1 Value: %lu\n",sizeof(aa_ptr3[a][i][c]));
    }
}

int main()
{
    //Essential Rules:
    /*
        No Decay Exceptions:
            1) &(Array) get address of array, remembers type
            2) sizeof(Array)
            3) When string literal such as char arr[] = "foo"
            4) Outside of 1-3, value of array is address of first element (decays to pointer type (value = address) of first element)
            5) &array and array will have the SAME value (address) but are different type-wise
                &array -> data_type(*)[N]
                array data_type[N]
            6) ARRAYS CONTAIN MEMORY ADDRESSES AS ELEMENTS -> THESE NEED TO BE DEREFERENCED TO GET VALUE
               IF WE HAVE ARRAY OF POINTERS, WE WILL NEED TO DEREFERENCE POINTER TO GET MEMORY ADDRESS, THEN DEREFERENCE AGAIN TO GET VALUE
                Think of pointers as containers of memory addresses that may or may point to other pointers or memory addresses that contain values

    */
    //Basic example

    char a[10]="1234567"; //Declare array of size 8 with type char
    //char a[10]={"1234567"};
    char* a_ptr = a; // SAME AS char* a_ptr = &(a[0]);
                    // Declare pointer TO type char
                    // Array value always DECAYS to first element's ADDRESS
                    // Sizeof is fruitless to get whole array size.
                    // sizeof(a_ptr) gives us pointer size
                    // If we dereference, we can only get size of actual data type stored in array
                    // --> sizeof(*a_ptr) = 1 for char datatype
    
    char(* b_ptr)[10]=&a; //&a is address of array of 10 with type char AKA char(*)[10] --> Pointer to char[10] 
                    // Declare pointer TO array of size 10 with type char
                    // Using & for RVALUE means passing by REFERENCE -> this is a reference (function-wise)
                    // We can use sizeof(*b_ptr) == we dereference to get ACTUAL ARRAY since &a is char(*)[10] 
    

    char aa[10][10]={"HUNG","DUYEN","KHANH"}; //Declare array of size 10, each element containing array of size 10 with type char
                                        //&aa is type char(*)[10][10] == address of array aa aka pointer to char[10][10]
    
    //char* aa_ptr = *aa;               //This does not work if we aim to get pointer to char type
                                        //*aa means we dereference memory address of first element, which is of type char(*)[10] => memory address of array of 10 chars

    char* aa_ptr1 = *aa;                //Declare pointer to first element of first subarray
                                        //This works because *aa is first element of aa deferenced.
                                        // Although *aa is first subarray, the value is decayed to first address of this subarray.
                                        // Type of first address of subarray is type char(*) or pointer to char

    char (*aa_ptr2)[10] = &(*aa);       //Declare pointer to first subarray
                                        //Here we use & of deferenced value (array). Here we need to match array dimensions
                                        //Value of aa_ptr2 is address of first subarray

    char (*aa_ptr3)[10][10] = &(aa);    //Declare pointer to whole array
                                        //Since we use & for original aa, we must match ALL dimensions

    const char *pa = "12345678";       //SAME AS const char (*ppa)= {"12345678"};
                                        // Declare pointer to char
                                        // We have no dimension data of how many values unless we specify
                                        // Whole string is printable without need for dimensions due to NULL terminator (Also present in above char*);

    const char *ppa[]= {"HUNG","HOANG","HIEP"};
                                        //Declare array of size three with pointer to char AKA array of pointers!
                                        // We do have dimensional data of how many subarrays there are (1)
                                        // We have no dimension data of how many values in subarray unless we specify
                                        // Unless we point to an established array, no way to get exact number of values for char
                                        // We can set up a size as first index and use ppa++ after saving size and passing it to function
    
    // --------------------------------------------------FUNCTIONS---------------------------------------------
    printf("test::a\n");
    test::a(a); //arg: a is type char[10]; we are passing by value!
                //a decays to char* since array decays to memory address of first element
    printf("\ntest::aa\n");
    test::aa(aa); //arg: aa is type char[10][10]; we are passing by value!
                  //Since array decays to memory address of first element
                  //First element of aa is subarray of 10 chars AKA char*[10]
                  //Note: In function, when using subarray by name, the value is memory address of its first element which is char(*)
                  //When we print, %s looks for char* datatype but subarray is not char*, it is char*[10]
                  //EMPHASIZE: subarray is type char *[10] ==> array of memory addresses NOT char(*)[10] which signifies memory address to ARRAY
                  //Print will still work but we will get flag. Way to fix is use subarray[i] | *(subarray+i)
                  //Note that fix above prints the WHOLE word (increment memory address until NULL terminator)
                  //To print individual characters of each word, dereference subarray (pull value by memory address incr) or index it
    printf("\ntest::aa_ptr1\n");
    test::aa_ptr1(aa_ptr1); //arg: aa_ptr is type char* AKA pointer to memory address of first element of first subarray
                            //We can print whole word by %s due to increment until NULL terminator
                            //REMEMBER: We are limited to only elements of FIRST subarray i.e. "Hung"
                            //We cannot access other words, we will need to create more pointers
    printf("\ntest::aa_ptr2\n");
    test::aa_ptr2(aa_ptr2);

    printf("\ntest::aa_ptr3\n");
    test::aa_ptr3(aa_ptr3);

    printf("\ntest::pa\n");
    test::pa(pa);

    printf("\ntest::ppa\n");
    test::ppa(ppa);         //arg: ppa is array of pointers and will decay to first element address as function arg
                            //first memory address implies char* already but since the elements are pointers, we add another *
                            //Parameter for function will need to be char** or char* param []
    printf("\n");
    return 0;
}


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
                    //Declare pointer TO type char
                    //array always addressed with first 
                    // We use decayed value -> this is a pointer (function-wise)
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
                                        // Although *aa is an array, the value is decayed to first address fo this array.

    char (*aa_ptr2)[10] = &(*aa);       //Declare pointer to first subarray
                                        // Here we use & of deferenced value (array). Here we need to match array dimensions

    char (*aa_ptr3)[10][10] = &(aa);    //Declare pointer to whole array
                                        //Since we use & for original aa, we must match ALL dimensions

    const char *pa = "12345678";       //SAME AS const char (*ppa)= {"12345678"};
                                        // Declare pointer to char
                                        // We have no dimension data of how many values unless we specify
                                        // Whole string is printable without need for dimensions due to NULL terminator (Also present in above char*);

    const char *ppa[]= {"HUNG","HOANG","HIEP"};
                                        //Declare array of size three with pointer to char
                                        // We do have dimensional data of how many subarrays there are (1)
                                        // We have no dimension data of how many values unless we specify
                                        // Unless we point to an established array, no way to get exact number of values for char
                                        // We can set up a size as first index and use ppa++ after saving size and passing it to function
    return 0;
}

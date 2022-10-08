#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Definitions;
    Pointer vs Reference:
        Reference variable cannot be set without value of existing object or variable
        Reference variable is considered an "alias" for existing variable/object
        Set up with char& ref_var = orig_var;
        temporary object: unnamed object created by compiler to store temp value
*/
namespace test
{

    void pa(const char *pa ) //same as char a[10]
    {
        printf("String: %s\n",pa);
    }

    void ppa(const char **ppa)   //Same as const char *ppa[]
                            //No dimensional data aside from value data type
                            //Initially passed in was an array of pointers
                            //Value of array is decayed to memory address of first POINTER
                            //first element is a memory address of POINTER type char** AKA POINTER to memory address to char
                            //We get char** because data type of pointer is char*, but first index of array is memory address TO Pointer hence char** (add another *)
                            //Need to dereference first element to get value or memory address to -> type char*
                            //Can dereference again to get actual char values
                            //IMPORTANT: No structure means we are dealing with char or memory chars, no char[] at all
    {
        int i = 0;
        int c = 0;
        printf("%s -> Wrong: Trying to print pointer use %%p instead..\n",ppa); //Does not work because arg ppa is first element of original ppa

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
                                    //receives pointer that stores memory address of array of 10 chars as VALUE
                                    // Since pointer is NOT an array, not subject to decay 
                                    // -> When we dereference pointer, we are getting value of its stored address which is char[10]
                                    // NOTE that char[10] is an array
                                    // To print this array using printf("%s",array); we need the 2nd arg to be char*
                                    // Luckily for us, once we get the array and pass it in as VALUE, it automatically decays to memory address of first address AKA char*
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

int pointers_main()
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

    const char pa2[]="12345678";        //Declare a char array of 9 elements, values being memory address to char
                                        //Compared to below, due to array decay:
                                        // pa2[0] = pa[0] since these both point to same memory addresses
                                        // However note that type is different, pa2[] is char array, pa is pointer
    const char *pa = "12345678";       //SAME AS const char (*pa)= {"12345678"};
                                        //Creates pointer to string literal which is stored in STATIC memory
                                        // Declare pointer with value of memory address of char
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
                  //First element of aa type is subarray of 10 chars AKA char*[10];
                  //this element (subarray) decays/stores value of address of its first element which is (char*)
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
    test::pa("HELLO WORLD"); //Hello World already treated as const char* since it is string literal

    printf("\ntest::ppa\n");
    test::ppa(ppa);         //arg: ppa is array of pointers and will decay to first element address as function arg
                            //first memory address implies char* already but since the elements are pointers, we add another *
                            //Parameter for function will need to be char** or char* param []
    printf("\n");
    return 0;
}

/*
const char a[]= "12345678";
const char *b[9] = {"12345678"};

For a:
Since this is a regular 1d char array, I think of this as..
"an array of size 9 containing memory addresses to value of char"
If we do a[0] or *(a+0), memory address of first index is dereferenced to get direct value.

for b:
I think of this as...
an array of size 9 elements containing memory addresses of pointers pointing to memory addresses to value of char"
if we do b[0] or *(b+0), memory address of first index is dereferenced to get value which is the actual pointer object
if we do b[0][0] or *(*(b+0)+0), pointer's value or memory address(type char*) is dereferenced
to get value of that memory address which is char and value of "1".



    TestClass tc((char(*)[6])"BITCH"); //This is pointer to array of 6 characters, in function, value is address of first pointer; array decayed to this memory address
                                        //This pointer is stored in stack (local scope) but value is string literal which is stored in global/static close to text/machine_code

    //TestClass2 tc2((const char *[]){"BBBB"}); //Error because temporary array. 
                                                  //To pass string literal to function, arg needs to be pointer to something!
                                                  //This is array of pointers established inline (Works in C but not acceptable in C++ -> doesn't allow allocation)
                                                  //Pointers may be stored in local scope/stack and values in global/static since they contain string literals
                                                  //HOWEVER, array itself size or no size is not declared in memory (would have pointer) and no pointer was created
                                                  //Considered a temporary array with no scope
    //TestClass2 tc2(new char*[]{"BBBB"});
    char** z = new char*[55]; //LVALUE: pointer to pointer to memory address of char
                              //RVALUE: array of size 55 with pointers to char (Array of pointers)
                              //Notice that z pointer does not have dimensions. 
                              //New... like malloc from C returns pointer with value as memory address of FIRST pointer in array of pointers
                              //NOT the same as pointer with value as memory address of array of pointers --> WRONG
    const char* z_txt = "Hello"; 
    z[0] = new char[10]; //Initializes memory of size 10*(sizeof(char)); assigns declaration to each memory block to be type char*
                         //If we print z[0] or *(z+0) value is 0x0 or NULL;
                         //If we try to assign different type to z's indices, we will get data type error
                         // this new returns pointer to memory address of FIRST element in char[10] array (No dimension data)
    strcpy(z[0],"HELLO"); //Assigns string value to 
*/

/*
    From C Malloc (Check for compatibility of data types especially const char* for c++)
    char** str_arr =malloc((total_elems)*sizeof(char*)+1);
                                //malloc creates array of DECLARED (NOT DEFINED) pointers with value as memory address to char of size 4 in this case
                                //malloc returns pointer with value as memory address of first pointer to char from created array
                                //IMPORTANT: MALLOC DOES NOT return pointer with value as memory address of CREATED ARRAY --> WRONG
                                //RVALUE: since array decays to memory address of first element
                                //Remember
                                                            

    for (int i = 1; i < total_elems + 1; i++)
    {
        str_arr[i] = malloc((max_length+1) * sizeof(char)+2);
    };
    //char te[2];   //Best way to copy character or sequence of characters to first element of str_arr which declares char* (Works with array degradation)

    //sprintf(te,"%i",total_elems);
    //strcpy(str_arr[0],te);

    char* te= "2";  //If we were to declare char* te, we need to place in string literal for array to initialize without error and set index 0 to pointer itself(its address)
                    //Note that pointer's value is memory address of first element of array of chars
    str_arr[0] = te; //store memory address of te to first index of str_arr | value of first index is POINTER
    
    char *tc;




*/
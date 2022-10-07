#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    char test[]="HELLO";
    printf("\nOriginal 1D Array Value: %s\n",test);
    printf("Address by name: %p --> Pointer expects type void*. In array name is already type void*\n",(void*)test);
    printf("Address with &: %p\n",(void*)&test);
    printf("Note: Last 2 Addresses are the same\n\n");

    for( int i = 0; i < strlen(test); i++)
    {
        printf("ASCII HEX: arr[%d] = %02x = %02x = *(arr+%d)\n", i, test[i], *(test+i), i );
    }
    for( int i = 0; i < strlen(test); i++)
    {
        printf("ASCII TEXT: arr[%d] = %c = %c = *(arr+%d)\n", i, test[i], *(test+i), i );
    }
    for( int i = 0; i < strlen(test); i++)
    {
        printf("ADDRESS: (void*)&arr[%d] = %p= %p = (void*)&*(arr+%d)\n", i, (void*)&test[i], (void*)&*(test+i), i );
    }
    
    int x = 5;
    printf("\nOriginal Int Value: %d\n",x);
    printf("ASCII HEX: x = %02x\n", x);
    printf("ASCII NUMBER: x = %d\n", x);
    printf("Address by name: %p ---> //Does not work to show address. Using %%p only shows hex value\n",x);
    printf("Address by &: %p\n",(void*)&x);
    printf("Note: Both aboves Addresses are different since type is NOT array\n\n");
    
    char* refptr;
    refptr=test;
    printf("\n\n\n");
    printf("\nOriginal Reference to 1D Array %s\n",refptr);
    printf("Reference Address by name: %p --> Points to array address (same as first element address)*\n",(void*)refptr);
    printf("Reference Address with &: %p --> Points to address of reference itself\n",(void*)&refptr);
    printf("Note: Last 2 Addresses are NOT the same\n\n");
    printf("\n");

    for( int i = 0; i < strlen(refptr); i++)
    {
        printf("ASCII HEX: arr_pointer[%d] = %02x = %02x = *(arr_pointer+%d)\n", i, refptr[i], *(refptr+i), i );
    }
    for( int i = 0; i < strlen(refptr); i++)
    {
        printf("ASCII TEXT: arr_pointer[%d] = %c = %c = *(arr_pointer+%d)\n", i, refptr[i], *(refptr+i), i );
    }
    for( int i = 0; i < strlen(refptr); i++)
    {
        printf("POINTER ADDRESS: &arr_pointer[%d] = %p\n", i, (void*)&refptr[i]);
    }

    printf("\n");
    printf("Size of Original Array Value: %lu\n",sizeof(test));
    printf("Size of Original Array[0]: %lu\n",sizeof(test[0]));
    printf("Size of Pointer to Elements in Array: %lu\n",sizeof(refptr));
    printf("Size of Pointer to Elements in Array[0]: %lu\n",sizeof(refptr[0]));
    
    
    char test_2d[][10] = {"HUNG","BOANG","CIEP"};
    printf("\nOriginal 2D Array Initial Value: test_2d[0] = *(test_2d+0) = %s = %s\n",test_2d[0], *(test_2d+0));
    printf("Original 2D Array 2nd Value: test_2d[1] = *(test_2d+1) = %s = %s\n",test_2d[1], *(test_2d+1));
    printf("Original 2D Array 3rd Value: test_2d[2] = *(test_2d+2) = %s = %s\n",test_2d[2], *(test_2d+2));
    printf("\n");
    printf("Level 0 1st Address by name: %p\n",(void*)test_2d);
    printf("Level 0 1st Address with &: %p\n",(void*)&test_2d);
    printf("Level 0 2nd Address by name: %p\n",(void*)test_2d[1]);
    printf("Level 0 2nd Address with &: %p\n",(void*)&test_2d[1]);
    printf("Level 0 3nd Address by name: %p\n",(void*)test_2d[2]);
    printf("Level 0 3nd Address with &: %p\n",(void*)&test_2d[2]);
    printf("\n");
    printf("Level 1 1st Address by name: %p\n",(void*)test_2d[0][0]);
    printf("Level 1 1st Address with &: %p\n",(void*)&test_2d[0][0]);
    printf("Level 1 2nd Address by name: %p\n",(void*)test_2d[1][0]);
    printf("Level 1 2nd Address with &: %p\n",(void*)&test_2d[1][0]);
    printf("Level 1 3nd Address by name: %p\n",(void*)test_2d[2][0]);
    printf("Level 1 3nd Address with &: %p\n",(void*)&test_2d[2][0]);
    printf("\n");
    printf("Level 0 Size: %lu\n",sizeof(test_2d)/sizeof(test_2d[0]));
    printf("Level 1 Size: %lu\n",sizeof(test_2d[0])/sizeof(test_2d[0][0]));
    printf("\n\n");
    for( int i = 0; i < strlen(test_2d[0]); i++)
    {
        printf("POINTER ADDRESS: &arr2d[0][%d] = %lu = %lu == &*(*(arr2d+0)+%d)\n", i, (void*)&test_2d[0][i], (void*)&(*(*(test_2d+0)+i)), i);
    }
    for( int i = 0; i < strlen(test_2d[1]); i++)
    {
        printf("POINTER ADDRESS: &arr2d[1][%d] = %lu = %lu == &*(*(arr2d+1)+%d)\n", i, (void*)&test_2d[1][i], (void*)&(*(*(test_2d+1)+i)), i);
    }
    for( int i = 0; i < strlen(test_2d[2]); i++)
    {
        printf("POINTER ADDRESS: &arr2d[2][%d] = %lu = %lu == &*(*(arr2d+2)+%d)\n", i, (void*)&test_2d[2][i], (void*)&(*(*(test_2d+2)+i)), i);
    }
    /*
            arr[0][0]= 'H' = 'H' =  *(*(arr+0)+0)
            arr[1][0]= 'B' = 'B' =  *(*(arr+1)+0)
            arr[2][0]= 'C' = 'C' =  *(*(arr+2)+0)
    */
    
    //REMEMBER, Pointer stores a memory address and the * dereference means to go to that address to get the value/address stored
    //ARRAYS: Segment in memory that contains multiple elements (AKA pointers to memory that contain values)
    return 0;
}
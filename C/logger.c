#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countMaxStrinArr(char** str_arr[]) //array decays to pointer
{
    int max_len=0;
    int curr_len;
    int size = atoi((*str_arr)[0]);
    (*str_arr)++;

    for(int ind=0; ind<size;ind++)
    {
        curr_len=strlen((*str_arr)[ind]);
        if(curr_len > max_len)
        {
            max_len=curr_len;
        }
    }
    return max_len;
}

char** build2dArraybyLiteral(char* arg_string, const char* delim)
{    

    int total_delims = 0;
    int max_length = 0;
    int curr_length = 0;
    char x[2];
    printf("Building Array from Literal...\n");
    printf("Original: %s\n",arg_string);
    for(int c = 0; c < strlen(arg_string); c++)
    {
        //printf("%c\n",arg_string[c]);
        sprintf(x,"%c",arg_string[c]);
        if(strcmp(x,delim) == 0)
        {
            total_delims++;
            if(curr_length > max_length)
            {
                max_length=curr_length;
            }
            curr_length = 0;
            continue;
        }
        curr_length++;
    }
    //Add null terminator
    max_length=max_length+1;
    int total_elems = total_delims + 1;
    int offset = 2;
    printf("Total Delims: %d\n",total_delims);
    printf("Total Elems: %d\n",total_elems);
    printf("Max Length: %d\n",max_length);

    char** str_arr =malloc((total_elems+offset)*sizeof(char*));
                                //malloc creates array of DECLARED (NOT DEFINED) pointers with value as memory address to char of size 4 in this case
                                //malloc returns pointer with value as memory address of first pointer to char from created array
                                //IMPORTANT: MALLOC DOES NOT return pointer with value as memory address of CREATED ARRAY --> WRONG
                                //RVALUE: since array decays to memory address of first element
                                //Remember
                                                            

    for (int i = 0; i < total_elems + offset; i++) //i needs to be zero if we are NOT using pointer substitution (See below)
    {
        str_arr[i] = malloc((max_length) * sizeof(char));
    };

    char te[2];   //Best way to copy character or sequence of characters to first element of str_arr which declares char* (Works with array degradation)

    sprintf(te,"%i",total_elems);
    strcpy(str_arr[0],te);

    //char* te= "2";  //If we were to declare char* te, we need to place in string literal for array to initialize without error and set index 0 to pointer itself(its address)
                    //Note that pointer's value is memory address of first element of array of chars
    //str_arr[0] = te; //store memory address of te to first index of str_arr | value of first index is POINTER

    char tc[2];
    sprintf(tc,"%i",max_length);
    strcpy(str_arr[1],tc);


    for(int i = 2; i < total_elems + offset; i++)
    {
        strcpy(str_arr[i],"");
        //str_arr[i][0]='c'; //Works, can MODIFY string. 
        //printf("Modified: %s\n",str_arr[i]);
    };

    int curr_index = offset;
    for(int c = 0; c < strlen(arg_string); c++)
    {
        char x[2];
        sprintf(x,"%c",arg_string[c]);
        if(strcmp(x,delim) == 0)
        {
            curr_index++;
        }
        else
        {
            strcat(str_arr[curr_index],x);
        }
    }
    return str_arr;
}

void logLits(char* f_string, char* str_arr, int str_size) //Function params: char* means char[size_of_input][1] | Only one character stored at each index
                                                         //NOTE: When we pass in literal string "Phrase" to str_arr parameter, it is NOT MUTABLE since stored in GLOBAL/STATIC
                                                         //C++ standards require us to notate str_arr with const char* but we do not in this case since whatever C allows it.
                                                         
{
    char str_buffer[str_size];
    char** args_arr=build2dArraybyLiteral(str_arr, " ");
    int num_elems;
    int num_chars_per_elem;
    num_elems=atoi(*args_arr);
    num_chars_per_elem=atoi(*(args_arr+1));
    args_arr=args_arr+2;
    char f_copy[strlen(f_string)+1];
    char msg_str[strlen(f_string)+strlen(str_arr)+2];
    strcpy(f_copy,f_string);
    strcpy(msg_str,"");
    char* token=strtok(f_copy," "); // strtok automatically frees and replaces pointer for String Literal
    int arg_index = 0;
    while( token != NULL)
    {
        if(strcmp(token,"%s") == 0)
        {
            strcat(msg_str, " ");
            strcat(msg_str, args_arr[arg_index]);
            arg_index++;
        }
        else
        {
            strcat(msg_str, " ");
            strcat(msg_str,token);
        }
        token = strtok(NULL, " ");
    };
    printf("%s\n",msg_str);
    args_arr = args_arr - 2;
    //CLEAR MEMORY of 2D Array allocated
    //free(args_arr[0]);
    
    //free(args_arr);
    printf("Number of Elements: %s\n",args_arr[0]);
    printf("Word: %s\n",args_arr[1]);
    for(int i = 0; i < num_elems; i++)
    {   
        free(args_arr[i]);
        args_arr[i]=NULL;
    }
    free(args_arr);
    args_arr=NULL;
}

void logVars(char* f_string, char** str_arr, int str_size) //Function params: char* means char[size_of_input][1] | Only one character stored at each index
{
    char **args_arr=str_arr; ///make reference to pointer for naming conveniece. Str_arr is already a pointer so when we make another we add another asterisk *
    char ***arg_ptr=&args_arr;
    char f_copy[strlen(f_string)+1];
    
    char msg_str[strlen(f_string)+countMaxStrinArr(arg_ptr)+2];
    strcpy(f_copy,f_string);
    strcpy(msg_str,"");
    char* token=strtok(f_copy," "); // strtok automatically frees and replaces pointer for String Literal
    
    int arg_index = 0;
    while( token != NULL)
    {
        if(strcmp(token,"%s") == 0)
        {
            strcat(msg_str, " ");
            strcat(msg_str, args_arr[arg_index]);
            arg_index++;
        }
        else
        {
            strcat(msg_str, " ");
            strcat(msg_str,token);
        }
        token = strtok(NULL, " ");
    };
    printf("%s\n",msg_str);

}


int main()
{
    logLits("\nKey: %s \nValue: %s \n", "HUNGY POO", 5);
    //logVars("\nKey: %s \nValue: %s \n", (char*[]){"2","HUNG","COOL"}, 5);
    return 0;
}
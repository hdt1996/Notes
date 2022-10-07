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

char** buildArrbyLit(char* arg_string, const char* delim)
{    
    int curr_index = 0;
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
    printf("Total Delims: %d\n",total_delims);
    printf("Total Elems: %d\n",total_elems);
    printf("Max Length: %d\n",max_length);

    char** str_arr =malloc((total_elems)*sizeof(char*));
    for (int i = 0; i < total_elems; i++)
    {
        str_arr[i] = malloc((max_length+1) * sizeof(char));
    }
        
    for(int i = 0; i < total_delims+1; i++)
    {
        strcpy(str_arr[i],"");
    }

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
{
  char str_buffer[str_size];
  char** args_arr=buildArrbyLit(str_arr, " ");
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
  }
    printf("%s\n",msg_str);
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
    }
        printf("%s\n",msg_str);
}


int main()
{
    //logLits("\nKey: %s \nValue: %s \n", "HUNGY POO", 5);
    logVars("\nKey: %s \nValue: %s \n", (char*[]){"2","HUNG","COOL"}, 5);
    return 0;
}
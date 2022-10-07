#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
    //printf("\nMax length of strings in array is %d",max_len);
    return max_len;
}
char** buildArrbyLit(char* arg_string, char* delim)
{    
    int curr_index = 0;
    int total_delims = 0;
    int max_length = 0;
    int curr_length = 0;
    char x[2];
    char msg_orig[200];
    char msg_delims[200];
    char msg_length[200];
    char msg_elems[200];
    
    sprintf(msg_orig,"Original: %s\n",arg_string);
    
    Serial.println("Building Array from Literal...");
    Serial.println(msg_orig);
    for(int c = 0; c < strlen(arg_string); c++)
    {
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
    
    sprintf(msg_delims,"Total Delims: %d",total_delims);
    sprintf(msg_elems,"Total Elems: %d",total_elems);
    sprintf(msg_length,"Max Length: %d",max_length);
    Serial.println(msg_delims);
    Serial.println(msg_elems);
    Serial.println(msg_length);
    char** str_arr = malloc((total_elems)*sizeof(char*));
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
            //strcat(str_arr[curr_index]," ");
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
  
  //
    //char test[10][10];
    //char (*tp)[10][10] = &test; //Pointer to WHOLE array, noticing *tp which means taking values
    //char *ptr = test[0];
    //strcpy(ptr,"TABSSS"); //strcpy takes Pointer not value. Updates value of pointer.
    //strcpy(test[0],"TESTIES");
  //
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
    Serial.println(msg_str);
}
void logVars(char* f_string, char* str_arr[], int str_size) //Function params: char* means char[size_of_input][1] | Only one character stored at each index
{
    char **args_arr=str_arr; ///make reference to pointer for naming conveniece. Str_arr is already a pointer so when we make another we add another asterisk *
    char ***arg_ptr=&args_arr;
    char f_copy[strlen(f_string)+1];
    
    char msg_str[strlen(f_string)+countMaxStrinArr(arg_ptr)+2];
    strcpy(f_copy,f_string);
    strcpy(msg_str,"");
    char* token=strtok(f_copy," "); // strtok automatically frees and replaces pointer for String Literal
    
    //
        //char test[10][10];
        //char (*tp)[10][10] = &test; //Pointer to WHOLE array, noticing *tp which means taking values
        //char *ptr = test[0];
        //strcpy(ptr,"TABSSS"); //strcpy takes Pointer not value. Updates value of pointer.
        //strcpy(test[0],"TESTIES");
    //
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
        Serial.println(msg_str);
}
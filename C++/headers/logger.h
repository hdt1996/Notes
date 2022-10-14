#define DEV 0
#define LOG_HELPER char helper_str[200]
#if DEV == 0
    #define LOG_STR(str_literal) printf(str_literal)
    #define LOG_FSTR_TYPE(combined_str) printf("%s",combined_str)
    #define INIT_LOGGER ;

#elif DEV == 1
    #define LOG_STR(str_literal) Serial.print(str_literal)
    #define LOG_FSTR_TYPE(combined_str) Serial.print(combined_str)
    #define INIT_LOGGER Serial.begin(9600);
#endif
#define LOG_FSTR(fstr, arg, helper) memset(helper, 0, sizeof(helper)); sprintf(helper,fstr,arg); LOG_FSTR_TYPE(helper); 

namespace Logger
{
    namespace CharArrays
    {
        int countLengthCharArr(char*** str_arr);
        char** build2dArraybyStrLiteral(char* arg_string, const char* delim);
    };

    void logVars(char* f_string, char** str_arr, int str_size);
    void logLits(const char* f_string, const char* args_str, int str_size);

}
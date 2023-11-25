#ifndef USSR_COM_H
#define USSR_COM_H 

#include <stdio.h>
#include <stdlib.h>
#include <unistdio.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

/*boolean macros*/
#define false (uint8_t)1 
#define true (uint8_t)0 
#define FALSE false 
#define TRUE true 

typedef uint8_t err_flag;

enum{ 
    FG_OK = 0, 
    ERR_NULL, ERR_ALLOC, ERR_REALLOC, ERR_VALS, WA_NOTNULL, ERR_TYPE,
    ARR_NULL, ARR_ALLOC, ARR_REALLOC, ARR_VALS, ARR_NOTNULL, ARR_APP,
    STR_NULL, STR_ALLOC, STR_REALLOC, STR_VALS, STR_NOTNULL, STR_APP,
};

#define ARR_OK FG_OK //array
#define STR_OK FG_OK


typedef enum ussr_types{
    ur_null=0, ur_char, ur_str, ur_int64, ur_uint64, ur_float, ur_double, ur_array,
}ussr_type;

extern uint8_t realloc_str_coeff;


#endif 

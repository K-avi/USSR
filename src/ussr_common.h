#ifndef USSR_COM_H
#define USSR_COM_H 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h> //fuck windows 
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
    CAT_NULL, CAT_ALLOC, CAT_REALLOC, CAT_VALS, CAT_NOTNULL, CAT_APP,
    DUP_NULL, DUP_ALLOC, DUP_REALLOC, DUP_VALS, DUP_NOTNULL, DUP_APP,
    PR_NULL, PR_ALLOC, PR_REALLOC, PR_VALS, PR_NOTNULL, PR_APP,
    TAB_NULL, TAB_ALLOC, TAB_REALLOC, TAB_VALS, TAB_NOTNULL, TAB_APP,
};

#define ARR_OK FG_OK //array
#define STR_OK FG_OK //string 
#define CAT_OK FG_OK //concatenate functions 
#define PR_OK FG_OK //print 
#define TAB_OK FG_OK //str tab thing 

extern uint8_t realloc_str_coeff;
extern uint8_t realloc_strtab_coeff;


#endif 

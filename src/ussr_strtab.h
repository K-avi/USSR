#ifndef USSR_STRTAB_H 
#define USSR_STRTAB_H 

#include "ussr_basic.h"
#include "ussr_common.h"
#include <stdint.h>
#include <stdio.h>

/*
usstr strtab will make copies of strings when appened to and NOT 
references of string  cuz I don't want multiple references to the same 
string moving aroung. 
*/

typedef struct s_ussr_strtab{
    uint32_t cur_in; 
    uint32_t max; 

    S_USSR_STRING * elems; 
}S_USSTRTAB; 

extern err_flag init_usstrtab(S_USSTRTAB * tab, uint32_t elems);
extern err_flag free_usstrtab(S_USSTRTAB * tab);
extern err_flag append_usstrtab(S_USSTRTAB * tab, const S_USSR_STRING * usstr);
extern err_flag fprint_usstrtab(FILE * flux, const S_USSTRTAB * tab);

#endif 

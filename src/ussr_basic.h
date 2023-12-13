#ifndef USSR_STRING_H
#define USSR_STRING_H 

#include "ussr_common.h"


typedef struct s_ussr_string{
    uint32_t cur_in ;
    uint32_t max;

    uint8_t * elems; 
}S_USSR_STRING ;

//to avoid invalid read warnings :0 
#define declare_usstr(usstr) {(usstr).cur_in=0;(usstr).elems=NULL;(usstr).max=0;}

typedef S_USSR_STRING  S_USSTR; //shorter name 

extern err_flag init_ussr_string(S_USSR_STRING * ussr_str , uint32_t size);
extern err_flag free_ussr_string(S_USSR_STRING * ussr_str);
extern err_flag append_ussr_string(S_USSR_STRING * ussr_str, uint8_t elem);

#endif 


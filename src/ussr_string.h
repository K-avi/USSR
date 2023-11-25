#ifndef USSR_STRING_H
#define USSR_STRING_H 

#include "ussr_common.h"


typedef struct s_ussr_string{
    uint32_t cur_in ;
    uint32_t max;

    uint8_t * elems; 
}S_USSR_STRING ;

extern err_flag init_ussr_string(S_USSR_STRING * ussr_str , uint32_t size);
extern err_flag free_ussr_string(S_USSR_STRING * ussr_str);
extern err_flag append_ussr_string(S_USSR_STRING * ussr_str, uint8_t elem);

extern err_flag fprint_ussr_str(FILE * f, S_USSR_STRING * ussr_string);
#define print_ussr_str(ussr_string) fprint_ussr_str(stdout, (ussr_string))
//maybe an actual print function is better 

#endif 


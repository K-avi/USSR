#ifndef USSR_PRINT_H 
#define USSR_PRINT_H 

#include "ussr_common.h"
#include "ussr_basic.h"

extern err_flag ussr_variadic_fprint(FILE * f, uint32_t nba , ...);

extern err_flag fprint_ussr_str(FILE * f, const S_USSR_STRING * ussr_string);
#define print_ussr_str(ussr_string) fprint_ussr_str(stdout, (ussr_string))
//maybe an actual print function is better 

#endif 

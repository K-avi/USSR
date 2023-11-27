#ifndef USSR_CONV_H
#define USSR_CONV_H 

#include "ussr_common.h"
#include "ussr_basic.h"

extern err_flag c_str_to_ussr_str(S_USSR_STRING * ussr_str, const char * c_str); 
extern err_flag ussr_str_to_c_str(const S_USSR_STRING * ussr_str, char ** c_str);

#endif 


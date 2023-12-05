#ifndef USSR_REDEF_H
#define USSR_REDEF_H 

#include "ussr_common.h"
#include "ussr_basic.h"

extern err_flag ussr_strlen(S_USSR_STRING * ustr, uint32_t * ret);
extern err_flag ussr_strchr(const S_USSR_STRING * usstr, uint8_t ch , uint8_t ** ret );
extern err_flag ussr_strcmp(S_USSR_STRING * usstr1 , S_USSR_STRING * usstr2, uint8_t * ret);


err_flag ussr_strcoll( const S_USSR_STRING * usstr1, const S_USSR_STRING * usstr2, int8_t * ret); 
//not done 
#endif 

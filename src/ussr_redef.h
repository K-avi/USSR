#ifndef USSR_REDEF_H
#define USSR_REDEF_H 

#include "ussr_common.h"
#include "ussr_basic.h"

<<<<<<< HEAD
extern err_flag ussr_strlen( const S_USSR_STRING * ustr, uint32_t * ret);
extern err_flag ussr_strcmp(S_USSR_STRING * usstr1 , S_USSR_STRING * usstr2, uint8_t * ret);


extern err_flag ussr_strcspn(const S_USSR_STRING * usstr,  char * rejectedCharacters, size_t * ret);
extern err_flag ussr_strfry(S_USSR_STRING * usstr);

extern err_flag ussr_strpbrk(const S_USSR_STRING * usstr, char * searched, int32_t * ret);
extern err_flag ussr_strchr(const S_USSR_STRING * usstr, const char searched, int32_t * ret);

extern err_flag ussr_strspn(const S_USSR_STRING * usstr , char * acceptedCharacters, size_t * ret);
extern err_flag ussr_strstr(const S_USSR_STRING * usstr, const char * substr, int32_t * index);
=======
extern err_flag ussr_strlen(S_USSR_STRING * ustr, uint32_t * ret);
extern err_flag ussr_strchr(const S_USSR_STRING * usstr, uint8_t ch , uint8_t ** ret );
extern err_flag ussr_strcmp(S_USSR_STRING * usstr1 , S_USSR_STRING * usstr2, uint8_t * ret);
>>>>>>> 8ebd5f9e0f590dca59865e47582df5a923b362dc


err_flag ussr_strcoll( const S_USSR_STRING * usstr1, const S_USSR_STRING * usstr2, int8_t * ret); 
//not done 
#endif 

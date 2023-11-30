#include "ussr_redef.h"
#include "ussr_basic.h"
#include "ussr_common.h"
#include "ussr_misc.h"
#include <stdint.h>


err_flag ussr_strlen(S_USSR_STRING * ustr, uint32_t * ret){
    /* 
    strlen equivalent
    kinda useless lol 
    */
    if(!ustr){
        ussr_report_err("ussr_strlen", STR_NULL);
        return STR_NULL;   
    }
    if(!ret){
        ussr_report_err("ussr_strlen", STR_VALS);
        return STR_VALS;   
    }

    *ret = ustr->cur_in;

    return STR_OK; 
}//not tested ; prolly ok 

err_flag ussr_strchr(const S_USSR_STRING * usstr, uint8_t ch , uint8_t ** ret ){
    /*
    strchr equivalent

    usstr -> not null; initialized 
    ch -> 
    ret -> not null
    */
    if(!usstr){
        ussr_report_err("ussr_strchr usstr", STR_NULL); 
        return STR_NULL;
    }
    if(!usstr->elems){
        ussr_report_err("ussr_strchr usstr->elems", STR_NULL); 
        return STR_NULL;
    }
    if(!ret){
        ussr_report_err("ussr_strchr ret", STR_NULL);
        return STR_NULL;
    }

    uint8_t * tmp = usstr->elems;
    while(tmp < &usstr->elems[usstr->cur_in]){
    //fancy while loop :O
        if(*tmp == ch){
            *ret = tmp;
            return STR_OK; 
        }
        tmp ++ ;
    }
    *ret = NULL; 
    return STR_OK;
}//not tested; prolly ok

err_flag ussr_strcmp(S_USSR_STRING * usstr1 , S_USSR_STRING * usstr2, uint8_t * ret){
    /*
    strcmp implem

    usstr1 -> usstr; can be null; can be unitialized 
    usstr2 -> -/- 

    ret -> return value not null 
    */
    if(!ret){
        ussr_report_err("ussr_strcmp ret", STR_NULL); 
        return STR_NULL;
    }
    if(! (usstr1 && usstr2) ){
        ussr_report_warning("ussr_strcmp usstr", STR_NULL); 
        *ret = FALSE; 
        return STR_OK;
    }
    if(! (usstr1->elems && usstr2->elems)){
        ussr_report_warning("ussr_strcmp elems", STR_NULL); 
        *ret = FALSE; 
        return STR_NULL;
    }
    

    if(usstr1->cur_in != usstr2->cur_in){
        *ret = FALSE ; 
        return STR_OK;
    }

    uint8_t * tmp1 = usstr1->elems, *tmp2 = usstr2->elems; 
    while(tmp1 < &usstr1->elems[usstr1->cur_in]){

        if(! (*tmp1 == *tmp2)){
            *ret = FALSE; 
            return STR_OK;
        }
        tmp1++;
        tmp2++;
    }

    *ret = TRUE;
    return STR_OK;
}//not tested 


err_flag ussr_strcoll( const S_USSR_STRING * usstr1, const S_USSR_STRING * usstr2, int8_t * ret){
    /*
    strcoll reimpl kinda useless 
    usstr1 -> can be NULL, can be uninitialized , 
    usstr2 -> can be NULL, can be unititialized
    ret -> not null 
    */
 /*   if(!ret){
        ussr_report_err("ussr_strcmp ret", STR_NULL); 
        return STR_NULL;
    }
    if(! (usstr1) ){
        ussr_report_warning("ussr_strcmp usstr", STR_NULL); 
        *ret = ; 
        return STR_OK;
    }
    if(! (usstr1->elems && usstr2->elems)){
        ussr_report_warning("ussr_strcmp elems", STR_NULL); 
        *ret = FALSE; 
        return STR_NULL;
    }
*/

    return STR_OK;
}//not done ; checkout what strcoll SHOULD do closer

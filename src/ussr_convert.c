#include "ussr_convert.h"
#include "ussr_common.h"
#include "ussr_misc.h"

err_flag ussr_str_to_c_str(const S_USSR_STRING * ussr_str, char ** c_str){
    /*
    ussr_str -> non null; initialized 
    c_str -> non null ; *c_str unallocated 
    */
    if(!ussr_str){
        ussr_report_err("ussr_str_to_c_str ussr_str", STR_NULL);
        return STR_NULL;
    }
    if(!c_str){
        ussr_report_err("ussr_str_to_c_str c_str", STR_NULL);
        return STR_NULL;
    }
    if(*c_str){
        ussr_report_warning("ussr_str_to_c_str", STR_NOTNULL); 
    }

    *c_str = malloc((ussr_str->cur_in + 1 )* sizeof(char) );
    if(!*c_str){
        ussr_report_err("ussr_str_to_c_str", STR_ALLOC);
        return STR_ALLOC;
    }

    memcpy(*c_str, ussr_str->elems, sizeof(char) * ussr_str->cur_in);
    (*c_str)[ussr_str->cur_in ] = '\0';
    return STR_OK;
}//tested ; possibly wrong 

err_flag c_str_to_ussr_str(S_USSR_STRING * ussr_str, const char * c_str){
    /*
    ussr_str -> non null; non initialized
    c_str -> non null ; initialized ; null char terminated
    */
    if(!ussr_str){
        ussr_report_err("c_str_to_ussr_str ussr_str", STR_NULL);
        return STR_NULL;
    }
    if(!c_str){
        ussr_report_err("c_str_to_ussr_str c_str", STR_NULL);
        return STR_NULL;
    }

    uint32_t str_length = strlen(c_str);

    err_flag failure = init_ussr_string(ussr_str, (uint32_t) (1.5 * str_length) );
    if(failure){
        ussr_report_err("c_str_to_ussr_str", failure); 
        return failure;
    }

    memcpy(ussr_str->elems, c_str, str_length * sizeof(char));

    ussr_str->cur_in = str_length;

    return STR_OK;
}//tested ; seems ok 

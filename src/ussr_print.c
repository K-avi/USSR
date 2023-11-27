#include "ussr_print.h"
#include "ussr_basic.h"
#include "ussr_common.h"
#include "ussr_misc.h"
#include <stdarg.h>
#include <stdint.h>



err_flag fprint_ussr_str(FILE * f, S_USSR_STRING * ussr_string){
    /*
    Basic non variadic print function; 
    takes 
    f -> flux pointer , not null 
    ussr_string -> usstring pointer, not null, initialized

    tries as much as possible to return warning and not errors
    */
    if(!f){
       fprintf(stderr, "warning at : fprint_ussr_str, file pointer is NULL\nprinting to sdtout\n");
    }
    if(!ussr_string){
        if(!f){
            fprintf(stderr, "warning at : fprint_ussr_str ussr_string is NULL\n");
            return STR_OK;
        }else{
            fprintf(f, "warning at : fprint_ussr_str ussr_string is NULL\n");
            return STR_OK;
        }
    }
    if(!ussr_string->elems){
        if(!f){
            fprintf(stderr, "warning at : fprint_ussr_str ussr_string->elems is NULL\n");
            return STR_OK;
        }else{
            fprintf(f, "warning at : fprint_ussr_str ussr_string->elems is NULL\n");
            return STR_OK;
        }
    }
    if(!f){
        char buff[ussr_string->cur_in + 1 ]; //c11 or higher ;(
        memcpy(buff, ussr_string->elems, ussr_string->cur_in);
        //maybe use malloc and don't do the implicit alloca call idk
        buff[ussr_string->cur_in + 1 ] = '\0';

        fprintf(stdout , "%s\n",buff);
    }else{
        char buff[ussr_string->cur_in + 1 ]; //c11 or higher ;(
        memcpy(buff, ussr_string->elems, ussr_string->cur_in);
        //maybe use malloc and don't do the implicit alloca call idk
        buff[ussr_string->cur_in ] = '\0';

        fprintf(f , "%s\n",buff);
    }
    return STR_OK;
}//messy as fuck; tested; seems ok



err_flag ussr_variadic_fprint(FILE * f, uint32_t nba , ...){
    /*
    */
    if(!nba){
        ussr_report_warning("ussr_fprint_var", PR_VALS); 
        return PR_OK;
    }
    if(!f){
        ussr_report_warning("ussr_fprint_var", PR_NULL); 
        return PR_OK;
    }

    va_list parameters ; 
    va_start(parameters, nba);

    for(uint32_t i = 0 ; i < nba ; i ++){

        S_USSR_STRING * tmp_elem = (S_USSR_STRING *) va_arg(parameters, S_USSR_STRING*); 
        err_flag failure = fprint_ussr_str(f,  tmp_elem);
        if(failure){
            ussr_report_err("ussr_fprint_var", failure); 
            return failure;
        }
    }
    return PR_OK;
}

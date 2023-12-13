#include "ussr_basic.h"
#include "ussr_common.h"
#include "ussr_misc.h"

/* STRING PRIMITIVES */
err_flag init_ussr_string(S_USSR_STRING * ussr_str , uint32_t size){
    /*
    ussr_str -> non null non initialised ussr_str pointer 
    size -> uint32_t > 0 
    */
    if(!ussr_str){//ussr_str is null
        ussr_report_err("init_ussr_string", STR_NULL);
        return STR_NULL;
    }
    if(!size){//size == 0 
        ussr_report_err("init_ussr_string", STR_VALS); 
        return STR_VALS;
    }
    if(ussr_str->elems)ussr_report_warning("init_ussr_string", STR_NOTNULL); 
    //report memleaks

    //actual alloc lol
    ussr_str->elems = (uint8_t*) calloc(size, sizeof(uint8_t));
    if(!ussr_str->elems){
        ussr_report_err("init_ussr_string", STR_ALLOC); 
        return STR_ALLOC;
    }

    ussr_str->cur_in = 0 ; 
    ussr_str->max = size; 

    return STR_OK;
}//tested ; ok 


err_flag free_ussr_string(S_USSR_STRING * ussr_str){
    /*
    ussr_str -> ussr_str ptr, can be NULL
    (reports warning if finds null pointer)
    */
    if(!ussr_str){
        ussr_report_warning("free_ussr_string ussr_str pointer", STR_NULL);
        return STR_OK;
    }
    if(!ussr_str->elems){
        ussr_report_warning("free_ussr_string ussr_str->elems pointer", STR_NULL);
        return STR_OK;
    }

    free(ussr_str->elems); 
    ussr_str->elems = NULL; 
    ussr_str->cur_in = 0; 
    ussr_str->max = 0 ; 
    
    return STR_OK;
}//tested; ok

static err_flag realloc_ussr_string(S_USSR_STRING * ussr_str, uint32_t realloc_coeff){
    /*
    ussr_str -> initialized; not null ussr_str ptr 
    realloc_coeff -> integer >= 0 
    */
    if(!ussr_str){//nullptr check 
        ussr_report_err("realloc_ussr_string", STR_NULL);
        return STR_NULL;
    }
    if(realloc_coeff == 0 ){//free case 
        if(ussr_str->elems)free(ussr_str->elems); 
        ussr_str->elems = NULL;
        ussr_str->max = 0 ; 
        ussr_str->cur_in = 0 ;  
        return STR_OK;
    }

    ussr_str->elems = (uint8_t*)realloc(ussr_str->elems, sizeof(uint8_t) * realloc_coeff * ussr_str->max);
    if(!ussr_str->elems){
        ussr_report_err("realloc_ussr_string", STR_REALLOC); 
        return STR_REALLOC;
    }
    ussr_str->max *= realloc_coeff;

    return STR_OK;
}//tested; ok 

err_flag append_ussr_string(S_USSR_STRING * ussr_str, uint8_t elem){
    /*
    ussr_str -> initialized; not null ussr_str ptr ; modified by call
    elem -> any character
    */
    if(!ussr_str){//nullptr check 
        ussr_report_err("append_ussr_string ussr_str ptr", STR_NULL);
        return STR_NULL;
    }
    if(!ussr_str->elems){//nullptr check 
        ussr_report_err("append_ussr_string ussr_str->elems ptr", STR_NULL);
        return STR_NULL;
    }
    if(ussr_str->cur_in == ussr_str->max ){//realloc case
        err_flag failure = realloc_ussr_string(ussr_str, realloc_str_coeff);
        if(failure){
            ussr_report_err("append_ussr_string", STR_REALLOC); 
            return STR_REALLOC;
        }
    }

    ussr_str->elems[ussr_str->cur_in++] = elem ;
    return STR_OK;
}//tested; ok 

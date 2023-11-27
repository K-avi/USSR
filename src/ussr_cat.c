#include "ussr_cat.h"
#include "ussr_basic.h"
#include "ussr_common.h"
#include "ussr_misc.h"
#include <stdarg.h>

static err_flag helper_cat(S_USSR_STRING * dest , const S_USSR_STRING * src){
    /*
    static cat helper
    */
    if(!dest){
        ussr_report_err("helper_cat dest", CAT_NULL); 
        return CAT_NULL;
    }
    if(!src){
        ussr_report_err("helper_cat src", CAT_NULL); 
        return CAT_NULL;
    }
    if(dest->max < src->cur_in + dest->cur_in){
        ussr_report_err("helper_cat", CAT_VALS); 
        return CAT_VALS;
    }

    memcpy(&dest->elems[dest->cur_in], src->elems, src->cur_in * sizeof(uint8_t));
    dest->cur_in += src->cur_in;

    return CAT_OK;
}//tested; seems ok ; 


err_flag ussr_cat(uint32_t nba, S_USSR_STRING * dest, ...){
    /*
    nba  -> argument count 
    dest -> ussr_string pointer; initialized; not null
    */
    if(!dest){
        ussr_report_err("ussr_cat dest", CAT_NULL); 
        return CAT_NULL;
    }
    if(!nba){
        ussr_report_warning("ussr_cat", CAT_VALS); 
        return CAT_OK;
    }
   
    va_list parameters; 
    va_start(parameters, dest);

    uint64_t total_size = dest->cur_in ; 
    S_USSR_STRING * refs[nba];

    for(uint32_t i = 0 ; i < nba ; i++){
       S_USSR_STRING * src_extracted =  (S_USSR_STRING *) va_arg(parameters, S_USSR_STRING * );
       if(!src_extracted ){
            ussr_report_err("ussr_cat src_extracted", CAT_NULL); 
            return CAT_NULL;
       }
       if(!src_extracted->elems){
            ussr_report_err("ussr_cat src_extracted->elem", CAT_NULL); 
            return CAT_NULL;
       }
       total_size += src_extracted->cur_in;
       refs[i] = src_extracted;
    }
    va_end(parameters);

    dest->elems = realloc(dest->elems, (total_size * 1.1) * sizeof(uint8_t));  
    dest->max = total_size * 1.1;

    if(!dest->elems){
        ussr_report_err("ussr_cat", CAT_REALLOC);
        return CAT_REALLOC;
    }

    for(uint32_t i = 0 ; i < nba ; i ++){
        err_flag failure = helper_cat(dest, refs[i]);
        if(failure){
            ussr_report_err("ussr_cat", failure); 
            return failure;
        }
    }
    return CAT_OK;
}//tested; seems ok  

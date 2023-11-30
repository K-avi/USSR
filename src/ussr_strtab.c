#include "ussr_strtab.h"
#include "ussr_basic.h"
#include "ussr_common.h"
#include "ussr_dup.h"
#include "ussr_misc.h"

err_flag init_usstrtab(S_USSTRTAB * tab, uint32_t elems){
    /*
    tab -> not null ; not initialized
    */

    if(!tab){
        ussr_report_err("init_usstrtab", TAB_NULL);
        return TAB_NULL;
    }
    if(tab->elems){
        ussr_report_warning("init_usstrtab", TAB_NOTNULL);
    }
    if(elems){
        ussr_report_warning("init_usstrtab", TAB_VALS); 
        return TAB_OK;
    }

    tab->elems = calloc(elems , sizeof(S_USSR_STRING ));
    if(!tab->elems){
        ussr_report_err("init_usstrtab", TAB_ALLOC); 
        return TAB_ALLOC;
    }
    return TAB_OK;
}//not tested ; don't know if I should init every str in tbh 

err_flag free_usstrtab(S_USSTRTAB *tab){
    /*
    tab
    frees every string contained in the tab so watch out 
    */
    if(!tab){
        ussr_report_warning("free_usstrbtab", TAB_NULL); 
        return TAB_OK; 
    }
    if(!tab->elems){
        ussr_report_warning("free_usstrbtab", TAB_NULL); 
        return TAB_OK; 
    }

    for(uint32_t i = 0 ; i < tab->cur_in ; i ++){
        if(tab->elems[i].cur_in){
            free(tab->elems[i].elems);
            tab->elems[i].elems = NULL; 
        }
    }

    free(tab->elems);
    tab->elems = NULL; 
    tab->cur_in = 0;
    tab->max = 0 ; 

    return TAB_OK;  
}//maybe redesign idk I might wanna pass ussr_strings references tbh 

static err_flag realloc_usstrtab(S_USSTRTAB * tab){
    /*
    tab -> not null ; initialized; 
    */
    if(!tab){
        ussr_report_err("realloc_usstrtab", TAB_NULL); 
        return TAB_NULL;
    }
    if(!tab->elems){
        ussr_report_warning("realloc_usstrtab", TAB_NULL); 
        return TAB_OK;
    }

    tab->elems = realloc(tab->elems, tab->max * sizeof(S_USSTRTAB) * realloc_strtab_coeff);
    if(!tab->elems){
        ussr_report_err("realloc_usstrtab", TAB_REALLOC); 
        return TAB_REALLOC;
    }
    tab->max *= realloc_strtab_coeff;

    return TAB_OK;
}//not tested

extern err_flag append_usstrtab(S_USSTRTAB * tab, S_USSR_STRING * usstr){
    /*
    tab -> not null ; initialized; 
    u
    */
    if(!tab){
        ussr_report_err("append_usstrbtab", TAB_NULL); 
        return TAB_NULL; 
    }
    if(!tab->elems){
        ussr_report_err("append_usstrbtab", TAB_NULL); 
        return TAB_NULL; 
    }
    if(!usstr){
        ussr_report_err("append_usstrbtab", STR_NULL); 
        return STR_NULL; 
    }
    if(!usstr->elems){
        ussr_report_warning("append_usstrbtab elems", STR_NULL); 
    }

    if(tab->cur_in == tab->max){
        err_flag failure = realloc_usstrtab(tab);
        if(failure){
            ussr_report_err("append_usstrbtab", failure); 
            return failure; 
        }
    }

    err_flag failure = ussr_dup(1, &tab->elems[tab->cur_in], usstr);
    if(failure){
        ussr_report_err("append_ussrtab", failure); 
        return failure;
    }

    tab->cur_in++;
    return TAB_OK;
}//not tested; likely wrong

extern err_flag fprint_usstrtab(FILE * flux, const S_USSTRTAB * tab){
    /*
    */
}


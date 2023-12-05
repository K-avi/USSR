#include "ussr_split.h"
#include "ussr_common.h"
#include "ussr_convert.h"
#include "ussr_misc.h"
#include "ussr_strtab.h"
#include <stdint.h>

err_flag usssr_strsplit(S_USSR_STRING * usstr, S_USSTRTAB * usstrtab , uint8_t chr){
    /*
    usstr -> not null; initialized 
    usstrtab -> not null;  (not initialized) | (initialized & empty)
    */
    if(!usstr){
        ussr_report_err("usstr_strsplit usstr", STR_NULL); 
        return STR_NULL;
    }
    if(!usstr->elems){
        ussr_report_err("usstr_strsplit usstr.elems", STR_NULL); 
        return STR_NULL;
    }
    if(!usstrtab){
        ussr_report_err("usstr_strsplit", TAB_NULL); 
        return TAB_NULL;
    }
    if(usstrtab->cur_in){
        ussr_report_err("usstr_strsplit", TAB_VALS); 
        return TAB_VALS;
    }

    if(!usstrtab->elems){
        err_flag failure = init_usstrtab(usstrtab, 10);
        if(failure){
            ussr_report_err("usstr_strsplit",  failure); 
            return failure;
        }
    }

    S_USSR_STRING tmp_usstr;    
    char * buff = calloc(usstr->cur_in, sizeof(uint8_t)); 
    uint32_t buff_size = 0 ; 
    uint8_t start = usstr->elems[0]; 

    for(uint32_t i = 0 ; i < usstr->cur_in ; i++){
        if(usstr->elems[i] == chr ){
            if(buff_size!=0){
                buff[buff_size] = '\0';
                printf("buff : %s i=%u\n",buff,i);
                //turns tmp_string into actual string
                err_flag failure = c_str_to_ussr_str(&tmp_usstr, buff);
                if(failure){free(buff);ussr_report_err("usstr_strsplit" , failure); return failure;}

                //appends to usstr
                failure = append_usstrtab(usstrtab, &tmp_usstr);
                if(failure){free(buff);ussr_report_err("usstr_strsplit", failure); return failure;}

                memset((void*)buff, 0, usstr->cur_in * sizeof(uint8_t));
                free_ussr_string(&tmp_usstr);
            }
            start = i;
            buff_size = 0 ; 
        }else{
            buff[buff_size] = usstr->elems[i];
            buff_size++; 
        }
    }

    if(start != usstr->cur_in){
        buff[buff_size] = '\0';
        //turns tmp_string into actual string
        err_flag failure = c_str_to_ussr_str(&tmp_usstr, buff);
        if(failure){free(buff);ussr_report_err("usstr_strsplit", failure); return failure;}

        //appends to usstr
        failure = append_usstrtab(usstrtab, &tmp_usstr);
        if(failure){free(buff);ussr_report_err("usstr_strsplit", failure); return failure;}

        memset((void*)buff, 0, usstr->cur_in * sizeof(uint8_t));
        free_ussr_string(&tmp_usstr);
    }

    free(buff);
    return STR_OK; 
}//tested; seems ok; maybe rewrite with the memcpy thing 

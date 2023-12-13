#include "ussr_redef.h"
#include "ussr_basic.h"
#include "ussr_common.h"
#include "ussr_misc.h"


err_flag ussr_strlen(const S_USSR_STRING * ustr, uint32_t * ret){
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
}//tested ; seems ok 

<<<<<<< HEAD
=======
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
}//tested; ok
>>>>>>> 8ebd5f9e0f590dca59865e47582df5a923b362dc

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
}//tested , works


err_flag ussr_strcspn(const S_USSR_STRING * usstr,  char * rejectedCharacters, size_t * ret){
    /*
    usstr -> not null, initialized 
    rejectedCharacters -> can be null ; recommended to pass string litteral 
<<<<<<< HEAD

    returns the size of the longest substring of usstr not containing 
    any rejected char 
=======
>>>>>>> 8ebd5f9e0f590dca59865e47582df5a923b362dc
    */
    if(!ret){
        ussr_report_err("ussr_strcspn", ERR_NULL);
        return ERR_NULL;
    }
    if(!usstr){
        ussr_report_err("ussr_strcspn", STR_NULL);
        return STR_NULL;
    }
    if(!rejectedCharacters){
        ussr_report_warning("ussr_strcspn", STR_NULL);
        *ret = usstr->cur_in;
        return STR_OK;
    }

    for(uint32_t i = 0 ; i < usstr->cur_in ; i++){

        uint8_t c = usstr->elems[i];
        char * tmps2 = rejectedCharacters;
        while (*tmps2) {
            if(c == *tmps2){
                *ret =  &usstr->elems[i] - usstr->elems;
                return STR_OK;
            }
            tmps2 ++ ; 
        }
    }

    *ret = usstr->cur_in;
    return STR_OK; 
<<<<<<< HEAD
}//tested ; ok
=======
}//not tested ; maybe wrong 
>>>>>>> 8ebd5f9e0f590dca59865e47582df5a923b362dc


err_flag ussr_strfry(S_USSR_STRING * usstr){
    /*
    usstr -> not null ; initialized | !initialized
<<<<<<< HEAD

    makes a palindrome of usstr idk why this is in the 
    string.h lib tbh 
=======
>>>>>>> 8ebd5f9e0f590dca59865e47582df5a923b362dc
    */
    if(!usstr){
        ussr_report_err("ussr_strfry", STR_NULL); 
        return STR_NULL; 
    }
    if(! (usstr->elems || usstr->cur_in == 0 ) ){
        ussr_report_warning("ussr_strfry", STR_NULL); 
        return STR_OK;
    }

    for(uint32_t i = 0 ; i < usstr->cur_in ; i ++){
        uint8_t c = usstr->elems[i]; 

        uint32_t r_index = rand()%usstr->cur_in;

        usstr->elems[i] = usstr->elems[r_index];
        usstr->elems[r_index] = c;
    }

    return STR_OK;
<<<<<<< HEAD
}// tested ; ok 
=======
}//not tested ; prolly ok 
>>>>>>> 8ebd5f9e0f590dca59865e47582df5a923b362dc


err_flag ussr_strpbrk(const S_USSR_STRING * usstr, char * searched, int32_t * ret){
    /*
    src -> not null; initialized;
    searched -> not null 
    ret -> not null 

    returns index of first occurence instead of char * 
    because of reasons. 
<<<<<<< HEAD

    returns index of first occurence in searched or -1 
=======
>>>>>>> 8ebd5f9e0f590dca59865e47582df5a923b362dc
    */
    if(!usstr){
        ussr_report_err("ussr_strpbrk usstr", STR_NULL);
        return STR_NULL ;
    }
    if(!usstr->elems){
        ussr_report_err("ussr_strpbrk usstr.elems", STR_NULL);
        return STR_NULL ;
    }
    if(!searched){
        ussr_report_warning("ussr_strpbrk usstr.elems", STR_NULL);
        *ret = -1 ; 
        return STR_OK;
    }

    for(uint32_t i = 0 ; i < usstr->cur_in; i++){
        
        register uint8_t c = usstr->elems[i];
        char * tmp = searched; 

        do{
            if(*tmp == c){
                *ret = i;
                return STR_OK;
            }

            tmp++;
        }while(*tmp); 
    }

    *ret = -1; 
    return STR_OK;
<<<<<<< HEAD
}// tested; ok 

err_flag ussr_strchr(const S_USSR_STRING * usstr, const char searched, int32_t * ret){
    /*
    src -> not null && initialized
    ret -> not null 

    strchr equivalent ; returns the index and not the raw pointer bc of 
    reasons
=======
}//not tested

err_flag ussr_strrchr(const S_USSR_STRING * usstr, const char searched, int32_t * ret){
    /*
    src -> not null && initialized
    ret -> not null 
>>>>>>> 8ebd5f9e0f590dca59865e47582df5a923b362dc
    */
    if(!usstr){
        ussr_report_err("ussr_strpbrk usstr", STR_NULL);
        return STR_NULL ;
    }
    if(!usstr->elems){
        ussr_report_err("ussr_strpbrk usstr.elems", STR_NULL);
        return STR_NULL ;
    }
    if(!ret){
        ussr_report_err("ussr_strpbrk usstr.elems", ERR_NULL);
        return ERR_NULL;
    }

    for(uint32_t i = usstr->cur_in ; i > 0 ; i++ ){
        if(usstr->elems[i] == searched){
            *ret = i ; 
            return STR_OK;
        }
    }

    *ret = -1; 
    return STR_OK;
<<<<<<< HEAD
}//tested;  ok 


err_flag ussr_strspn(const S_USSR_STRING * usstr , char * acceptedCharacters, size_t * ret){
    /*
        usstr -> not null & (initialized | not initialized) (warning if not initialized)
        accepted -> null | not null (warning if null)
        ret -> not null 

        returns size of longest substr w specified chars 
    */
    if(!usstr){
        ussr_report_err("ussr_strspn", STR_NULL); 
        return STR_NULL;
    }
    if(!ret){
        ussr_report_err("ussr_strspn", ERR_NULL); 
        return ERR_NULL;
    }
    if(!usstr->elems){
        ussr_report_warning("ussr_strspn", STR_NULL); 
        *ret = 0 ; 
        return STR_OK;
    }
    if(!acceptedCharacters){
        ussr_report_warning("ussr_strspn", STR_NULL); 
        *ret = usstr->cur_in ; 
        return STR_OK;
    }
    
    for(uint32_t i = 0 ; i < usstr->cur_in ; i++){

        uint8_t c = usstr->elems[i];
        char * tmps2 = acceptedCharacters;

        uint8_t accepted = FALSE; 
        while (*tmps2) {
            if(c == *tmps2){
                accepted = TRUE; 
                break;
            }
            tmps2 ++ ; 
        }
        if(!accepted){
            *ret = i;
            return STR_OK;
        }
    }
   
   *ret = usstr->cur_in;
   return STR_OK ;
}//not tested ; prolly ok 

extern err_flag ussr_strstr(const S_USSR_STRING * usstr, const char * substr, int32_t * index){
    /*
    usstr -> null | not null & initialized | not initialized (throws warnings)
    substr -> null | not null (throws warnings)

    index -> not null 
    */

    if(!index){
        ussr_report_err("ussr_strstr", ERR_NULL); 
        return STR_NULL;
    }
    if(!usstr){
        *index = -1; 
        ussr_report_warning("ussr_strstr", STR_NULL);
        return STR_OK;
    }
    if(!usstr->elems){
        *index = -1; 
        ussr_report_warning("ussr_strstr", STR_NULL);
        return STR_OK;
    }
    if(!substr){
        *index = -1; 
        ussr_report_warning("ussr_strstr", STR_NULL);
        return STR_OK;
    }

    uint32_t i = 0 ; 
    while(i < usstr->cur_in){
        int32_t start = i ; 
        const char * tmp = substr;

        while(tmp && *tmp == usstr->elems[i]){

            tmp++;
            i++;
        }
        if(!tmp){
            *index = start ; 
            return STR_OK;
        }
        i++;
    }

    *index = -1; 
    return STR_OK;
}//not tested ; might be wrong 
=======
}//not tested; prolly ok 

>>>>>>> 8ebd5f9e0f590dca59865e47582df5a923b362dc

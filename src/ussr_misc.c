#include "ussr_misc.h"
#include "ussr_common.h"


static inline char * str_flag(err_flag flag)
{

  switch (flag) 
  {
    case ERR_NULL: return "null pointer passed";
    case ERR_ALLOC: return "couldn't allocate memory";
    case ERR_REALLOC: return "couldn't reallocate memory";
    case ERR_VALS: return "value given not matching expected values";
    case WA_NOTNULL: return "pointer is not null"; 
   
    case ARR_NULL: return "null pointer passed as array struct pointer";
    case ARR_ALLOC: return "couldn't allocate memory to array elements";
    case ARR_REALLOC: return "couldn't reallocate arrays elements"; 
    case ARR_VALS: return "value given not matching expected values"; 
    case ARR_NOTNULL: return "array elements is not null"; 
    case ERR_TYPE : return "type passed is not valid"; 
    case ARR_APP : return "value couldn't be appened to the array";

    case STR_NULL : return "null pointer passed as USSR_STR struct pointer";
    case STR_ALLOC: return "couldn't allocate memory to S_USSR_ARRAY->elements";
    case STR_REALLOC: return "couldn't reallocate STR arrays elements"; 
    case STR_VALS: return "value given not matching expected values in string_basic function"; 
    case STR_NOTNULL: return "STRay elements is not null"; 
    case STR_APP : return "value couldn't be appened to the array";

    case CAT_NULL : return "null pointer passed in ussr_cat function";
    case CAT_ALLOC: return "couldn't allocate memory to S_USSR_ARRAY->elements in ussr_cat function";
    case CAT_REALLOC: return "couldn't reallocate memory to S_USSR_ARRAY->elements in ussr_cat function"; 
    case CAT_VALS: return "value given not matching expected values in str_cat function"; 
    case CAT_NOTNULL: return "str->elements is not null in cat function"; 
    case CAT_APP : return "value couldn't be appened to the string in cat function";

    case DUP_NULL : return "null pointer passed in ussr_dup function";
    case DUP_ALLOC: return "couldn't allocate memory to S_USSR_ARRAY->elements in ussr_dup function";
    case DUP_REALLOC: return "couldn't reallocate memory to S_USSR_ARRAY->elements in ussr_dup function"; 
    case DUP_VALS: return "value given not matching expected values in str_dup function"; 
    case DUP_NOTNULL: return "str->elements is not null in dup function"; 
    case DUP_APP : return "value couldn't be appened to the string in dup function";

    case PR_NULL : return "null pointer passed in ussr_print_var function";
    case PR_ALLOC: return "placeholder error";
    case PR_REALLOC: return "placeholder error"; 
    case PR_VALS: return "value given not matching expected values in ussr_print_var function"; 
    case PR_NOTNULL: return "placeholder error"; 
    case PR_APP : return "placeholder error";

    case TAB_NULL : return "null pointer passed as S_USSTRTAB";
    case TAB_ALLOC: return "couldn't allocate memory to S_USSRTAB->elements in ussr_dup function";
    case TAB_REALLOC: return "couldn't reallocate memory to S_USSRTAB->elements in ussr_dup function"; 
    case TAB_VALS: return "value given not matching expected values as tab function"; 
    case TAB_NOTNULL: return "tab->elements is not null"; 
    case TAB_APP : return "value couldn't be appened to the usstrtab";

    default : return "unknown error ; how did you get here?";
  }
}//ok

static inline void ussr_report( FILE * flux, const char * repport_msg, const char * error_msg ,
 err_flag flag){
    /*
    the real repport function of the project 
    every variant of it will rely on it 
    */
    if(! flux){
        fprintf(stderr,"ussr_report : NULL was passed for flux\n");
        return;
    }else if(!repport_msg){
        fprintf(stderr,"ussr_report : NULL was passed for repport_msg\n");
        return;
    }else if(!error_msg){
        fprintf(stderr,"ussr_report : NULL was passed for error_msg\n");
        return; 
    }
    fprintf(flux," %s : %s at %s\n",repport_msg, str_flag(flag), error_msg);
}

void ussr_report_err( const char * msg , err_flag flag){ 
  //could be a macro 
  ussr_report(stdout, "error", msg, flag);
}

void ussr_report_warning(const char * msg , err_flag flag){ 
  //could be a macro 
  ussr_report(stdout, "error", msg, flag);
}



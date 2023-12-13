#include "ussr_cat.h"
#include "ussr_common.h"
#include "ussr_dup.h"
#include "ussr_misc.h"
#include "ussr_basic.h"
#include "ussr_convert.h"
#include "ussr_print.h"
#include "ussr_redef.h"
#include "ussr_strtab.h"
#include "ussr_split.h"

#include <time.h>
int main(int argc, char ** argv){

	time_t t ;
	time(&t);

	srand(t);
	/*
	S_USSR_STRING u_test; 
	u_test.elems = NULL;

	char hi[] = "hello world :)\n";
	char * hey = NULL ; 
	
	c_str_to_ussr_str(&u_test, (char*)hi);

	//print_ussr_str(&u_test);

	ussr_str_to_c_str(&u_test, &hey);
	
	S_USSR_STRING u_test1, u_test2, u_test3;
	u_test1.elems = NULL;
	u_test2.elems = NULL;
	u_test3.elems = NULL;

	c_str_to_ussr_str(&u_test1, (char*)"salut mon pote");
	c_str_to_ussr_str(&u_test2, " comment ca va");
	c_str_to_ussr_str(&u_test3, " tu me dois de l'oseille\n");

	ussr_cat(3, &u_test, &u_test1, &u_test2, &u_test3);

	//print_ussr_str(&u_test);


	free(hey);

	S_USSR_STRING u_dup_test; 
	u_dup_test.elems = NULL; 

	ussr_dup(4, &u_dup_test, &u_test, &u_test1, &u_test2, &u_test3);

	ussr_variadic_fprint(stdout, 1,  &u_dup_test, &u_test1, &u_test2, &u_test3);

	uint32_t ret, ret1; 
	ussr_strlen(&u_dup_test, &ret);
	ussr_strlen(&u_test, &ret1);
	printf("len : %u %u\n",ret, ret1 );

	
	

	append_ussr_string(&u_test, 'p');
	printf("reT.curin %u %u\n", u_test.cur_in ,u_test.max );
	ussr_variadic_fprint(stdout, 1, &u_test);

	uint8_t * char_ret; 
	ussr_strchr(&u_test, 'z', &char_ret);

	printf("char ret: %p  %p %c\n", char_ret, &u_test.elems[4], u_test.elems[0]);
	

	free_ussr_string(&u_test);
	free_ussr_string(&u_test1);
	free_ussr_string(&u_test2);
	free_ussr_string(&u_test3);
	free_ussr_string(&u_dup_test);
	*/
	/*
	S_USSR_STRING str1, str2; 
	
	str1.elems = str2.elems = NULL; 

	c_str_to_ussr_str(&str1, "hayy: :::i'm:fine:3\n");
	c_str_to_ussr_str(&str2, "hayy :3\n");

	ussr_variadic_fprint(stdout, 2, &str1, &str2);
	//uint8_t val_strcmp; 
	//ussr_strcmp(&str1, &str2, &val_strcmp);
	//s("strcmp first call : %u\n" , val_strcmp);

	S_USSTRTAB tab; 
	tab.elems = NULL;
	tab.cur_in = tab.max = 0 ; 

	usssr_strsplit(&str1, &tab, ':');
	
	fprint_usstrtab(stdout, &tab);
	free_usstrtab(&tab);
	//S_USSR_STRING str3 ; 
	//c_str_to_ussr_str(&str3, "hay:3\n");
	//ussr_strcmp(&str1, &str3, &val_strcmp);

	//printf("strcmp scd call : %u\n" , val_strcmp);

	free_ussr_string(&str1);
	free_ussr_string(&str2);
	//free_ussr_string(&str3);
	*/

	//test of strpbrk : 

	//char * strprb_test = "aeuio";

	S_USSTR usstr_test ; 
	declare_usstr(usstr_test);

	
	c_str_to_ussr_str(&usstr_test, "kky");

	//size_t size=0; 

	//ussr_strcspn(&usstr_test, strprb_test, &size);

	//ussr_strfry(&usstr_test);
	//print_ussr_str(&usstr_test);

	int32_t ret_int = -1; 
	ussr_strpbrk(&usstr_test, "a", &ret_int); 

	printf("ret_int=%d\n", ret_int);

	free_ussr_string(&usstr_test);
	return 0 ; 
}

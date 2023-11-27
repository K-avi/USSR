#include "ussr_cat.h"
#include "ussr_common.h"
#include "ussr_dup.h"
#include "ussr_misc.h"
#include "ussr_basic.h"
#include "ussr_convert.h"
#include "ussr_print.h"

int main(int argc, char ** argv){

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

	free_ussr_string(&u_test);
	free_ussr_string(&u_test1);
	free_ussr_string(&u_test2);
	free_ussr_string(&u_test3);
	free_ussr_string(&u_dup_test);

	return 0 ; 
}

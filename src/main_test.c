#include "ussr_common.h"
#include "ussr_misc.h"
#include "ussr_string.h"
#include "ussr_convert.h"

int main(int argc, char ** argv){


	S_USSR_STRING u_test; 
	char hi[] = "hello world :)\n";
	char * hey; 
	
	c_str_to_ussr_str(&u_test, (char*)hi);

	print_ussr_str(&u_test);

	ussr_str_to_c_str(&u_test, &hey);

	printf("%s", hey);

	free_ussr_string(&u_test);

	return 0 ; 
}

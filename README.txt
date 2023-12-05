USSR stands for Ultime String System Replacement (the acronym 
doesn't mean much it's more of a joke than anything). 

C strings are weird so I want to a library for a "higher level" 
string system with more advanced functions. 
I'm doing this for fun on my spare time so I don't really 
care for the "normal" C library philosophy of not allocating 
stuff. This project really aims to implement "high level" operations 
on strings. 

if I finish the project I'll use it for string manipulation in C so 
it will be maintained. 


The main string structure will be wrapper around a straight forward
dynamic array : 

struct ussr_string{
    uint32_t arr_nbelem ;
    uint32_t arr_size ; 

    char * arr_ptr; 

}

Depending how good I think this string implementation is I might expand on it 
and implement a high level type system alongisde it 


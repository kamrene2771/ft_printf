#include "ft_printf.h"


int handle_char(int c){
    return ft_putchar(c);
}
int handle_str(char *str){
    return ft_putstr(str);
}
int handle_int(int nbr){
	char *number = ft_itoa(nbr);
	int len = handle_str(number);
	free(number);
	return len;
}
int handle_unsigned(unsigned int nbr){
	char *number = ft_itoa_base(nbr,"0123456789");
	int len = handle_str(number);
	free(number);
	return len;
}
int handle_hex(unsigned int nbr,char specipier){
	char *base;
	if ( specipier == 'x')
		base = "0123456789abcdef";
	else 
		base = "0123456789ABCDEF";
	char *number = ft_itoa_base(nbr,base);
	int len = handle_str(number);
	free(number);
	return len;
}
int handle_pointer(void *ptr){
	unsigned long addr = (unsigned long)ptr;
	char *hex = ft_itoa_base(addr,"0123456789abcdef");
	int len = handle_str("0x");
	len += handle_str(hex);
	free(hex);
	return len;
}
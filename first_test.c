#include <libc.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}
void	ft_putnbr(int n)
{
	long long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num < 10)
		ft_putchar(num + '0');
	else
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
}

int	howmanyper(const char *str)
{
	int	c;

	c = 0;
	while (*str)
	{
		if (*str == '%')
			c++;
		str++;
	}
	return (c);
}

const char *handle_str(const char *str, char *arg){
    str = str + 2;
	ft_putstr(arg);
    return str;
}
const char *handle_nbr(const char *str,int arg){
    str = str + 2;
	ft_putnbr(arg);
    return str;
}
const char *handle_char(const char *str,int arg){
    str = str + 2;
	ft_putchar(arg);
    return str;
}
const char *handle_ptr(const void *str,unsigned long arg){
	str +=2 ;
	convert_hex_ptr(arg);
	return str;
}
const char *handle_dec(const void *str,long arg){
	str +=2 ;
	ft_putnbr(arg);
	return str;
}
const char *handle_int(const void *str,int arg){
	str +=2 ;
	ft_putnbr(arg);
	return str;
}
const char *handle_udec(const void *str,unsigned long arg){
	str +=2 ;
	ft_putnbr(arg);
	return str;
}
const char *handle_hex(const void *str,int arg,char c){
	str +=2 ;
	if(!arg)
		ft_putchar('0');
	else
		convert_hex(arg,c);
	return str;
}
const char *handle_per(const char *str,int arg){
    str = str + 2;
	ft_putchar('%');
    return str;
}
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;
    
	count = howmanyper(str);
	va_start(args, str);
	i = 0;
	while (i++ < count)
	{
		if (*str == '%' && *(str + 1) == 's')
			str = handle_str(str,va_arg(args, char *));
		else if (*str == '%' && *(str + 1) == 'd')
			str = handle_nbr(str,va_arg(args,int));
        else if (*str == '%' && *(str + 1) == 'c')
			str = handle_char(str,va_arg(args,int));
		else if (*str == '%' && *(str + 1) == 'p')
		 	str = handle_ptr(str,(unsigned long)va_arg(args,int));
		else if (*str == '%' && *(str + 1) == 'd')
		 	str = handle_dec(str,(long)va_arg(args,int));
		else if (*str == '%' && *(str + 1) == 'i')
		 	str = handle_int(str,va_arg(args,int));
		else if (*str == '%' && *(str + 1) == 'u')
		 	str = handle_udec(str,(unsigned long)va_arg(args,int));
		else if (*str == '%' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		 	str = handle_hex(str,va_arg(args,int),*(str+1));
		else if (*str == '%' && *(str + 1) == '%')
			str = handle_per(str,va_arg(args,int));
		while (*str != '%' && *str)
			write(1, &(*str++), 1);
	}
	va_end(args);
	return (0);
}
int	main(void)
{
	//ft_printf("%s   %d this is hjwh jfwkljw %d   %s  %c %d  ", "had", 1337, 487, "dial L97ab",'v',4564897);
	void *ptr ;
	//printf("%d\n",(int)ptr);
	
	printf("%d\n",1234568795467894);
	ft_printf("%d\n",1234568795467894);

}

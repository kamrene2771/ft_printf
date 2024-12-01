#include "ft_printf.h"
#include <libc.h>

int ft_printf(const char *format, ...) 
{
    va_list args;
    int count = 0;
    int len = 0;

    va_start(args, format);
    while (*format) {
            if (*format == '%' && (*(format + 1) == '-' || (*(format + 1) == '0') || (*(format + 1) == '.')))
            {
                format++;
                count += substr_flags(format,args,&len);
                format += len;
            }
            else if (*format == '%' && *(format + 1))
            {
                format++;
                count += ft_process_specifier(*format++, args);
            
            }else if(*format == '%')
                format++;
            else
                count += ft_putchar(*format++);
    }
    va_end(args);
    return count;
}

int main(){
    int i = ft_printf(" %01d ", 0);
    printf("%d",i);
    //ft_printf("|%.8-17d|",77);
    // ft_printf("%012x |%-12.3s|",42,"abcedfgh");
    //printf("%d",i);
    // ft_printf("khalil %s %d %x %X %u %% %c %n%","amrene",1337,456789,456789,-1337,'f');
    
}
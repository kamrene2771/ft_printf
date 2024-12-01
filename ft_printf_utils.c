#include "ft_printf.h"

int ft_putchar(char c) {
    return write(1, &c, 1);
}
int ft_putstr(char *str){
    int len = 0;
    if(!str){
        write(1,"(null)",6);
        return 6;
    }
    while(str[len]){
        ft_putchar(str[len++]);
    }
    return len;
}
int check(char *flag){
    int i = 0;
    while(flag[i]){
        if(flag[i] == '.' || flag[i] == '-')
            return i;
        i++;
    }
    return 0;
}
int zero_flag_lenght(char c,va_list arglen){
    int lenght = 0;
    if(c == 's')
        lenght = ft_strlen(va_arg(arglen,char *));
    else if (c == 'd' || c == 'i')
        lenght = ft_strlen(ft_itoa(va_arg(arglen,int)));
    else if(c == 'u')
        lenght = ft_strlen(ft_itoa_base(va_arg(arglen,int),"0123456789"));
    else if(c == 'x' || c == 'X')
        lenght = ft_strlen(ft_itoa_base(va_arg(arglen,int),"0123456789abcdef"));
    
    return lenght;
}
char *ft_itoa_base(unsigned long n, const char *base) {
    char *result;
    unsigned long tmp = n;
    int base_len = 0, len = 1;

    while (base[base_len])
        base_len++;
    tmp = n;
    while ((tmp /= base_len))
        len++;
    result = malloc(len + 1);
    if (!result)
        return NULL;
    result[len] = '\0';
    while (len--)
        result[len] = base[n % base_len], n /= base_len;
    return result;
}
//optimize this
int handle_both(char *specifier_flag_buffer,va_list args,int *count,int c)
{
    int second_flag;
    int lenght;
    int how_many_1 = 0;
    int how_many_2 = 0;
    char *to_print;
    va_list arglen;
    va_copy(arglen,args);
    int specifier = 0;
    second_flag = check(specifier_flag_buffer);
    *count = ft_strlen(specifier_flag_buffer) + 1;
    if(specifier_flag_buffer[second_flag] == '.'){
        how_many_1 = ft_atoi(specifier_flag_buffer);
        lenght = how_many_1;
        specifier_flag_buffer += second_flag + 1;
        how_many_2 = ft_atoi(specifier_flag_buffer);
    }else{
        how_many_2 = ft_atoi(specifier_flag_buffer);
        specifier_flag_buffer += second_flag + 1;
        how_many_1 = ft_atoi(specifier_flag_buffer);
        lenght = how_many_1;
    }
    while(specifier_flag_buffer[specifier])
        specifier++;
    if(c == '-' && specifier_flag_buffer[specifier-1] != 's'){
        lenght =  zero_flag_lenght(specifier_flag_buffer[specifier-1],arglen);
        int len = how_many_2;
        how_many_2 = how_many_2 - lenght;
        if (how_many_2 > 0)
            while(how_many_2){
                ft_putchar('0');
                how_many_2--;
            }
        else
            len = lenght;
        lenght = ft_process_specifier(specifier_flag_buffer[specifier-1] ,args);
        how_many_1 = how_many_1 - len;
        if (how_many_1 > 0)
            while(how_many_1){
                ft_putchar(' ');
                how_many_1--;
            }
    }else if(c == '-'){
        to_print = ft_substr(va_arg(args, char *),0,how_many_2);
        how_many_1 = how_many_1 - handle_str(to_print);
        if (how_many_1 > 0)
            while(how_many_1){
                ft_putchar(' ');
                how_many_1--;
            }
    }
    if(c == '0' && specifier_flag_buffer[specifier-1] != 's'){
        lenght =  zero_flag_lenght(specifier_flag_buffer[specifier-1],arglen) ; 
        how_many_1 = how_many_1 - lenght;
        if (how_many_1 > 0)
            while(how_many_1){
                ft_putchar(' ');
                how_many_1--;
            }
        ft_process_specifier(specifier_flag_buffer[specifier-1],args);
    }else if(c == '0'){
        lenght =  ft_strlen(va_arg(arglen,char *) - how_many_2  - 1 ) ;
        how_many_1 = how_many_1 - lenght;
        if (how_many_1 > 0)
            while(how_many_1){
                ft_putchar('0');
                how_many_1--;
            }
        to_print = ft_substr(va_arg(args, char *),0,how_many_2);
        lenght += handle_str(to_print);
}
    va_end(arglen);
    return lenght;
}
int handle_minus(const char *format,va_list args,int *count, int len)
{
    int how_many = 0;
    int lenght = 0;
    char *specifier_flag_buffer;
    int c = format[0];
    specifier_flag_buffer = ft_substr(format,1,len);
    if(check(specifier_flag_buffer) > 0)
            return handle_both(specifier_flag_buffer,args,count,c);
    how_many = ft_atoi(specifier_flag_buffer);
    lenght = how_many;
    *count = ft_strlen(specifier_flag_buffer) + 1;
    free(specifier_flag_buffer);
    len = ft_process_specifier(format[len],args);
    how_many = how_many - len;
    if (how_many > 0)
        while(how_many){
            ft_putchar(' ');
            how_many--;
        }
    else
        lenght = len;
    return lenght;
}

int handle_zero(const char *format,va_list args,int *count, int len)
{   
    int how_many = 0;
    int lenght = 0;
    char *specifier_flag_buffer;
    int c = format[0];
    va_list arglen;
    va_copy(arglen,args);

    specifier_flag_buffer = ft_substr(format,1,len);
    if(c == '.')
        c = specifier_flag_buffer[check(specifier_flag_buffer)];
    if(check(specifier_flag_buffer) > 0)
        return handle_both(specifier_flag_buffer,args,count,c);
    how_many = ft_atoi(specifier_flag_buffer);
    *count = ft_strlen(specifier_flag_buffer) + 1;
    free(specifier_flag_buffer);
    lenght = zero_flag_lenght(format[len],arglen);
    va_end(arglen);
    how_many = how_many - lenght;
    if (how_many > 0)
        while(how_many){
            ft_putchar('0');
            how_many--;
        }
    ft_process_specifier(format[len],args);
    return lenght;
}

int handle_dot_string(const char *format,va_list args,int *count, int len)
{
    int how_many = 0;
    int lenght = 0;
    char *specifier_flag_buffer;
    char *to_print;
    int c ;
    int second_flag;

    
    specifier_flag_buffer = ft_substr(format,1,len);
    second_flag = check(specifier_flag_buffer);
    c = specifier_flag_buffer[second_flag];
     if(check(specifier_flag_buffer) > 0)
        return handle_both(specifier_flag_buffer,args,count,c);
    how_many = ft_atoi(specifier_flag_buffer);
    lenght = how_many;
    *count = ft_strlen(specifier_flag_buffer) + 1;
    free(specifier_flag_buffer);
    to_print = ft_substr(va_arg(args, char *),0,how_many);
    len = handle_str(to_print);
    free(to_print);
    return len;
}
int substr_flags(const char *format,va_list args,int *count)
{
    int len = 0;
    int end_off_flag = 0;
    
    while (format[len]){ 
        if (format[len] == 'd' || format[len] == 'i' || format[len] == 's' || format[len] == '%' || format[len] == 'c' || format[len] == 'u' || format[len] == 'x' || format[len] == 'X' || format[len] == 'p'){
            end_off_flag = 1;
            break;
        }
        len++;
    }
    if (end_off_flag == 1)
    {  
        if(format[0] == '-')
            len = handle_minus(format,args,count,len);
        if(format[0] == '0')
            len = handle_zero(format,args,count,len);
        if(format[0] == '.')
        {
            if(format[len] != 's')
                len = handle_zero(format,args,count,len);
            else
                len = handle_dot_string(format,args,count,len);
        }
        return len;
    }
  return 0;
}
int ft_process_specifier(char specifier, va_list args) 
{   
    if (specifier == 'c')
        return handle_char(va_arg(args, int));
    else if (specifier == 's')
        return handle_str(va_arg(args,char *));
    else if (specifier == 'd' || specifier == 'i')
        return handle_int(va_arg(args, int));
    else if (specifier == 'u')
        return handle_unsigned(va_arg(args, unsigned int));
    else if (specifier == 'x' || specifier == 'X')
        return handle_hex(va_arg(args, unsigned int),specifier);
    else if (specifier == 'p')
        return handle_pointer(va_arg(args, void *));
    else 
        return ft_putchar(specifier);
    return 0;
}

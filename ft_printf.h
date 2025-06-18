/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamrene <kamrene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:13:36 by kamrene           #+#    #+#             */
/*   Updated: 2024/12/16 13:13:10 by kamrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
void	swap(int *a, int *b);
int		lst_it(char *buffer);
char	*ft_itoa_base(unsigned long n, const char *base);
int		ft_process_specifier(char specifier, va_list args);
int		handle_char(int c);
int		handle_str(char *str);
int		handle_int(int nbr);
int		handle_unsigned(unsigned int nbr);
int		handle_hex(unsigned int nbr, char specipier);
int		handle_pointer(void *ptr);
int		handle_ptr_zero(va_list args);
// bonus
int		count_flags(const char *format);
int		handle_minus_not_s(char *specifier_flag_buffer, va_list args, int h1,
			int h2);
int		look_for_first_flag(const char *format);
int		look_for_all(const char *format);
int		look_for_all_helper(const char *format, int i, int *sign);
int		sharp_search(const char *format, va_list args, int *count, int check);
int		width_flags_second(const char *format, va_list args, int *count,
			int skip);
int		calculate_lenght(char c, va_list arglen);
int		plus_search(const char *format, va_list args, int *count, int check);
char	*add_flag(const char *format, int *count, int check);
int		space_search(const char *format, va_list args, int *count, int check);
int		handle_sharp(const char *format, va_list args, int len, int *count);
void	sharp_all(int *returned_len, const char *format, int *count,
			va_list args);
int		dot_numbers_helper_sec(const char *format, int argument_l, int width,
			int i);
int		dot_num_sec(const char *format, int *count, va_list args, int i);
int		numbers_else_sec(const char *format, int *count, va_list args, int i);
int		print_space(int width);
char	*search_help(const char *format, int *count, const char *flag);
int		minus_numbers(const char *format, int *count, va_list args);
int		dot_numbers_helper(const char *format, int argument_l, int width,
			int i);
int		dot_numbers_helper_2(int r_l, int argument_l, int width);
int		dot_numbers(const char *format, int *count, va_list args, int i);
int		numbers_else(const char *format, int *count, va_list args, int i);
int		width_flags(const char *format, va_list args, int *count);
int		width_flags_second(const char *format, va_list args, int *count,
			int skip);
void	sharp_helper(const char *format, int *r_l, int *count, va_list args);
void	sharp_helper_sec(const char *format, int arg, int *r_l, int *count);
int		handle_space(const char *format, va_list args, int len, int *count);
int		space_helper(va_list args, const char *format, int len, int *count);
int		handle_plus(const char *format, va_list args, int len, int *count);
void	plus_helper(va_list args, const char *format, int *returned_len,
			int *count);
void	space_last(int *r_l, int *count, const char *format, va_list args);
int		handle_both(char *specifier_flag_buffer, va_list args, int *count,
			int c);
int		substr_flags_second(const char *format, va_list args, int *count);
int		substr_flags(const char *format, va_list args, int *count);
int		handle_minus(const char *format, va_list args, int *count, int len);
int		handle_zero(const char *format, va_list args, int *count, int len);
int		handle_dot_zero(const char *format, va_list args, int *count, int len);
int		handle_dot_string(const char *format, va_list args, int *count,
			int len);
int		check(char *flag);
int		z_m_flag(const char *format, int *count, int len, va_list args);
int		zm_flag_helper(const char *format, va_list args, int *count, int len);
char	*ft_itoa_base_zero(unsigned int n, const char *base);
void	handle_zero_negative(va_list args);
int		handle_dot_negative(va_list args);
int		lenght_dot_helper(va_list arglen, int c);
int		zero_flag_lenght(char c, va_list arglen);
int		zero_dot_flag_lenght(char c, va_list arglen, int flag, int *h1);
int		print_zero(int *how_many, char *format, va_list args, int len);
int		print_zero_helper(char c, int lenght, int *how_many);
int		print_dot_zero(int *how_many, char *format, va_list args, int len);
// combination
int		handle_both(char *specifier_flag_buffer, va_list args, int *count,
			int c);
int		handle_md_all(char *buffer, va_list args, int *h1, int h2);
int		handle_md_negative(char specifier, va_list args, int returned_len,
			int h2);
int		handle_md_s(va_list args, int *h1, int h2);
int		handle_zd_all(char *buffer, va_list args, int *h1, int h2);
void	zd_all_helper(int c, int *h1, int argument, int h2);
int		zd_all_helper2(int c, int *h1, int returned_len, int h2);
int		zd_all_helper3(int c, int *h1, int returned_len, int h2);
int		zd_all_print(int *arg, int h2, int specifier, va_list args);
int		handle_zd_negative(va_list args, int *h1, int h2);
int		handle_zd_s(va_list args, int *h1, int h2);

#endif

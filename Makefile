
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c \
	  libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c \
	  libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c \
	  libft/ft_strlcpy.c libft/ft_putendl_fd.c libft/ft_strrchr.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strmapi.c libft/ft_strnstr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c \
	  libft/ft_lstnew_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstlast_bonus.c libft/ft_lstadd_back_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstclear_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c\
	  ft_printf.c ft_printf_utils.c handle_specifier.c handle_specifier_1.c bonus/basic_functions_bonus.c bonus/basic_functions_bonus_1.c bonus/ft_printf_utils_bonus.c bonus/ft_printf_utils_bonus_1.c  bonus/ft_printf_utils_bonus_2.c bonus/ft_printf_utils_bonus_3.c bonus/ft_printf_utils_bonus_4.c bonus/ft_printf_utils_bonus_5.c bonus/ft_printf_utils_bonus_6.c bonus/ft_printf_utils_bonus_7.c bonus/ft_printf_utils_bonus_8.c bonus/ft_printf_utils_bonus_9.c
OBJ = $(SRC:.c=.o)
BNSOBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

%.o: %.c ft_printf.h 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: all

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean 
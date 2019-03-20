NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRCS = ./srcs/ft_atoi.c\
		./srcs/ft_bzero.c\
		./srcs/ft_isalnum.c\
		./srcs/ft_isalpha.c\
		./srcs/ft_isascii.c\
		./srcs/ft_isdigit.c\
		./srcs/ft_isprint.c\
		./srcs/ft_itoa.c\
		./srcs/ft_itoa_base.c\
		./srcs/ft_list_size.c\
		./srcs/ft_longtoa_base.c\
		./srcs/ft_lstadd.c\
		./srcs/ft_lstadd_end.c\
		./srcs/ft_lstdel.c\
		./srcs/ft_lstdelone.c\
		./srcs/ft_lstiter.c\
		./srcs/ft_lstmap.c\
		./srcs/ft_lstnew.c\
		./srcs/ft_lstprint.c\
		./srcs/ft_lstprintone.c\
		./srcs/ft_memalloc.c\
		./srcs/ft_memalloc_chr.c\
		./srcs/ft_memccpy.c\
		./srcs/ft_memchr.c\
		./srcs/ft_memcmp.c\
		./srcs/ft_memcpy.c\
		./srcs/ft_memdel.c\
		./srcs/ft_memdup.c\
		./srcs/ft_memjoin.c\
		./srcs/ft_memmove.c\
		./srcs/ft_memset.c\
		./srcs/ft_pow.c\
		./srcs/ft_putchar.c\
		./srcs/ft_putchar_fd.c\
		./srcs/ft_putendl.c\
		./srcs/ft_putendl_fd.c\
		./srcs/ft_putmem.c\
		./srcs/ft_putmem_fd.c\
		./srcs/ft_putnbr.c\
		./srcs/ft_putnbr_fd.c\
		./srcs/ft_putstr.c\
		./srcs/ft_putstr_fd.c\
		./srcs/ft_strcat.c\
		./srcs/ft_strchr.c\
		./srcs/ft_strclr.c\
		./srcs/ft_strcmp.c\
		./srcs/ft_strcpy.c\
		./srcs/ft_strdel.c\
		./srcs/ft_strdup.c\
		./srcs/ft_strequ.c\
		./srcs/ft_striter.c\
		./srcs/ft_striteri.c\
		./srcs/ft_strjoin.c\
		./srcs/ft_strlcat.c\
		./srcs/ft_strlen.c\
		./srcs/ft_strmap.c\
		./srcs/ft_strmapi.c\
		./srcs/ft_strncat.c\
		./srcs/ft_strncmp.c\
		./srcs/ft_strncpy.c\
		./srcs/ft_strnequ.c\
		./srcs/ft_strnew.c\
		./srcs/ft_strnstr.c\
		./srcs/ft_strrchr.c\
		./srcs/ft_strreverse.c\
		./srcs/ft_strsplit.c\
		./srcs/ft_strsplitlist.c\
		./srcs/ft_strstr.c\
		./srcs/ft_strsub.c\
		./srcs/ft_strtoupper.c\
		./srcs/ft_strtrim.c\
		./srcs/ft_tolower.c\
		./srcs/ft_ulongtoa_base.c\
		./srcs/ft_unistrlen.c\
		./srcs/get_next_line.c\
		./srcs/sort_list.c\
		./srcs/write_digit_base.c\
		./srcs/ft_printf/add_0_for_numstr.c\
		./srcs/ft_printf/b_options.c\
		./srcs/ft_printf/bigintsum_toa.c\
		./srcs/ft_printf/cast_signed.c\
		./srcs/ft_printf/cast_unsigned.c\
		./srcs/ft_printf/conv_to_strnum.c\
		./srcs/ft_printf/conversion.c\
		./srcs/ft_printf/count_digits.c\
		./srcs/ft_printf/e_format.c\
		./srcs/ft_printf/f_b.c\
		./srcs/ft_printf/f_c.c\
		./srcs/ft_printf/f_feg.c\
		./srcs/ft_printf/f_format.c\
		./srcs/ft_printf/f_pdioux.c\
		./srcs/ft_printf/f_s.c\
		./srcs/ft_printf/find_flags.c\
		./srcs/ft_printf/flags.c\
		./srcs/ft_printf/ft_fprintf.c\
		./srcs/ft_printf/ft_printf.c\
		./srcs/ft_printf/g_format.c\
		./srcs/ft_printf/get_exp_count.c\
		./srcs/ft_printf/get_float_params.c\
		./srcs/ft_printf/get_format_number1.c\
		./srcs/ft_printf/get_format_number2.c\
		./srcs/ft_printf/number_format.c\
		./srcs/ft_printf/pow_bignum_toa.c\
		./srcs/ft_printf/precision.c\
		./srcs/ft_printf/round_number.c\
		./srcs/ft_printf/set_color.c\
		./srcs/ft_printf/size_mode.c\
		./srcs/ft_printf/width.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(FLAGS) -I./includes -o $@ -c $<

clean:
	@rm -f srcs/$(OBJS)
	@rm -f srcs/ft_printf/$(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

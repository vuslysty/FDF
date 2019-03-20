/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:35:37 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/26 16:46:28 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MODE_FLAGS 7
# define CONVERSIONS "cspdiouxXfFeEgGb%"
# define FLAGS "+- #0"
# define ABS(n) ((n) > 0) ? (n) : (n * -1);
# define MANTISS_LEN 64

# define STD		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define GRAY		"\033[37m"
# define EOC		"\033[0m"

# define BGSTD		"\033[40m"
# define BGRED		"\033[41m"
# define BGGREEN	"\033[42m"
# define BGYELLOW	"\033[43m"
# define BGBLUE		"\033[44m"
# define BGPURPLE	"\033[45m"
# define BGCYAN		"\033[46m"
# define BGGRAY		"\033[47m"

# define NORMAL		"\033[0m"
# define BOLD		"\033[1m"
# define DBOLD		"\033[2m"
# define NBOLD		"\033[22m"
# define UNDERLINE	"\033[4m"
# define BLINK		"\033[5m"
# define INVERSE	"\033[7m"

/*
**		There is a possibility to combine COLOR + BG + FORMAT_TEXT.
**		FOR EXAMPLE: "{GREEN}{BGRED}{BOLD}Hello world{EOC}".
*/

# include "libft.h"
# include <stdarg.h>

enum	e_conv
{
	C, S, P, D, I, O, U, X, UPP_X, F, UPP_F, E, UPP_E, G, UPP_G, B, PR
};
typedef unsigned long long t_ull;
typedef long long t_ll;

typedef union		u_conv
{
	long double		ld;
	long int		li;
	double			d;
	char			*str;
}					t_conv;

typedef struct		s_format
{
	unsigned int	sign:1;
	unsigned int	minus:1;
	unsigned int	plus:1;
	unsigned int	space:1;
	unsigned int	sharp:1;
	unsigned int	zero:1;
	unsigned int	precision:1;
	unsigned int	size:1;
	int				s_val;
	enum e_conv		type;
	int				w_val;
	int				p_val;
}					t_format;

typedef struct		s_myfloat
{
	unsigned int	exp_sign:1;
	unsigned int	s:1;
	int				e;
	t_ull			m;
	char			*intnum;
	char			*decimal;
	int				len_i;
	int				len_d;
	int				exp_count;
}					t_myfloat;

typedef struct		s_pf
{
	va_list			ap;
	t_format		form;
	void			*form_str;
	char			*buf;
	size_t			len_buf;
	int				len;
	int				i;
	char			*tmp;
	int				fd;
}					t_pf;

int					find_flags(char **str, t_format *form, va_list *ap);
void				flags(t_format *form, char **str);
int					size(t_format *form, char **str);
void				precision(t_format *form, char **str, va_list *ap);
void				width(t_format *form, char **str, va_list *ap);
int					conversion(t_format *form, char **str);
size_t				f_c(t_format *form, va_list *ap, char **buf);
size_t				f_s(t_format *form, va_list *ap, char **str);
int					ft_printf(char *str, ...);
void				cast_signed(long long int *n, va_list *ap, t_format *f);
void				cast_unsigned(unsigned long long int *n, va_list *ap,
									t_format *f);
size_t				number_format(char **nbr, t_format *f);
size_t				f_pdioux(t_format *f, va_list *ap, char **str);
size_t				get_format_number1(t_format *f, void *n, char **str);
int					count_digits(size_t digit);
char				*pow_bigint_toa(size_t n, int pow);
/*
** 		Convert massive of integers to massive of characters.
** 		In result we have number in string.
*/
char				*conv_to_strnum(int *mas, int len);
/*
**		bigintsum has two mods:
**		1 - ignored '0' befor number (a usual work);
**		0 - calculate numbers with '0' befor number (I wrote it for numbers
**			which has floating point (its decimal part)).
*/
char				*bigintsum_toa(char *num1, char *num2, int mode);
/*
**		1 - add zeros start
**		0 - add zeros end
*/
void				add_0_for_numstr(char **num, int len_finish, int mode);
int					get_float_params(t_myfloat *mf, long double *n);
void				round_numstr(t_myfloat *mf, int round_count);
char				*e_format(t_myfloat *mf, t_format *f);
char				*f_format(t_myfloat *mf, t_format *f);
size_t				get_format_number2(t_format *f, long double *n, char **str);
size_t				f_feg(t_format *f, va_list *ap, char **str);
void				min_plus_space(char **nbr, t_format *f);
char				*g_format(t_myfloat *mf, t_format *f);
void				set_color(t_pf *pf, char *color, size_t i, char **str);
size_t				text_color(t_pf *pf, char **str);
size_t				bg_color(t_pf *pf, char **str);
size_t				addition_options(t_pf *pf, char **str);
void				get_exp_count(t_myfloat *mf);
/*
**		width - standart width.
**		0 - print bits with zeros at start.
**		- - print bits on the left side (default right),
**			work when -width is present.
**		+ - raises flag -0 and lowers flag of width, sets spaces between bytes.
**		. - works in cases when flag + is present, divided lines by N bytes,
**			sets '\n' at the end of each line.
**		---------------------------------------------------------------------
**		SIZE_MODE_FLAGS:
**		default (when nothing flags is present) - print 4 bytes (32 bits) max;
**		-FLAGS FOR INTEGERS-
**		hh - print 1 byte (8 bits) max;
**		h  - print 2 bytes (16 bits) max;
**		l  - print 4 bytes (32 bits) max;
**		ll - print 8 bytes (64 bits) max;
**		-FLAGS FOR NUMBERS WITH FLOATING POINTS-
**		mD  - print 8 bytes (64 bits) max; DOUBLE
**		L  - print 10 bytes (80 bits) max; LONG DOUBLE
**		-FLAG FOR PRINTING STRING BY BYTES (BY BITS)-
**		T  - print each character of string by bytes,
**			 raises flag -0.
*/
size_t				f_b(t_format *form, va_list *ap, char **buf);
void				b_flag_plus(char **buf, int bits, int spaces);
void				b_size_mode_t(char *buf, void *b, t_format *f);
void				read_binary(void *b, t_format *f, char *str, int bits);
int					b_flag_nozero(t_format *f, int len, char **str);
size_t				get_format_binary(t_format *f, char **str, int lb);
void				b_flag_precision(t_format *f, char *str);
int					ft_fprintf(int fd, char *str, ...);

#endif

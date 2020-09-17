/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:17:26 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/16 22:54:57 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef __int128	t_int128;

typedef struct	s_all
{
	int			symbol_num;
	char		flag_minus;
	char		flag_plus;
	char		flag_space;
	char		flag_zero;
	char		flag_hash;
	char		flag_sign_minus;
	int			width;
	int			precision;
	int			modifier;
	int			type;
	char		*fin_str;
}				t_all;

typedef struct	s_float_components
{
	int			sign;
	int			*integer;
	int			*fraction;
	int			inf_check;
	int			nan_check;
	int			len_fraction;
	int			len_integer;
	t_int128	one;
}				t_fcomp;

char			*check_flags(t_all *all, char *s);
char			*check_width_or_precision(t_all *all, char *s,
		va_list *ap, char flag);
char			*check_modifier(t_all *all, char *s);
char			*check_type(t_all *all, char *s);
char			*check_type_and_output(t_all *all, va_list *ap, char *s);
void			do_n(t_all *all, va_list *ap);
void			do_int(t_all *all, va_list *ap, char *str);
void			do_uint(t_all *all, va_list *ap, char *str);
void			do_int8(t_all *all, va_list *ap, char *str);
void			do_int16x(t_all *all, va_list *ap, char *str);
void			do_int16xupper(t_all *all, va_list *ap, char *str);
void			do_float(t_all *all, va_list *ap, char *str);
void			do_string(t_all *all, va_list *ap, char *str);
void			do_ptype(t_all *all, va_list *ap, char *str);
char			*ft_utoa_base(unsigned long nb, int base);
char			*ft_ltoa_base(long nb, int base);
void			do_percent_or_uchar(t_all *all, va_list *ap, char *str, char f);
char			*int_precision_processing(t_all *all, char *str, int *len);
char			*int_w_mz_processing(t_all *all, char *str, int *len);
char			*flags_ps_or_signs(t_all *all, char *str, int *len);
char			*intu82_p_processing(t_all *all, char *str, int *len);
char			*intu82_w_mz_processing(t_all *all, char *str, int *len);
char			*int8_h_processing(t_all *all, char *str, int *len);
char			*int16x_h_processing(t_all *all, char *str, int *len);
char			*int16_p_processing(t_all *all, char *str, int *len);
char			*int16_w_hmz_processing(t_all *all, char *str, int *len);
char			*int16_w_hm_processing(t_all *all, char *str, int *len);
void			do_lower(char *str);
char			*get_str(va_list *ap, char *str, t_all *all, int base);
void			zero_p(t_all *all, char *str, int *len, int flag);
char			*check_type_and_output(t_all *all, va_list *ap, char *s);
void			do_letter_wzm(t_all *all, char *str, char s);
void			get_components(va_list *ap, t_fcomp *fcomp);
void			get_components_l(va_list *ap, t_fcomp *fcomp);
void			do_int2(t_all *all, va_list *ap, char *str);
char			*merge_strings(char *s1, int len_1, char *s2, size_t n);
void			get_fraction(char *b_fraction, t_fcomp *fcomp);
char			*bit_fraction(long *exponent, long b, int *len);
char			*bit_fraction_l(long *exponent_l, t_int128 bl, int *len);
int				exception_handling(t_fcomp *fcomp, long b, long exponent);
int				exception_handl_l(t_fcomp *fcomp, t_int128 bl, long exponent_l);
int				check_5(t_fcomp *fcomp, int count);
void			norm_integer(t_fcomp *fcomp);
void			get_integer(char *b_integer, t_fcomp *fcomp);
char			*bit_integer(long exponent, long b, int *len);
char			*get_string_integer(t_fcomp *fcomp);
char			*bit_integer_l(long exponent_l, t_int128 bl, int *len);
void			processing_overflow_integerpart(t_fcomp *fcomp);
int				find_len_integer(int len_s);
char			*flags_f_ps_or_signs(t_all *all, char *str, int *len);
char			*float_w_mz_processing(t_all *all, char *str,
		int *len, int flag);

#endif

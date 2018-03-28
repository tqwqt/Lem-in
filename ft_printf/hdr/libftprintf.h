/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:25:13 by vhavryle          #+#    #+#             */
/*   Updated: 2018/02/11 16:25:16 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <string.h>
# include <unistd.h>
# include <wchar.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../../libft/libft.h"

typedef struct		s_flags
{
	short			plus;
	short			minus;
	short			space;
	short			sharp;
	short			zero;
	short			width;
	short			precision;
	char			size;
	char			type;
	int				b_count;
	int				neg;
	int				i;
}					t_flags;

void				ft_no_unic(va_list ap, t_flags *arg, char cc);
t_flags				*ft_pars_arg(char *arg_s, t_flags *arg);
int					ft_printf(const char *format, ...);
t_flags				*ft_pars(char *s, t_flags *arg, int *res, va_list ap);
t_flags				*ft_arg_clear(t_flags *arg);
t_flags				*ft_pars_width(char *s, t_flags *arg, int i);
t_flags				*ft_pars_precision(char *s, t_flags *arg, int i);
t_flags				*ft_pars_size(char *s, t_flags *arg, int i);
t_flags				*ft_pars_type(char *s, t_flags *arg, int i);
void				ft_caster(t_flags *arg, va_list ap);
void				ft_cast_ddi(va_list ap, t_flags *arg);
void				ft_cast_xx(va_list ap, t_flags *arg);
char				*ft_strtolow(char *s);
void				ft_cast_c(va_list ap, t_flags *arg);
int					ft_act_bits(wchar_t a);
int					ft_putstr_w(char *s, char c, int start);
void				ft_cast_ss(va_list ap, t_flags *arg);
void				ft_cast_s(va_list ap, t_flags *arg);
void				ft_cast_oo(va_list ap, t_flags *arg);
void				ft_cast_p(va_list ap, t_flags *arg);
t_flags				*ft_flag_check(t_flags *arg, int arg_len);
t_flags				*ft_space_check(t_flags *arg);
int					ft_put_prec(char *s, int prec, int arg_len);
void				ft_cast_ddi_if(t_flags *arg, intmax_t max);
void				ft_cast_xx_if(t_flags *arg, char *s, uintmax_t max);
void				ft_cast_oo_if(t_flags *arg, unsigned long long max,
	char *s);
void				ft_cast_uu(va_list ap, t_flags *arg);
void				ft_cast_uu_if(t_flags *arg, char *s,
	unsigned long long max);
char				*ft_add_prec(char *s, int prec);
void				ft_cast_proc(t_flags *arg);
void				ft_cast_wrong(t_flags *arg);
int					ft_put_uni(t_flags *arg, unsigned char mask, wchar_t a,
	int bits);
int					ft_str_uni_len(wchar_t *str);
int					ft_pars_uni(wchar_t a, t_flags *arg, int bits);
int					ft_count_bytes(int act);
int					ft_kostil_wchar_prec_len(wchar_t *a, t_flags *arg);
int					ft_z_init(unsigned char mask);
void				ft_put_ss(t_flags *arg, wchar_t *a, int bits, int arglen);
void				ft_put_p(t_flags *arg, char *s);
void				ft_minus_0(t_flags *arg, int arglen, intmax_t max, char *s);
void				ft_minus_1(t_flags *arg, int arglen, intmax_t max, char *s);
void				ft_put_xx(t_flags *arg, char *s, uintmax_t max);
void				ft_put_oo(t_flags *arg, char *s);

#endif

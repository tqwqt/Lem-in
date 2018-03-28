/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:08:37 by vhavryle          #+#    #+#             */
/*   Updated: 2018/02/04 14:08:38 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/libftprintf.h"

void		ft_cast_ss(va_list ap, t_flags *arg)
{
	wchar_t	*a;
	int		i;
	int		bits;
	int		arglen;

	i = -1;
	bits = 0;
	if (arg->type == 's' && arg->size != 'l')
	{
		ft_cast_s(ap, arg);
		return ;
	}
	a = va_arg(ap, wchar_t*);
	if (a == NULL)
	{
		arg->b_count += ft_putstr_w("(null)", '\0', 0);
		return ;
	}
	while (a[++i] != L'\0')
		bits += ft_count_bytes(ft_act_bits(a[i]));
	arglen = bits;
	ft_put_ss(arg, a, bits, arglen);
}

void		ft_put_ss(t_flags *arg, wchar_t *a, int bits, int arglen)
{
	int		len;
	int		i;

	i = -1;
	if (arg->precision > -1)
	{
		arglen = ft_kostil_wchar_prec_len(a, arg);
		bits = arg->precision;
	}
	len = ft_str_uni_len(a);
	if (arg->minus == 0)
	{
		ft_flag_check(arg, arglen);
		while (++i < len && bits != 0)
			bits = ft_pars_uni(a[i], arg, bits);
	}
	else
	{
		while (++i < len && bits != 0)
			bits = ft_pars_uni(a[i], arg, bits);
		ft_flag_check(arg, arglen);
	}
}

void		ft_cast_s(va_list ap, t_flags *arg)
{
	char	*s;
	int		arglen;
	char	*tmp;

	s = ft_strdup(va_arg(ap, char*));
	if (s == NULL)
		s = ft_strdup("(null)");
	if (arg->precision > -1)
	{
		tmp = s;
		s = ft_strsub(s, 0, arg->precision);
		ft_strdel(&tmp);
	}
	arglen = ft_strlen(s);
	if (arg->minus == 0)
	{
		ft_flag_check(arg, arglen);
		arg->b_count += ft_putstr_w(s, '\0', 0);
	}
	else
	{
		arg->b_count += ft_putstr_w(s, '\0', 0);
		ft_flag_check(arg, arglen);
	}
	ft_strdel(&s);
}

int			ft_act_bits(wchar_t a)
{
	int		i;

	i = 0;
	while (a && i < 2147483647)
	{
		a >>= 1;
		i++;
	}
	return (i);
}

void		ft_cast_c(va_list ap, t_flags *arg)
{
	wchar_t a;
	int		act;

	a = va_arg(ap, wint_t);
	act = ft_act_bits(a);
	if (act <= 7 || MB_CUR_MAX == 1)
	{
		ft_no_unic(NULL, arg, (char)a);
		return ;
	}
	if (arg->type == 'c' && arg->size == 'l')
		arg->type = 'C';
	if (arg->minus == 0)
	{
		ft_flag_check(arg, 1);
		ft_pars_uni(a, arg, 4);
	}
	else
	{
		ft_pars_uni(a, arg, 4);
		ft_flag_check(arg, 1);
	}
}

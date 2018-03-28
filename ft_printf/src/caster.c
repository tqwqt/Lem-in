/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:32:51 by vhavryle          #+#    #+#             */
/*   Updated: 2018/01/15 15:32:53 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/libftprintf.h"

void					ft_caster(t_flags *arg, va_list ap)
{
	if (ft_strchr("dDi", arg->type))
		ft_cast_ddi(ap, arg);
	else if (ft_strchr("xX", arg->type))
		ft_cast_xx(ap, arg);
	else if (arg->type == 'C' || (arg->type == 'c' && arg->size == 'l'))
		ft_cast_c(ap, arg);
	else if (arg->type == 'c' && arg->size != 'l')
		ft_no_unic(ap, arg, 'c');
	else if (ft_strchr("sS", arg->type))
		ft_cast_ss(ap, arg);
	else if (ft_strchr("oO", arg->type))
		ft_cast_oo(ap, arg);
	else if (arg->type == 'p')
		ft_cast_p(ap, arg);
	else if (ft_strchr("uU", arg->type))
		ft_cast_uu(ap, arg);
	else if (arg->type == '%')
		ft_cast_proc(arg);
	else
		ft_cast_wrong(arg);
}

void					ft_cast_wrong(t_flags *arg)
{
	char				*c;
	char				*tmp;
	int					arglen;

	c = ft_strnew(1);
	c[0] = arg->type;
	arg->precision = -1;
	if (arg->precision > -1)
	{
		tmp = c;
		c = ft_strsub(c, 0, arg->precision);
		ft_strdel(&tmp);
	}
	arglen = ft_strlen(c);
	if (arg->minus == 0)
	{
		ft_flag_check(arg, arglen);
		arg->b_count += ft_putstr_w(c, '\0', 0);
	}
	else
	{
		arg->b_count += ft_putstr_w(c, '\0', 0);
		ft_flag_check(arg, arglen);
	}
	ft_strdel(&c);
}

void					ft_cast_proc(t_flags *arg)
{
	arg->precision = -1;
	if (arg->minus == 0)
	{
		arg = ft_flag_check(arg, 1 + arg->neg);
		write(1, "%", 1);
		arg->b_count += 1;
	}
	else
	{
		write(1, "%", 1);
		arg->b_count += 1;
		arg = ft_flag_check(arg, 1 + arg->neg);
	}
}

void					ft_cast_p(va_list ap, t_flags *arg)
{
	unsigned long long	ptr;
	intmax_t			len;
	char				*s;
	char				*tmp;

	len = 0;
	ptr = va_arg(ap, unsigned long long);
	if (arg->precision == 0 && ptr == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base(ptr, 16);
	if (arg->precision > -1)
	{
		tmp = s;
		s = ft_add_prec(s, arg->precision);
		ft_strdel(&tmp);
	}
	tmp = s;
	s = ft_strjoin("0x", s);
	ft_strdel(&tmp);
	ft_put_p(arg, s);
}

void					ft_put_p(t_flags *arg, char *s)
{
	if (arg->minus == 0)
	{
		ft_flag_check(arg, ft_strlen(s));
		arg->b_count += ft_putstr_w(ft_strtolow(s), '\0', 0);
	}
	else
	{
		arg = ft_space_check(arg);
		arg->b_count += ft_putstr_w(ft_strtolow(s), '\0', 0);
		ft_flag_check(arg, ft_strlen(s));
	}
	ft_strdel(&s);
}

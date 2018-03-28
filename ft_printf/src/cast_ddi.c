/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_ddi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 19:37:30 by vhavryle          #+#    #+#             */
/*   Updated: 2018/02/04 19:37:31 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/libftprintf.h"

void			ft_cast_ddi(va_list ap, t_flags *arg)
{
	intmax_t	max;

	if (ft_strchr("D", arg->type))
		arg->size = 'l';
	max = va_arg(ap, size_t);
	if (arg->size == 'j')
		max = (intmax_t)max;
	else if (arg->size == 'L')
		max = (long long int)max;
	else if (arg->size == 'h')
		max = (short int)max;
	else if (arg->size == 'H')
		max = (char)max;
	else if (arg->size == 'l')
		max = (long int)max;
	else if (arg->size == 'z')
		max = (size_t)max;
	else if (arg->size == '0')
		max = (int)max;
	if (max < 0)
	{
		arg->space = 0;
		arg->width++;
	}
	ft_cast_ddi_if(arg, max);
}

void			ft_cast_ddi_if(t_flags *arg, intmax_t max)
{
	char		*s;
	int			arglen;
	char		*tmp;

	if (arg->precision == 0 && max == 0 && arg->width != -1)
		s = ft_strnew(0);
	else
		s = ft_itoa(max);
	if (max < 0)
		arg->neg = 1;
	else
		arg->neg = 0;
	arg = ft_space_check(arg);
	if (arg->precision > -1)
	{
		tmp = s;
		s = ft_add_prec(s, arg->precision);
		ft_strdel(&tmp);
	}
	arglen = ft_strlen(s);
	if (arg->minus == 0)
		ft_minus_0(arg, arglen, max, s);
	else
		ft_minus_1(arg, arglen, max, s);
	ft_strdel(&s);
}

void			ft_minus_0(t_flags *arg, int arglen, intmax_t max, char *s)
{
	if (arg->zero != 1)
		arg = ft_flag_check(arg, arglen + arg->neg);
	if (max >= 0 && arg->plus == 1)
	{
		write(1, "+", 1);
		arg->b_count += 1;
	}
	else if (max < 0)
	{
		write(1, "-", 1);
		arg->b_count += 1;
	}
	if (arg->zero == 1)
		arg = ft_flag_check(arg, arglen + arg->neg);
	arg->b_count += ft_putstr_w(s, '\0', 0);
}

void			ft_minus_1(t_flags *arg, int arglen, intmax_t max, char *s)
{
	if (max >= 0 && arg->plus == 1)
	{
		write(1, "+", 1);
		arg->b_count += 1;
	}
	else if (max < 0)
	{
		write(1, "-", 1);
		arg->b_count += 1;
	}
	arg->b_count += ft_putstr_w(s, '\0', 0);
	arg = ft_flag_check(arg, arglen + arg->neg);
}

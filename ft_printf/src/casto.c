/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_oo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:32:45 by vhavryle          #+#    #+#             */
/*   Updated: 2018/02/05 14:32:46 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/libftprintf.h"

void					ft_cast_oo(va_list ap, t_flags *arg)
{
	unsigned long long	max;
	char				*s;

	s = NULL;
	max = va_arg(ap, unsigned long long);
	if (arg->type == 'O')
		arg->size = 'l';
	else
		arg->size = arg->size;
	if (arg->size == 'j')
		max = (size_t)max;
	else if (arg->size == 'L')
		max = (unsigned long long int)max;
	else if (arg->size == 'h')
		max = (unsigned short int)max;
	else if (arg->size == 'H')
		max = (unsigned char)max;
	else if (arg->size == 'l')
		max = (unsigned long int)max;
	else if (arg->size == 'z')
		max = (unsigned long long int)max;
	else if (arg->size == '0')
		max = (unsigned int)max;
	ft_cast_oo_if(arg, max, s);
}

void					ft_cast_oo_if(t_flags *arg, unsigned long long max,
	char *s)
{
	char				*tmp;

	if (max == 0 && (arg->sharp == 1 || arg->precision > -1))
		s = ft_strnew(0);
	else
		s = ft_itoa_base(max, 8);
	if (arg->precision > -1)
	{
		tmp = s;
		if (arg->sharp == 1)
			arg->precision--;
		s = ft_add_prec(s, arg->precision);
		ft_strdel(&tmp);
	}
	if (arg->sharp == 1)
	{
		tmp = s;
		s = ft_strjoin("0", s);
		ft_strdel(&tmp);
	}
	ft_put_oo(arg, s);
	ft_strdel(&s);
}

void					ft_put_oo(t_flags *arg, char *s)
{
	if (arg->minus == 0)
	{
		ft_flag_check(arg, ft_strlen(s));
		arg->b_count += ft_putstr_w(s, '\0', 0);
	}
	else
	{
		arg->b_count += ft_putstr_w(s, '\0', 0);
		ft_flag_check(arg, ft_strlen(s));
	}
}

void					ft_cast_uu(va_list ap, t_flags *arg)
{
	unsigned long long	max;
	char				*s;

	if (arg->type == 'U')
		arg->size = 'l';
	else
		arg->size = arg->size;
	max = va_arg(ap, unsigned long long);
	if (arg->size == 'j')
		max = (size_t)max;
	else if (arg->size == 'L')
		max = (unsigned long long int)max;
	else if (arg->size == 'h')
		max = (unsigned short int)max;
	else if (arg->size == 'H')
		max = (unsigned char)max;
	else if (arg->size == 'l')
		max = (unsigned long int)max;
	else if (arg->size == 'z')
		max = (unsigned long long int)max;
	else if (arg->size == '0')
		max = (unsigned int)max;
	s = NULL;
	ft_cast_uu_if(arg, s, max);
}

void					ft_cast_uu_if(t_flags *arg, char *s,
	unsigned long long max)
{
	char				*tmp;

	if (arg->precision == 0 && max == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base(max, 10);
	if (arg->precision > -1)
	{
		tmp = s;
		s = ft_add_prec(s, arg->precision);
		ft_strdel(&tmp);
	}
	if (arg->minus == 0)
	{
		ft_flag_check(arg, ft_strlen(s));
		arg->b_count += ft_putstr_w(s, '\0', 0);
	}
	else
	{
		arg->b_count += ft_putstr_w(s, '\0', 0);
		ft_flag_check(arg, ft_strlen(s));
	}
	ft_strdel(&s);
}

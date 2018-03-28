/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:08:05 by vhavryle          #+#    #+#             */
/*   Updated: 2018/02/05 14:08:37 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/libftprintf.h"

void			ft_cast_xx(va_list ap, t_flags *arg)
{
	uintmax_t	max;
	char		*s;

	s = NULL;
	max = va_arg(ap, uintmax_t);
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
	ft_cast_xx_if(arg, s, max);
}

void			ft_cast_xx_if(t_flags *arg, char *s, uintmax_t max)
{
	char		*tmp;

	if (arg->precision == 0 && max == 0)
		s = ft_strdup("");
	else
		s = ft_itoa_base(max, 16);
	if (arg->precision > -1)
	{
		tmp = s;
		s = ft_add_prec(s, arg->precision);
		ft_strdel(&tmp);
	}
	if (arg->sharp == 1 && max != 0 && arg->zero == 1)
	{
		if (arg->type == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		arg->width -= 2;
		arg->b_count += 2;
	}
	ft_put_xx(arg, s, max);
}

void			ft_put_xx(t_flags *arg, char *s, uintmax_t max)
{
	char		*tmp;
	int			arglen;

	if (arg->sharp == 1 && max != 0 && arg->zero == 0)
	{
		tmp = s;
		s = ft_strjoin("0X", s);
		ft_strdel(&tmp);
	}
	arglen = ft_strlen(s);
	if (arg->type == 'x')
		s = ft_strtolow(s);
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

char			*ft_strtolow(char *s)
{
	int			i;

	i = -1;
	while (s[++i] != '\0')
		s[i] = ft_tolower(s[i]);
	return (s);
}

void			ft_no_unic(va_list ap, t_flags *arg, char cc)
{
	char c;

	if (ap != NULL)
		c = va_arg(ap, int);
	else
		c = cc;
	if (arg->minus == 0)
	{
		ft_flag_check(arg, 1);
		write(1, &c, 1);
		arg->b_count++;
	}
	else
	{
		write(1, &c, 1);
		ft_flag_check(arg, 1);
		arg->b_count++;
	}
}

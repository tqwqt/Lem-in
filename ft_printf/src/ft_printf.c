/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:36:46 by vhavryle          #+#    #+#             */
/*   Updated: 2018/01/08 17:36:48 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/libftprintf.h"

int					ft_printf(const char *format, ...)
{
	va_list ap;
	t_flags *arg;
	int		res;
	char	*s;

	arg = NULL;
	res = 0;
	if (format)
	{
		s = ft_strdup((char*)format);
		if (s[0] == '%' && s[1] == '\0')
			return (0);
		va_start(ap, format);
		arg = ft_pars(s, arg, &res, ap);
		free(arg);
		arg = NULL;
		va_end(ap);
	}
	return (res);
}

t_flags				*ft_pars(char *s, t_flags *arg, int *res, va_list ap)
{
	int				end;
	int				p;

	end = ft_strlen(s);
	p = 0;
	arg = malloc(sizeof(t_flags));
	arg = ft_arg_clear(arg);
	arg->i = 0;
	while (s[arg->i] != '\0' && arg->i < end)
	{
		if (s[arg->i] == '%')
		{
			*res += ft_putstr_w(s, '%', p);
			arg = ft_pars_arg(&s[arg->i], arg);
			p = arg->i + 1;
			ft_caster(arg, ap);
			*res += arg->b_count;
			arg = ft_arg_clear(arg);
		}
		arg->i += 1;
	}
	*res += ft_putstr_w(s, '\0', p);
	ft_strdel(&s);
	return (arg);
}

int					ft_putstr_w(char *s, char c, int start)
{
	unsigned int	i;
	char			*tmp;
	int				s_start;

	i = 0;
	tmp = NULL;
	s_start = start;
	if (s)
	{
		while (s[start] != '\0' && s[start] != c)
		{
			start++;
			i++;
		}
		tmp = ft_strnew(i);
		start = 0;
		while (s[s_start] != '\0' && s[s_start] != c)
		{
			tmp[start++] = s[s_start];
			s_start++;
		}
		write(1, tmp, i);
		ft_strdel(&tmp);
	}
	return (i);
}

t_flags				*ft_arg_clear(t_flags *arg)
{
	arg->plus = 0;
	arg->minus = 0;
	arg->space = 0;
	arg->sharp = 0;
	arg->zero = 0;
	arg->width = -1;
	arg->precision = -1;
	arg->size = '0';
	arg->type = '0';
	arg->b_count = 0;
	arg->neg = 0;
	arg->i = arg->i;
	return (arg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:37:51 by vhavryle          #+#    #+#             */
/*   Updated: 2018/01/08 17:37:54 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/libftprintf.h"

t_flags		*ft_pars_arg(char *arg_s, t_flags *arg)
{
	int i;

	i = 0;
	if (arg_s[i + 1] != '\0' && arg_s[i] != '\0')
	{
		while ((arg_s[++i] == '+' || arg_s[i] == '-' || arg_s[i] == ' '
			|| arg_s[i] == '#' || arg_s[i] == '0') && arg_s[i] != '\0')
		{
			if (arg_s[i] == '-')
				arg->minus = 1;
			else if (arg_s[i] == '+')
				arg->plus = 1;
			else if (arg_s[i] == '0')
				arg->zero = 1;
			else if (arg_s[i] == ' ')
				arg->space = 1;
			else if (arg_s[i] == '#')
				arg->sharp = 1;
		}
	}
	arg = ft_pars_width(arg_s, arg, i);
	return (arg);
}

t_flags		*ft_pars_width(char *s, t_flags *arg, int i)
{
	char	*width;
	int		l;
	int		j;

	l = 0;
	i--;
	j = i;
	while (s[++i] >= '0' && s[i] <= '9' && s[i] != '\0')
		l++;
	width = ft_strnew(l);
	i = -1;
	while (s[++j] >= '0' && s[j] <= '9' && s[j] != '\0')
		width[++i] = s[j];
	arg->width = ft_atoi(width);
	arg = ft_pars_precision(s, arg, j);
	ft_strdel(&width);
	return (arg);
}

t_flags		*ft_pars_precision(char *s, t_flags *arg, int i)
{
	char	*precision;
	int		l;
	int		j;

	l = 0;
	j = i;
	if (s[i] == '.')
	{
		while (s[++i] >= '0' && s[i] <= '9' && s[i] != '\0')
			l++;
		precision = ft_strnew(l);
		i = -1;
		while (s[++j] >= '0' && s[j] <= '9' && s[j] != '\0')
			precision[++i] = s[j];
		arg->precision = ft_atoi(precision);
		ft_strdel(&precision);
		if (l == 0)
			arg->precision = 0;
	}
	arg = ft_pars_size(s, arg, j);
	return (arg);
}

t_flags		*ft_pars_size(char *s, t_flags *arg, int i)
{
	while (ft_strchr("zjlh", s[i]) != NULL && s[i] != '\0')
	{
		if (s[i] == 'z')
			arg->size = 'z';
		else if (s[i] == 'j')
			arg->size = 'j';
		else if (ft_strnstr(s + i, "ll", 2) != NULL)
			arg->size = 'L';
		else if (s[i] == 'l')
			arg->size = 'l';
		else if (s[i] == 'h' && ft_strnstr(s + i, "hh", 2) == NULL)
			arg->size = 'h';
		else if (ft_strnstr(s + i, "hh", 2) != NULL)
			arg->size = 'H';
		if (arg->size != '0')
			(arg->size == 'H' || arg->size == 'L') ? i += 2 : i++;
	}
	arg = ft_pars_type(s, arg, i);
	return (arg);
}

t_flags		*ft_pars_type(char *s, t_flags *arg, int i)
{
	arg->type = s[i];
	if (arg->plus == 1)
		arg->space = 0;
	if (arg->minus == 1)
		arg->zero = 0;
	arg->i += i;
	return (arg);
}

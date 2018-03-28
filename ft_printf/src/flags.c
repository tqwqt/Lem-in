/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:01:07 by vhavryle          #+#    #+#             */
/*   Updated: 2018/01/24 15:01:08 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/libftprintf.h"

t_flags				*ft_flag_check(t_flags *arg, int arg_len)
{
	int				i;
	char			c;
	char			*tmp;

	c = ' ';
	tmp = NULL;
	i = 0;
	if (arg->width > arg->precision && arg->precision != -1)
		arg->zero = 0;
	else
		arg->zero = arg->zero;
	if (arg->width > 0 && arg_len < arg->width)
	{
		i = arg->width - arg_len - arg->neg;
		if ((arg->zero == 1 && arg->minus == 0))
			c = '0';
		if (arg->plus == 1 && arg->neg != 1)
			i--;
		arg->b_count += i;
		tmp = ft_memset(ft_strnew(i), c, i);
		write(1, tmp, i);
		ft_strdel(&tmp);
	}
	return (arg);
}

t_flags				*ft_space_check(t_flags *arg)
{
	if (arg->space == 1 && arg->plus == 0 && arg->minus != 1)
	{
		write(1, " ", 1);
		arg->b_count++;
		arg->space = 0;
		arg->width--;
	}
	return (arg);
}

int					ft_z_init(unsigned char mask)
{
	if (mask == 224)
		return (2);
	if (mask == 240)
		return (3);
	return (1);
}

char				*ft_add_prec(char *s, int prec)
{
	int				k;
	char			*new;
	int				len;
	char			*tmp;

	k = 0;
	len = ft_strlen(s);
	if (prec > len && len > -1)
		k = prec - len;
	new = ft_strnew(k);
	while (k--)
		new[k] = '0';
	tmp = new;
	new = ft_strjoin(new, s);
	ft_strdel(&tmp);
	return (new);
}

int					ft_put_prec(char *s, int prec, int arg_len)
{
	unsigned int	i;
	int				j;
	int				k;

	i = 0;
	j = -1;
	k = 0;
	if (prec > arg_len && arg_len > -1)
		k = prec - arg_len;
	if (prec < arg_len)
		prec = arg_len;
	if (s)
	{
		while (k--)
			write(1, "0", 1);
		while (s[++j] != '\0' && prec--)
		{
			write(1, &s[j], 1);
			i++;
		}
	}
	return (i);
}

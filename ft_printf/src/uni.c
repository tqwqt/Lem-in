/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:05:57 by vhavryle          #+#    #+#             */
/*   Updated: 2018/02/04 14:05:59 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/libftprintf.h"

int					ft_str_uni_len(wchar_t *str)
{
	int				i;

	i = 0;
	while (str[i] != L'\0')
		i++;
	return (i);
}

int					ft_count_bytes(int act)
{
	if (act <= 7)
		return (1);
	else if (act > 7 && act < 12)
		return (2);
	else if (act > 11 && act < 17)
		return (3);
	else if (act > 16)
		return (4);
	return (0);
}

int					ft_pars_uni(wchar_t a, t_flags *arg, int bits)
{
	int				act;
	unsigned char	mask;

	mask = 0;
	act = ft_act_bits(a);
	if (act <= 7 || MB_CUR_MAX == 1)
	{
		act = (char)a;
		arg->b_count += 1;
		write(1, &act, 1);
		return (--bits);
	}
	else if (act > 7 && act < 12)
		mask = 192;
	else if (act > 11 && act < 17)
		mask = 224;
	else if (act > 16)
		mask = 240;
	return (ft_put_uni(arg, mask, a, bits));
}

int					ft_put_uni(t_flags *arg, unsigned char mask, wchar_t a,
	int bits)
{
	int				z;
	wchar_t			ac;

	z = ft_z_init(mask);
	if (z + 1 > bits)
		return (0);
	arg->b_count += z + 1;
	ac = a;
	ac >>= 6 * z;
	ac = mask | ac;
	write(1, &ac, 1);
	bits--;
	while (z-- && bits-- > 0)
	{
		mask = 128;
		ac = a;
		ac &= (63 << (6 * z));
		if (z != 0)
			ac >>= 6 * z;
		ac |= mask;
		write(1, &ac, 1);
	}
	return (bits);
}

int					ft_kostil_wchar_prec_len(wchar_t *a, t_flags *arg)
{
	int				act;
	int				i;
	int				z;
	int				ret;

	i = -1;
	ret = 0;
	while (a[++i] != L'\0')
	{
		z = 0;
		act = ft_act_bits(a[i]);
		if (act <= 7)
			z = 1;
		else if (act > 7 && act < 12)
			z = 2;
		else if (act > 11 && act < 17)
			z = 3;
		else if (act > 16)
			z = 4;
		if (arg->precision >= ret + z)
			ret += z;
	}
	return (ret);
}

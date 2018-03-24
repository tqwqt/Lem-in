/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:24:02 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/09 14:24:05 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strequ(const char *s1, const char *s2)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		a = s1[i];
		b = s2[i];
		while (a == b)
		{
			i++;
			a = s1[i];
			b = s2[i];
			if (a == '\0' && b == '\0')
				return (1);
		}
	}
	return (0);
}

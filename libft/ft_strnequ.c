/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:33:40 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/09 14:33:41 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	b;

	if (!n)
		return (1);
	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		a = s1[i];
		b = s2[i];
		while (a == b)
		{
			if ((a == '\0' && b == '\0') || n == 1)
				return (1);
			--n;
			a = s1[++i];
			b = s2[i];
		}
	}
	return (0);
}

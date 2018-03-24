/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:34:54 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/04 16:34:56 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memmove(void *dest, void *src, int len)
{
	char	*d;
	char	*s;

	d = dest;
	s = src;
	if (d > s)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	else
		while (len--)
			*(d++) = *(s++);
	return (&dest[0]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:10:56 by vhavryle          #+#    #+#             */
/*   Updated: 2017/10/30 17:11:00 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = dest;
	s = (char*)src;
	while (n--)
	{
		*(d++) = *(s++);
	}
	return (&dest[0]);
}

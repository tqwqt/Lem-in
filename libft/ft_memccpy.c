/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:10:35 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/04 18:11:16 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void		*ft_memccpy(void *dst, void *src, int c, int len)
{
	int		i;
	char	*s;
	char	*d;

	i = -1;
	s = src;
	d = dst;
	while (++i < len)
	{
		d[i] = s[i];
		if ((unsigned char)s[i] == (unsigned char)c)
			return (&d[i + 1]);
	}
	return (NULL);
}

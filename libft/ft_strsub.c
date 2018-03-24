/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:39:57 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/09 14:39:59 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	int		i;
	char	*new;

	if (s)
	{
		if ((new = ft_strnew(len)) != NULL)
		{
			i = -1;
			while (len--)
				new[++i] = s[start++];
			return (new);
		}
	}
	return (NULL);
}

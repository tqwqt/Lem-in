/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:26:33 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/07 12:26:35 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (i == 0)
		return (NULL);
	if (c == '\0')
		return ((char*)&s[i]);
	while (--i != -1)
		if (s[i] == c)
			return ((char*)&s[i]);
	return (NULL);
}

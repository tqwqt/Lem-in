/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:18:45 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/09 14:18:47 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new;

	if (s)
	{
		if ((new = ft_strnew(ft_strlen(s))) != NULL)
		{
			i = -1;
			while (s[++i] != '\0')
				new[i] = (*f)(i, s[i]);
		}
		return (new);
	}
	return (NULL);
}

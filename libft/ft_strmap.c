/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:49:49 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/09 13:49:52 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	char	*new;

	if (s)
	{
		if ((new = ft_strnew(ft_strlen(s))) != NULL)
		{
			i = -1;
			while (s[++i] != '\0')
				new[i] = (*f)(s[i]);
		}
		return (new);
	}
	return (NULL);
}

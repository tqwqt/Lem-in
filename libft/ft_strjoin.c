/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:53:18 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/09 14:53:19 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	int		l;
	int		ll;
	int		i;

	if (s1 && s2)
	{
		l = ft_strlen(s1);
		ll = ft_strlen(s2);
		i = 0;
		if ((new = ft_strnew(l + ll)) != NULL)
		{
			while (l--)
				new[i++] = *s1++;
			while (ll--)
				new[i++] = *s2++;
			new[i] = '\0';
			return (new);
		}
	}
	return (NULL);
}

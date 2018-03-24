/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:33:15 by vhavryle          #+#    #+#             */
/*   Updated: 2017/10/26 12:33:18 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	a = s1[i];
	b = s2[i];
	if (n == 0)
		return (0);
	while (a == b && ++i < n)
	{
		a = s1[i];
		b = s2[i];
		if (a == '\0' && b == '\0')
			return (0);
	}
	return (a - b);
}

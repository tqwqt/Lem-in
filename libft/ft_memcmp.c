/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:20:58 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/06 18:20:59 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(void *s1, void *s2, size_t n)
{
	while (n--)
		if (*(unsigned char *)s1++ != *(unsigned char *)s2++)
			return (*(unsigned char*)--s1 - *(unsigned char*)--s2);
	return (0);
}

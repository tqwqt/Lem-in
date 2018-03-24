/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:43:59 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/07 15:44:00 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*p;

	if ((p = malloc(size * sizeof(void*))) != NULL)
	{
		ft_bzero(p, size);
		return (p);
	}
	return (NULL);
}

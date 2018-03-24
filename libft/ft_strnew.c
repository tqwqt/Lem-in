/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:04 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/07 16:51:06 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	void	*new;

	new = malloc(size + 1);
	if (!new)
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}

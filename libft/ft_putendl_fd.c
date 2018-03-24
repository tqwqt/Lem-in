/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:51:02 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/11 15:51:05 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	int i;

	i = -1;
	if (s)
	{
		while (s[++i])
			ft_putchar_fd(s[i], fd);
		ft_putchar_fd('\n', fd);
	}
}

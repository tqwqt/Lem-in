/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:36:53 by vhavryle          #+#    #+#             */
/*   Updated: 2018/03/30 12:42:25 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/lemin.h"

void		write_info(char *info)
{
	if (info)
	{
		write(1, info, ft_strlen(info));
		write(1, "\n", 1);
	}
}

void		error_exit(char *info)
{
	int i;

	i = 1;
	ft_printf("ERROR:^%s\n", info);
	free(g_farm);
	exit(0);
}

void		error_cont(char *info)
{
	ft_printf("ERROR:^%s, reading stopped\n", info);
}

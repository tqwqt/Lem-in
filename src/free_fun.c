/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:53:21 by vhavryle          #+#    #+#             */
/*   Updated: 2018/03/30 13:02:27 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/lemin.h"

void		free_data(char ***data)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = *data;
	while (tmp[++i] != NULL)
		ft_strdel(&tmp[i]);
	free(tmp);
}

void		free_rooms(t_rooms **head)
{
	if (head && *head)
	{
		if ((*head)->next)
			free_rooms(&(*head)->next);
		free((*head)->name);
		free((*head)->links);
		free(*head);
	}
}

void		free_arr(char ***arr)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = *arr;
	if (tmp)
	{
		while (tmp[++i])
			ft_strdel(&tmp[i]);
		free(tmp);
	}
}

void		free_ants(t_ant ***ants)
{
	t_ant	**tmp;
	int		i;

	i = -1;
	tmp = *ants;
	while (tmp[++i])
	{
		free(tmp[i]);
	}
	free(tmp);
}

void		print_ants_steps(int n, char *name)
{
	if (g_farm->is_first_ant == 1)
	{
		ft_printf("L%d-%s", n, name);
		g_farm->is_first_ant = 0;
	}
	else
		ft_printf(" L%d-%s", n, name);
}

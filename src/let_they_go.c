/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_they_go.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:05:39 by vhavryle          #+#    #+#             */
/*   Updated: 2018/03/30 13:04:50 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/lemin.h"

void			lets_go(t_rooms **head, int i, int ind, t_rooms *fin)
{
	t_ant		**ants;

	ants = get_ants(g_farm->ants, get_start(head));
	ft_printf("\n");
	while (g_farm->ants > fin->ants_in)
	{
		i = -1;
		while (ants[++i] != NULL)
		{
			ind = ind_of_empty_r(ants[i]->room, -1);
			if (ind != -1)
			{
				ants[i]->room->ants_in--;
				ants[i]->room = ants[i]->room->links[ind];
				print_ants_steps(ants[i]->number, ants[i]->room->name);
				if (ants[i]->room->is_f != 1)
					ants[i]->room->ants_in = 1;
				else
					ants[i]->room->ants_in++;
			}
		}
		ft_printf("\n");
		g_farm->is_first_ant = 1;
	}
	free_ants(&ants);
}

int				lin_len(t_rooms **links)
{
	int			i;

	i = 0;
	while (links[i])
		i++;
	return (i);
}

int				ind_of_empty_r(t_rooms *r, int i)
{
	int			*indxs;
	int			len;
	int			ret;

	if (r->is_f == 1)
		return (-1);
	len = lin_len(r->links);
	indxs = ind_alloc(len);
	len = -1;
	while (r->links[++i])
	{
		if (r->links[i]->is_f == 1)
		{
			free(indxs);
			return (i);
		}
		if (r->links[i]->ants_in == 0 && r->links[i]->dist != 2147483647)
			indxs[++len] = i;
	}
	ret = best_room(indxs, len, r);
	free(indxs);
	return (ret);
}

int				best_room(int *indxs, int len, t_rooms *r)
{
	int			ret;
	int			i;

	i = 0;
	if (indxs[0] == -1)
		return (-1);
	ret = indxs[0];
	while (i < len && indxs[++i] && indxs[i] != -1)
		if (r->links[indxs[i]]->dist < r->links[ret]->dist)
			ret = indxs[i];
	return (ret);
}

int				*ind_alloc(int len)
{
	int			i;
	int			*indxs;

	indxs = malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
		indxs[i] = -1;
	return (indxs);
}

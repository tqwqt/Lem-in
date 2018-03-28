/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_they_go.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:05:39 by vhavryle          #+#    #+#             */
/*   Updated: 2018/03/23 14:05:40 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/lemin.h"

void lets_go(t_rooms **head)
{
	t_rooms		*fin;
	t_ant		**ants;
	int 		i;
	int			ind;
//	show_list(*head);
	ants = get_ants(g_farm->ants, get_start(head));
	fin = get_fin(head);
	ft_printf("\n");
	while (g_farm->ants > fin->ants_in)
	{
		i = -1;
		while (ants[++i] != NULL)
		{
			ind = ind_of_empty_r(ants[i]->room);
			if (ind != -1)
			{
				ants[i]->room->ants_in--;
				ants[i]->room = ants[i]->room->links[ind];
				ft_printf("L%d-%s ", ants[i]->number, ants[i]->room->name);
				if (ants[i]->room->is_f != 1)
					ants[i]->room->ants_in = 1;
				else
					ants[i]->room->ants_in++;
			}
		}
		ft_printf("\n");
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
int				ind_of_empty_r(t_rooms *r)
{
	int			i;
	int			*indxs;
	int			len;
	int			ret;

	if (r->is_f == 1)
		return (-1);
	len = lin_len(r->links);
	indxs = malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
		indxs[i] = -1;
	i = -1;
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
	i = 0;
	if (indxs[0] == -1)
	{
		free(indxs);
		return (-1);
	}
	ret = indxs[0];
	while (i < len && indxs[++i] && indxs[i] != -1)
		if (r->links[indxs[i]]->dist < r->links[ret]->dist)
			ret = indxs[i];
	free(indxs);
	return (ret);
}

t_rooms *get_fin(t_rooms **head)
{
	t_rooms		*h;

	h = *head;
	while (h && h->is_f != 1)
		h = h->next;
	if (h && h->is_f == 1)
		return (h);
	return (0);
}

t_rooms *get_start(t_rooms **head)
{
	t_rooms		*h;

	h = *head;
	while (h && h->is_s != 1)
		h = h->next;
	if (h && h->is_s == 1)
		return (h);
	return (0);
}

t_ant			**get_ants(int n, t_rooms *start)
{
	t_ant		**new;
	int			a;
	int			i;

	i = -1;
	a = 0;

	new = malloc(sizeof(t_ant*) * (n + 1));
	while ( ++a <= n)
	{
		new[++i] = malloc(sizeof(t_ant));
		new[i]->number = a;
		new[i]->room = start;
	}
	//new[++i] = malloc(sizeof(t_ant));
	new[++i] = NULL;
	return (new);
}

void			free_ants(t_ant ***ants)
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
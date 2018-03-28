/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:24:40 by vhavryle          #+#    #+#             */
/*   Updated: 2018/03/15 13:24:41 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/lemin.h"

t_rooms *new_room_alloc(int *cors, short is_s, short is_f, char *name)
{
	t_rooms	*new;

	if (!(new = (t_rooms *)malloc(sizeof(t_rooms))))
		return (NULL);
	new->is_s = (short) (is_s == 1 && g_farm->start != 1 ? 1 : 0);
	new->is_f = (short) (is_f == 1 && g_farm->end != 1 ? 1 : 0);
	if (is_s && g_farm->start != 1)
	{
		new->ants_in = g_farm->ants;
		new->is_full = 1;
		g_farm->start = 1;
	}
	else if (is_f && g_farm->end != 1)
	{
		new->ants_in = 0;
		new->is_full = 0;
		g_farm->end = 1;
	}
	else
	{
		new->ants_in = 0;
		new->is_full = 0;
	}
	new->name = ft_strdup(name);
	new->cors[0] = cors[0];
	new->cors[1] = cors[1];
	new->next = NULL;
	new->marked = 0;
	if (new->is_f)
		new->dist = 0;
	else
		new->dist = 2147483647;
	new->links = NULL;
	return (new);
}

void push_list_r_back(t_rooms **head, t_rooms *to_push)
{
	t_rooms	*curr;

	curr = NULL;
	curr = *head;
	if (curr)
	{
		while (curr->next)
			curr = curr->next;
		curr->next = to_push;
	}
	else
		*head = to_push;

}


int check_cors(int x, int y, t_rooms *head)
{
	t_rooms	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->cors[0] == x && tmp->cors[1] == y)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void add_list_link(t_rooms *link, t_rooms **room)
{
	t_rooms	*curr;
	t_rooms	**tmp;
	int			i;

	curr = *room;
	if (!curr->links)
	{
		curr->links = malloc(sizeof(t_rooms*) * 2);
		curr->links[0] = link;
		curr->links[1] = NULL;
		return ;
	}
	i = 0;
	while (curr->links[i] != NULL)
		i++;
	tmp = curr->links;
	curr->links = list_join_links(&curr->links, i, link);
	free(tmp);
//	free_rooms(&tmp, i);
//	curr->links[i] = link;
	//curr->links[++i] = malloc(sizeof(t_rooms*));
	//curr->links[i] = NULL;
}

void free_rooms(t_rooms **head)
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

t_rooms **list_join_links(t_rooms ***old, int size, t_rooms *link)
{
	t_rooms	**new;
	t_rooms	**oldi;

	oldi = *old;
	int 	i;

	i = -1;
	new = malloc(sizeof(t_rooms*) * (size + 2));
	while (oldi[++i] != 0)
		new[i] = oldi[i];
	new[i] = link;
	new[++i] = NULL;
	return (new);
}
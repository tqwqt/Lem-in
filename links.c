/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:44:46 by vhavryle          #+#    #+#             */
/*   Updated: 2018/03/20 13:44:53 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void the_links(char *line)
{	
	int		ret;
	t_rooms	*r;
	short	f;

	ret = 1;
	f = 0;
	if (g_farm->start == 0 || g_farm->end == 0)
	{
		free_rooms(&g_rooms);
		free(g_farm);
		error_exit("there is no start || end room");
	}
	while (ret > 0)
	{
		write_info(line);
		if (is_comment(line) == 0)
			if (is_link(line) == 0)
			{
				ft_strdel(&line);
				break ;
			}
		if (f == 1)
			ft_strdel(&line);
		ret = get_next_line(g_farm->fd, &line);
		f = 1;
	}
	r = get_fin();
	if (mark_the_way(&r) == 0)
	{
		free_rooms(&g_rooms);
		free(g_farm);
		error_exit("no connection between start & end");
	}
	lets_go();
}


int			is_comment(char *line)
{	
	if (line)
	{
		if (line[0] == '#' && !ft_strequ("#start", line) && !ft_strequ("#end", line))
		return (1);
	}
	return (0);
}

int 		is_link(char *line)
{
	char	**split;
	int 	i;
	t_rooms	*r1;
	t_rooms	*r2;

	i = 0;
	split = ft_strsplit(line, '-');
	while (split[i] != NULL)
		i++;
	if (i != 2)
	{
		error_cont("non 2 args");
		free_arr(&split);
		return (0);
	}
	r1 = find_by_name(split[0]);
	r2 = find_by_name(split[1]);
	if (r1 && r2)
	{
		if (ft_strequ(r1->name, r2->name))
		{
			error_cont("equal mames");
			free_arr(&split);
			return (0);
		}
		add_list_link(r1, &r2);
		add_list_link(r2, &r1);
	}
	else
	{
		error_cont("can't find room name");
		free_arr(&split);
		return (0);
	}
	free_arr(&split);
	return (1);
}

t_rooms			*find_by_name(char	*name)
{
	t_rooms		*tmp;

	tmp = g_rooms;
	if (name)
	{	
		while (tmp)
		{
			if (ft_strequ(tmp->name, name))
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (NULL);
}

int			mark_the_way(t_rooms **room)
{
	t_rooms		*r;
	int			i;
	int			s_f_way;

	r = *room;
	i = 0;
	s_f_way = 0;
	r->marked = 1;
	while (r->links && r->links[i] != 0)
	{
		if (is_s_in_links(r->links) == 1)
		{
			r->marked = 0;
			s_f_way = 1;
		}
		else if (r->links[i]->marked == 0 && r->links[i]->is_f != 1) //&& r->links[i]->dist == 2147483647)
		{
			if (links_num(r->links[i]) > 1)
				r->links[i]->dist = r->dist + 1 < r->links[i]->dist ? r->dist + 1 : r->links[i]->dist ;
			mark_the_way(&r->links[i]);
		}
		i++;
	}
	r->marked = 0;
	return (s_f_way);
}

int			is_s_in_links(t_rooms	**links)
{
	int		i;

	i = -1;
	while (links[++i])
		if (links[i]->is_s == 1) //|| links[i]->is_f == 1)
			return (1);
	return (0);
}
int			links_num(t_rooms *r)
{
	int		i;

	i = 0;
	while (r->links[i])
		i++;
	return (i);
}

void		free_arr(char ***arr)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = *arr;
	while (tmp[++i])
		ft_strdel(&tmp[i]);
	free(tmp);

}

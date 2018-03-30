/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:44:46 by vhavryle          #+#    #+#             */
/*   Updated: 2018/03/30 13:12:03 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/lemin.h"

void		the_links(char *line, t_rooms **head)
{
	int		ret;

	ret = 1;
	if (g_farm->start == 0 || g_farm->end == 0)
	{
		free_rooms(head);
		ft_strdel(&line);
		error_exit("there is no start || end room");
	}
	while (ret > 0)
	{
		write_info(line);
		if (is_comment(line) == 0)
			if (is_link(line, &head) == 0)
			{
				ft_strdel(&line);
				break ;
			}
		ft_strdel(&line);
		ret = get_next_line(g_farm->fd, &line);
	}
	find_end_mark(head);
}

void		find_end_mark(t_rooms **head)
{
	t_rooms	*r;

	r = get_fin(head);
	if (mark_the_way(&r, 0) == 0)
	{
		free_rooms(head);
		error_exit("no connection between start & end");
	}
	lets_go(head, -1, -1, get_fin(head));
}

int			is_link(char *line, t_rooms ***head)
{
	char	**split;
	int		i;
	t_rooms	*r1;
	t_rooms	*r2;

	i = 0;
	split = ft_strsplit(line, '-');
	while (split && split[i] != NULL)
		i++;
	if (i != 2)
	{
		error_cont("non 2 args");
		free_arr(&split);
		return (0);
	}
	r1 = find_by_name(split[0], &head);
	r2 = find_by_name(split[1], &head);
	if (valid_n_link(r1, r2) == 0)
	{
		free_arr(&split);
		return (0);
	}
	free_arr(&split);
	return (1);
}

int			valid_n_link(t_rooms *r1, t_rooms *r2)
{
	if (r1 && r2)
	{
		if (ft_strequ(r1->name, r2->name))
		{
			error_cont("equal mames");
			return (0);
		}
		add_list_link(r1, &r2);
		add_list_link(r2, &r1);
	}
	else
	{
		error_cont("can't find room name");
		return (0);
	}
	return (1);
}

int			links_num(t_rooms *r)
{
	int		i;

	i = 0;
	while (r->links[i] && i < 3)
		i++;
	return (i);
}

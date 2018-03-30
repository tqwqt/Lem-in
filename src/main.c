/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:22:59 by vhavryle          #+#    #+#             */
/*   Updated: 2018/03/30 13:14:23 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/lemin.h"

int			main(void)
{
	char	*line;
	t_rooms	*rooms;

	g_farm = malloc(sizeof(t_farm));
	g_farm->fd = 0;
	g_farm->start = 0;
	g_farm->end = 0;
	g_farm->sf_way = 0;
	g_farm->is_first_ant = 1;
	get_num_ants();
	rooms = NULL;
	line = the_rooms(&rooms);
	the_links(line, &rooms);
	free_rooms(&rooms);
	free(g_farm);
	return (0);
}

int			is_room_spaces(char *line)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (line[++i] != '\0')
		if (line[i] == ' ')
			j++;
	if (j == 2)
		return (1);
	return (0);
}

char		*the_rooms(t_rooms **head)
{
	char	*line;
	short	sf[4];
	int		ret;

	ret = 1;
	sf[0] = 0;
	sf[1] = 0;
	sf[2] = 0;
	sf[3] = 0;
	while (ret > 0)
	{
		ret = get_next_line(g_farm->fd, &line);
		if (ft_strchr(line, '-') != NULL)
			return (line);
		write_info(line);
		room_commands(line, sf, head);
		ft_strdel(&line);
	}
	return (0);
}

int			is_comment(char *line)
{
	if (line)
	{
		if (line[0] == '#' && !ft_strequ("#start", line)
				&& !ft_strequ("#end", line))
			return (1);
	}
	return (0);
}

int			mark_the_way(t_rooms **room, int i)
{
	t_rooms	*r;

	r = *room;
	r->marked = 1;
	while (r->links && r->links[i] != 0 && i < 200)
	{
		if (r->links[i]->is_s == 1)
		{
			r->links[i]->marked = 0;
			g_farm->sf_way = 1;
		}
		else if (r->links[i]->marked == 0 && r->links[i]->is_f != 1)
		{
			if (links_num(r->links[i]) > 1)
			{
				r->links[i]->dist = r->dist + 1 <
					r->links[i]->dist ? r->dist + 1 : r->links[i]->dist;
				mark_the_way(&r->links[i], 0);
			}
		}
		i++;
	}
	if (r->links)
		r->links[i - 1]->marked = 0;
	return (g_farm->sf_way);
}

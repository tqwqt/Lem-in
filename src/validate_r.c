/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:39:50 by vhavryle          #+#    #+#             */
/*   Updated: 2018/03/30 12:42:58 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/lemin.h"

void		room_commands(char *line, short *sf, t_rooms **head)
{
	if (ft_strequ("##start", line) && sf[2] != 1)
	{
		sf[2] = (short)(sf[0] == 1 ? 1 : 0);
		sf[0] = 1;
	}
	if (ft_strequ("##start", line) && sf[2] == 1)
	{
		ft_strdel(&line);
		error_exit("double ##start");
	}
	if (ft_strequ("##end", line) && sf[3] != 1)
	{
		sf[3] = (short)(sf[1] == 1 ? 1 : 0);
		sf[1] = 1;
	}
	if (ft_strequ("##end", line) && sf[3] == 1)
	{
		ft_strdel(&line);
		error_exit("double ##end");
	}
	if (line && line[0] != '#')
		*head = room_validate(line, sf[0], sf[1], head);
}

t_rooms		*room_validate(char *line, short s, short f, t_rooms **head)
{
	char	**data;
	int		cors[2];
	t_rooms	*tmp;

	tmp = *head;
	if (!is_room_spaces(line))
		error_exit("incorrect number of spaces");
	data = ft_strsplit(line, ' ');
	is_data_valid(data, 0);
	cors[0] = ft_atoi(data[1]);
	cors[1] = ft_atoi(data[2]);
	if (check_cors(cors[0], cors[1], *head) == 1)
	{
		error_exit("this cors are already exist");
		free_data(&data);
	}
	if (check_name(data[0], *head) == 1)
	{
		free_rooms(head);
		error_exit("room with this name is already exist");
	}
	push_list_r_back(&tmp, new_room_alloc(cors, s, f, data[0]));
	free_data(&data);
	return (tmp);
}

int			is_data_valid(char **data, int i)
{
	while (data && data[i] != NULL)
		i++;
	if (i != 3)
	{
		free_data(&data);
		error_exit("args room != 3");
	}
	if (data[0][0] == 'L')
	{
		free_data(&data);
		error_exit("name starts with L");
	}
	if (ft_str_is_digit(data[1]) != 1 || ft_str_is_digit(data[2]) != 1)
	{
		free_data(&data);
		error_exit("cors are incorrect");
	}
	return (1);
}

int			check_name(char *name, t_rooms *head)
{
	while (head)
	{
		if (ft_strequ(head->name, name) == 1)
			return (1);
		head = head->next;
	}
	return (0);
}

int			check_cors(int x, int y, t_rooms *head)
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

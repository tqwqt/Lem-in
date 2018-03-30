/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:59:26 by vhavryle          #+#    #+#             */
/*   Updated: 2018/03/30 14:16:30 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/lemin.h"

t_rooms			*get_fin(t_rooms **head)
{
	t_rooms		*h;

	h = *head;
	while (h && h->is_f != 1)
		h = h->next;
	if (h && h->is_f == 1)
		return (h);
	return (0);
}

t_rooms			*get_start(t_rooms **head)
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
	if (!(new = malloc(sizeof(t_ant*) * (n + 1))))
		error_exit("cannot allocate memory, to much ants");
	while (++a <= n)
	{
		new[++i] = malloc(sizeof(t_ant));
		new[i]->number = a;
		new[i]->room = start;
	}
	new[++i] = NULL;
	return (new);
}

void			get_num_ants(void)
{
	char		*l;
	int			ret;

	ret = 1;
	g_farm->ants = -1;
	while (g_farm->ants == -1 && ret > 0)
	{
		ret = get_next_line(g_farm->fd, &l);
		write_info(l);
		if (l && !(l[0] == '#' && !ft_strequ("#start", l)
				&& !ft_strequ("#end", l)))
		{
			if (ft_str_is_digit(l))
				g_farm->ants = ft_atoi(l);
			else
			{
				ft_strdel(&l);
				error_exit("not valid ants num line");
			}
		}
		ft_strdel(&l);
	}
	if (g_farm->ants <= 0 || g_farm->ants >= 2147483647)
		error_exit("invalid number of ants || empty line");
}

t_rooms			*find_by_name(char *name, t_rooms ****head)
{
	t_rooms		*tmp;

	tmp = ***head;
	if (name != NULL)
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


#include <fcntl.h>
#include <zconf.h>
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
	//show_list(rooms);
	the_links(line, &rooms);
	free_rooms(&rooms);
	free(g_farm);
	return 0;
}

void		get_num_ants()
{
	char	*l;
	int		ret;

	ret = 1;
	g_farm->ants = -1;
	while (g_farm->ants == -1 && ret > 0)
	{
		ret = get_next_line(g_farm->fd, &l);
		write_info(l);
		if (l && !(l[0] == '#' && !ft_strequ("#start", l) && !ft_strequ("#end", l)))
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
	if (g_farm->ants <= 0)
		error_exit("ants <= 0 || empty line");
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

char		*the_rooms(t_rooms **head)//валидация и создание комнат
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

void		room_commands(char *line, short *sf, t_rooms **head)
{
	if (ft_strequ("##start", line) && sf[2] != 1)//if 2 starts & 2 ends
	{
		sf[2] = (short) (sf[0] == 1 ? 1 : 0);
		sf[0] = 1;
	}
	if (ft_strequ("##start", line) && sf[2] == 1)
	{
		ft_strdel(&line);
		error_exit("double ##start");
	}
	if (ft_strequ("##end", line) && sf[3] != 1)
	{
		sf[3] = (short) (sf[1] == 1 ? 1 : 0);
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

void		write_info(char *info)
{
	if (info)
	{
		write(1, info, ft_strlen(info));
		write(1, "\n", 1);
	}
}

void error_exit(char *info)
{
	int i;

	i = 1;
	ft_printf("ERROR:^%s\n", info);
	free(g_farm);
	exit(0);
}

void error_cont(char *info)
{
	ft_printf("ERROR:^%s, reading stopped\n", info);
}

void		show_list(t_rooms *head)
{
	int i;

	if (!head)
		ft_printf("NULL hEAf\n");
	while (head)
	{
		i = -1;
		ft_printf("list[%-5s] dist[%10d] = full: %d, ants: %3d, s: %d, f: %d, cors = %d, %d \n", head->name,head->dist, head->is_full, head->ants_in, head->is_s, head->is_f, head->cors[0], head->cors[1]);
//		if (head->links)
//		{
//			while (head->links[++i] != NULL)
//			{
//				printf("lin = %s\n", head->links[i]->name);
//			}
//		}
		head = head->next;
	}
}

t_rooms		*room_validate(char *line, short s, short f, t_rooms **head) // проверить одинаковые коры комнат
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

void		free_data(char ***data)
{
	char **tmp;
	int 	i;

	i = -1;
	tmp= *data;
	while (tmp[++i] != NULL)
		ft_strdel(&tmp[i]);
	free(tmp);
}

int check_name(char *name, t_rooms *head)
{
	while (head)
	{
		if (ft_strequ(head->name, name) == 1)
			return (1);
		head = head->next;
	}
	return (0);
}

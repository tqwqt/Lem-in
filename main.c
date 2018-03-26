#include <stdio.h>
#include <fcntl.h>
#include <zconf.h>
#include "lemin.h"
#include "gnl/get_next_line.h"


void		show_list(t_rooms *head);

int			main(int ac, char **av)
{
	int		fd;
	char	*line;
	//t_farm	*farm;

	if (ac != 2 && ac != 1)
	{
		perror("ERROR: incorrect number of args");
		return 0;
	}
	g_farm = malloc(sizeof(t_farm));
	if (ac == 1)
		g_farm->fd = 0;
	else
		g_farm->fd = open(av[1], O_RDWR);
	g_farm->start = 0;
	g_farm->end = 0;
	g_farm->sf_way = 0;
	get_num_ants();
	the_rooms();
	free_rooms(&g_rooms);
	free(g_farm);
	return 0;
}

void		get_num_ants()
{
	char	*line;
	int		ret;

	ret = 1;
	g_farm->ants = -1;
	while (g_farm->ants == -1 && ret > 0)
	{
		ret = get_next_line(g_farm->fd, &line);
		write_info(line);
		if (line && !(line[0] == '#' && !ft_strequ("#start", line) && !ft_strequ("#end", line)))
		{
			if (ft_str_is_digit(line))
				g_farm->ants = ft_atoi(line);
			else
				error_exit("no valid ants num");
		}
		ft_strdel(&line);
	}
	if (g_farm->ants <= 0)
		error_exit("ants <= 0");
}

int			room_validate(char *line, short s, short f) // проверить одинаковые коры комнат
{
	char	**data;
	int		i;
	int		cors[2];

	i = 0;
	if (!is_room_spaces(line))
		error_exit("incorrect number of spaces");
	data = ft_strsplit(line, ' ');
	while (data[i] != NULL)
		i++;
	if (i != 3)
	{
		error_exit("args room != 3");
		free_data(&data);
	}
	if (data[0][0] == 'L')
	{
		error_exit("name starts with L");
		free_data(&data);
	}
	if (ft_str_is_digit(data[1]) != 1 || ft_str_is_digit(data[2]) != 1)
	{
		error_exit("cors are incorrect");
		free_data(&data);
	}
	cors[0] = ft_atoi(data[1]);
	cors[1] = ft_atoi(data[2]);
	if (check_cors(cors[0], cors[1]) == 1)
	{
		error_exit("this cors are already exist");
		free_data(&data);
	}
	push_list_r_back(&g_rooms, new_room_alloc(cors, s, f, data[0]));
	free_data(&data);
	return (1);
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
void		the_rooms()//валидация и создание комнат
{
	char	*line;
	short	sf[4];
	int		ret;

	ret = 1;
	g_rooms = NULL;
	sf[0] = 0;
	sf[1] = 0;
	sf[2] = 0;
	sf[3] = 0;
	while (ret > 0)
	{
		ret = get_next_line(g_farm->fd, &line);
		if (ft_strchr(line, '-') != NULL)
		{	//show_list(g_rooms);
			the_links(line);
			ft_strdel(&line);
			return ;
		}
		write_info(line);
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
			room_validate(line, sf[0], sf[1]);
		ft_strdel(&line);
	}
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
	printf("ERROR:^%s\n", info);
	//while (1)
	//	i = i;
	exit(0);
}

void error_cont(char *info)
{

	printf("ERROR:^%s, reading stopped\n", info);

}

void		show_list(t_rooms *head)
{
	int i;
//

	while (head)
	{
		i = -1;
		printf("list[%-5s] dist[%10d] = full: %d, ants: %3d, s: %d, f: %d \n", head->name,head->dist, head->is_full, head->ants_in, head->is_s, head->is_f);
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
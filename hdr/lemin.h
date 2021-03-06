/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:06:58 by vhavryle          #+#    #+#             */
/*   Updated: 2018/03/30 13:38:34 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <fcntl.h>
# include <zconf.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/hdr/libftprintf.h"

typedef struct		s_struct
{
	int				ants;
	int				fd;
	short			start;
	short			end;
	short			sf_way;
	short			is_first_ant;
}					t_farm;

typedef struct		s_list_r
{
	struct s_list_r	**links;
	struct s_list_r	*next;
	char			*name;
	short			is_s;
	short			is_f;
	int				ants_in;
	int				dist;
	short			marked;
	int				cors[2];
}					t_rooms;

typedef struct		s_ant
{
	int				number;
	t_rooms			*room;
}					t_ant;

void				print_ants_steps(int n, char *name);
int					*ind_alloc(int len);
void				lets_go(t_rooms **head, int i, int ind, t_rooms *fin);
void				free_ants(t_ant ***ants);
t_ant				**get_ants(int n, t_rooms *start);
void				free_data(char	***data);
t_farm				*g_farm;
int					is_comment(char *line);
void				the_links(char *line, t_rooms **head);
int					is_link(char *line, t_rooms ***head);
t_rooms				*find_by_name(char *name, t_rooms ****head);
int					check_cors(int x, int y, t_rooms *head);
void				get_num_ants();
void				write_info(char *info);
void				error_exit(char *info);
t_rooms				*room_validate(char *line,
		short s, short f, t_rooms **head);
char				*the_rooms(t_rooms **head);
t_rooms				*new_room_alloc(int *cors,
		short is_s, short is_f, char *name);
void				push_list_r_back(t_rooms **head, t_rooms *to_push);
void				add_list_link(t_rooms *link, t_rooms **room);
int					links_num(t_rooms *r);
int					mark_the_way(t_rooms **room, int i);
t_rooms				**list_join_links(t_rooms ***old, int size, t_rooms *link);
t_rooms				*get_fin(t_rooms **head);
void				free_rooms(t_rooms **head);
void				free_arr(char ***arr);
t_rooms				*get_start(t_rooms **head);
int					ind_of_empty_r(t_rooms *r, int i);
int					lin_len(t_rooms **links);
int					is_room_spaces(char *line);
void				error_cont(char *info);
int					check_name(char *name, t_rooms *head);
void				room_commands(char *line, short *sf, t_rooms **head);
int					is_data_valid(char **data, int i);
void				find_end_mark(t_rooms **head);
int					valid_n_link(t_rooms *r1, t_rooms *r2);
void				new_room_init(t_rooms **new, int is_s, int is_f);
int					best_room(int *indxs, int len, t_rooms *r);

#endif

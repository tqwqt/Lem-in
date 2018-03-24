/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:06:58 by vhavryle          #+#    #+#             */
/*   Updated: 2018/03/14 14:07:01 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef struct		s_struct
{
	int 			ants;
	int 			fd;
	short			start;
	short			end;
}					t_farm;

typedef struct		s_list_r
{
	struct s_list_r	**links;
	struct s_list_r	*next;
	char			*name;
	short			is_full;
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

void			lets_go();
void			free_ants(t_ant ***ants);
t_ant			**get_ants(int n, t_rooms *start);
void			free_data(char	***data);
t_farm			*g_farm;
t_rooms			*g_rooms;
int				is_comment(char *line);
void			the_links(char *line);
int 			is_link(char *line);
t_rooms			*find_by_name(char	*name);
int				check_cors(int x, int y);
void			get_num_ants();
void			write_info(char *info);
void			error_exit(char *info);
int				room_validate(char *line, short s, short f);
void			the_rooms();
t_rooms			*new_room_alloc(int *cors, short is_s, short is_f, char *name);
void			push_list_r_back(t_rooms **head, t_rooms *to_push);
void			push_list_link(t_rooms **head, t_rooms *to_push);
void 			add_list_link(t_rooms *link, t_rooms **room);
int				links_num(t_rooms *r);
int mark_the_way(t_rooms **room);
t_rooms **list_join_links(t_rooms ***old, int size, t_rooms *link);
void			free_rooms(t_rooms **head);
void			free_arr(char ***arr);
int				is_s_in_links(t_rooms	**links);
t_rooms			*get_fin();
t_rooms			*get_start();
int				ind_of_empty_r(t_rooms *r);
int				lin_len(t_rooms **links);
int				is_room_spaces(char *line);
void			error_cont(char *info);
#endif

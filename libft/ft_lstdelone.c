/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:43:41 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/11 18:43:51 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;

	list = *alst;
	if (alst)
	{
		(*del)(list->content, list->content_size);
		free(*alst);
		*alst = NULL;
	}
}

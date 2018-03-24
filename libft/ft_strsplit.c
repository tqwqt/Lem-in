/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:45:52 by vhavryle          #+#    #+#             */
/*   Updated: 2017/11/09 16:45:54 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "libft.h"

static	int		ft_splt4_w(const char *s, char c)
{
	int			b;
	int			i;

	b = 0;
	i = -1;
	if (s)
		while (s[++i] != '\0')
			if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
				b++;
	return (b);
}

static	char	**split_this(const char *s, char c, char **arr, int w)
{
	int			i;
	int			z;
	int			p;

	i = 0;
	p = 0;
	z = -1;
	while (--w != -1 && s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] != c)
			i++;
		arr[++z] = ft_strsub(s, p, i - p);
		p = ++i;
//		i++;
	}
	arr[++z] = NULL;
	return (arr);
}

static	char	**ft_splt3(const char *s, char c, char **arr, int w)
{
	int			x;
	int			i;
	int			b;
	int			z;

	i = -1;
	b = ft_splt4_w(s, c);
	z = -1;
	while (b)
		if (s[++i] != c)
		{
			w = i - 1;
			x = -1;
			while (s[++w] != c && s[w])
				if (s[w] != c && (s[w + 1] == c || s[w + 1] == '\0'))
					if (b-- && ((arr[++z] = ft_strnew(w - i + 1)) != NULL))
					{
						while (i <= w && s[i])
							arr[z][++x] = s[i++];
						arr[z][++x] = '\0';
					}
		}
	arr[z + 1] = NULL;
	return (arr);
}


char			**ft_strsplit(const char *s, char c)
{
	char		**arr;
	int			b;

	b = ft_splt4_w(s, c);
	if (((arr = malloc(sizeof(char*) * (b + 1))) != 0) && s)
		arr = (char **) split_this(s, c, arr, b);//ft_splt3(s, c, arr, -1);
	return (arr);
}

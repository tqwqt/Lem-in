/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhavryle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:29:09 by vhavryle          #+#    #+#             */
/*   Updated: 2017/10/26 12:29:12 by vhavryle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	a = s1[i];
	b = s2[i];
	while (a == b)
	{
		i++;
		a = s1[i];
		b = s2[i];
		if (a == '\0' && b == '\0')
			return (0);
	}
	return (a - b);
}

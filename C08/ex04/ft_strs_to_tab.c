/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:02:23 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/28 10:41:03 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "ft_stock_str.h"

int	ft_strlen(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*src_cpy;
	int		i;

	i = 0;
	while (src[i])
		i++;
	src_cpy = NULL;
	src_cpy = malloc(sizeof(char) * i + 1);
	if (src_cpy == NULL || !src_cpy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		src_cpy[i] = src[i];
		i++;
	}
	src_cpy[i] = '\0';
	return (src_cpy);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s_tab;
	int			i;

	i = 0;
	s_tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (s_tab == NULL)
		return (NULL);
	while (i < ac)
	{
		s_tab[i].size = ft_strlen(av[i]);
		s_tab[i].str = av[i];
		s_tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	s_tab[i].str = 0;
	return (s_tab);
}

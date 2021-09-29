/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:09:48 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/16 19:21:24 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	diff;
	int	i;

	diff = max - min;
	i = -1;
	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(int) * (max - min));
	if (!tab)
		return (0);
	while (++i < diff)
		tab[i] = min++;
	return (tab);
}

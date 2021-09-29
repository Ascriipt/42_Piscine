/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:21:40 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/26 21:35:22 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	diff;
	int	i;

	i = -1;
	diff = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(int) * diff);
	if (!tab)
		return (-1);
	while (++i < diff)
		tab[i] = min++;
	*range = tab;
	return (diff);
}

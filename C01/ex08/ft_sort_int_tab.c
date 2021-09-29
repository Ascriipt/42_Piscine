/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:08:56 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/08 16:08:28 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	n;
	int	swop;

	i = -1;
	while (++i < size)
	{
		n = i;
		while (++n < size)
		{
			if (tab[i] > tab[n])
			{
				swop = tab[n];
				tab[n] = tab[i];
				tab[i] = swop;
			}
		}
	}
}

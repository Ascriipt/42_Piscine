/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 22:06:11 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/08 20:12:14 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	swop;

	i = -1;
	while (++i < size / 2)
	{
		swop = tab[size - i - 1];
		tab[size - i - 1] = tab[i];
		tab[i] = swop;
	}
}

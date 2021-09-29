/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:45:37 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/08 15:08:25 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int *tab, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_putchar(tab[i] + '0');
	if (tab[0] != 10 - n)
		write(1, ", ", 2);
}

void	ft_resolve(int *tab, int i, int n)
{
	if (i > 0)
		tab[i] = tab[i - 1] + 1;
	while (tab[i] < 10)
	{
		if (i < n - 1)
			ft_resolve(tab, i + 1, n);
		else
			ft_print(tab, n);
		tab[i]++;
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];
	int	bce;

	bce = -1;
	while (++bce != n)
		tab[bce] = 0;
	ft_resolve(tab, 0, n);
}

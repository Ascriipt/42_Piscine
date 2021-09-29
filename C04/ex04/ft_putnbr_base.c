/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:04:46 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/15 14:30:03 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int	ft_check_base(char *str, int ln)
{
	int	i;
	int	j;

	i = -1;
	if (ln < 2)
		return (0);
	while (++i < ln)
	{
		j = i + 1;
		while (j < ln)
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	return (1);
}

void	ft_print_base(int nbr, int len, char *str)
{
	long int	nb;

	nb = nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= len)
	{
		ft_print_base(nb / len, len, str);
		write(1, &str[nb % len], 1);
	}
	else
		write(1, &str[nb], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	if (ft_check_base(base, i) == 1)
		ft_print_base(nbr, i, base);
}

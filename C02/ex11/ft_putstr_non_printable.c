/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 10:35:42 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/20 12:04:06 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void	ft_print_hex(char c)
{
	char	*tab;

	tab = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &tab[c / 16], 1);
	write(1, &tab[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			ft_print_hex(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}

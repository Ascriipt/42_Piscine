/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:54:39 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/15 17:10:37 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void	ft_putstr(char *str)
{
	while (*str++)
		write(1, str - 1, 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc >= 0)
		ft_putstr(argv[0]);
	return (0);
}

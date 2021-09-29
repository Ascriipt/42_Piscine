/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:41:11 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/23 14:28:32 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int	g_board[10];
int	g_number;

void	ft_print_tab(void)
{
	int		i;
	char	dest[11];

	i = -1;
	while (++i < 10)
		dest[i] = g_board[i] + 48;
	dest[10] = '\0';
	i = -1;
	while (dest[++i])
		write(1, &dest[i], 1);
	write(1, "\n", 1);
	g_number++;
}

unsigned int	ft_diff(int Q_val, int Q_pos)
{
	return (g_board[Q_val] - g_board[Q_pos]);
}

int	ft_is_valid(int Q_val)
{
	int	i;

	i = -1;
	while (++i < Q_val)
		if (g_board[Q_val] == g_board[i]
			|| ft_diff(Q_val, i) == (unsigned int)(Q_val - i)
			|| ft_diff(Q_val, i) == (unsigned int)(i - Q_val))
			return (0);
	return (1);
}

void	ft_board_is_valid(int Q_pos)
{
	g_board[Q_pos] = -1;
	while (++g_board[Q_pos] < 10)
	{
		if (ft_is_valid(Q_pos))
		{
			if (Q_pos == 9)
				ft_print_tab();
			else
				ft_board_is_valid(Q_pos + 1);
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	ft_board_is_valid(0);
	return (g_number);
}

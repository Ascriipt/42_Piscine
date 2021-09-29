/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:01:35 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/15 14:30:16 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int	ft_ib(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str, int ln, char *rbase)
{
	int	sign;
	int	atoi;
	int	i;

	sign = 1;
	atoi = 0;
	while (*str == ' ' || *str == '\n'
		|| *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_ib(*str, rbase) != -1)
	{
		i = ft_ib(*str, rbase);
		atoi = atoi * ln + i;
		str++;
	}
	return (atoi * sign);
}

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
		if (str[i] == '-' || str[i] == '+'
			|| str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
			return (0);
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	if (ft_check_base(base, i))
		return (ft_atoi(str, i, base));
	return (0);
}

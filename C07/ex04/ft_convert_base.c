/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:20:06 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/28 10:23:39 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int		ft_sizeof(int n, int ln);
char	*ft_strrev(char *nbr, int n);

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

char	*ft_itoa_base(int nbr, int len, char *base, int ln)
{
	long int	nb;
	char		*dest;
	int			i;

	dest = malloc(255);
	if (nbr == -2147483648 && len == 32)
		len += 1;
	i = 0;
	nb = nbr;
	if (nb < 0)
	{
		dest[i++] = '-';
		nb = -nb;
	}
	while (i < len)
	{
		dest[i++] = base[nb % ln];
		nb /= ln;
	}
	dest[i] = '\0';
	ft_strrev(dest, len);
	return (dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*tab;
	int		ln;
	int		i;
	int		n;
	int		e;

	i = 0;
	ln = 0;
	while (base_from[i])
		i++;
	while (base_to[ln])
		ln++;
	if (!ft_check_base(base_from, i)
		|| !ft_check_base(base_to, ln))
		return (0);
	e = ft_atoi(nbr, i, base_from);
	n = ft_sizeof(e, ln);
	tab = malloc(sizeof(char) * 255);
	while (i < 255)
		tab[i++] = '\0';
	tab = ft_itoa_base(e, n, base_to, ln);
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:02:56 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/27 12:54:38 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sizeof(int n, int ln)
{
	if (n == -2147483648)
		n = -2147483647;
	if (n < 0)
	{
		n = -n;
		return (1 + ft_sizeof(n, ln));
	}
	if (n < ln)
		return (1);
	return (1 + ft_sizeof(n / ln, ln));
}

char	*ft_strrev(char *nbr, int n)
{
	int		i;
	int		j;
	char	swop;

	i = 0;
	j = n - 1;
	if (nbr[0] == '-')
		i++;
	while (i <= j)
	{
		swop = nbr[i];
		nbr[i] = nbr[j];
		nbr[j] = swop;
		i++;
		j--;
	}
	return (nbr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 12:49:18 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/25 22:22:06 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int	ft_ib(char x, char *charset)
{
	while (*charset)
	{
		if (x == *charset)
			return (0);
		charset++;
	}
	return (1);
}

int	ft_tablen(char *str, char *charset)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (ft_ib(str[i], charset) == 0)
		{
			len++;
			while (ft_ib(str[i], charset) == 0)
				i++;
		}
		i++;
	}
	return (len);
}

void	ft_strcpy(char *str, char *split, char *cpy_to)
{
	while (str < cpy_to)
		*(split++) = *(str++);
	*split = '\0';
}

int	ft_diff(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
			if (charset[j++] == str[i])
				return (i);
		i++;
	}
	return (i);
}

char **ft_split(char *str, char *charset)
{
	char	**split;
	char	*diff;
	int	tl;
	int	i;

	i = 0;
	diff = 0;
	tl = ft_tablen(str, charset);
	split = ((char **)malloc((sizeof(char *) * tl) + 1));
	while (*str)
	{
		if (ft_ib(*str, charset) == 0)
		{
			while (ft_ib(*str, charset) == 0)
				str++;
		}
		printf("str - diff %d\n", str - diff + 1);
		split[i] = malloc(str - diff + 1);
		ft_strcpy(str, split[i++], diff);
		str++;
	}
	split[i] = 0;
	return (split);
}

int	main(int ac, char **av)
{
	(void)ac;
	ft_split(av[1], av[2]);
	return (0);
}

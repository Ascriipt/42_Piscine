/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:20:27 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/26 11:47:34 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ib(char *charset, char c)
{
	while (*charset != 0)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_size(char *str, char *charset)
{
	int	size;

	size = 0;
	while (ft_ib(charset, *str) && *str)
		str++;
	while (*str)
	{
		size++;
		while (!ft_ib(charset, *str) && *str)
			str++;
		while (ft_ib(charset, *str) && *str)
			str++;
	}
	return (size);
}

char	*ft_strdup(char *str, char *charset)
{
	char	*cpy;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (str[size])
		size++;
	cpy = (char *)malloc((size + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (str[i] && !ft_ib(charset, str[i]))
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;

	split = (char **)malloc((ft_size(str, charset) + 1) * sizeof(char *));
	if (!split)
		return (0);
	i = 0;
	while (ft_ib(charset, str[i]))
		i++;
	j = 0;
	while (str[i])
	{
		split[j] = ft_strdup(&str[i], charset);
		if (!split[j])
			return (0);
		while (!ft_ib(charset, str[i]) && str[i])
			i++;
		while (ft_ib(charset, str[i]) && str[i])
			i++;
		j++;
	}
	split[ft_size(str, charset)] = 0;
	return (split);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:11:04 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/29 10:13:07 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_tl(int size, char **strs, char *sep)
{
	int	ln;
	int	i;

	i = 0;
	ln = 0;
	while (strs[i])
		ln += ft_strlen(strs[i++]);
	return (ft_strlen(sep) * (size - 1) + ln + 1);
}

char	ft_ult_cat(char *dest, char *src)
{
	int	i;
	int	n;

	n = 0;
	i = ft_strlen(dest);
	while (src[n])
	{
		dest[i + n] = src[n];
		n++;
	}
	dest[i + n] = '\0';
	return (*dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		tl;
	int		i;

	if (size == 0)
	{
		join = malloc(sizeof(char));
		*join = 0;
		return (join);
	}
	tl = ft_tl(size, strs, sep);
	join = malloc(sizeof(char) * tl);
	if (join == NULL)
		return (join);
	*join = 0;
	i = 0;
	while (i < size)
	{
		ft_ult_cat(join, strs[i]);
		if (i < size - 1)
			ft_ult_cat(join, sep);
		i++;
	}
	return (join);
}

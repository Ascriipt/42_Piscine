/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:51:55 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/27 18:49:53 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*src_cpy;
	int		i;

	i = 0;
	while (src[i])
		i++;
	src_cpy = NULL;
	src_cpy = malloc(sizeof(char) * i + 1);
	if (src_cpy == NULL || !src_cpy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		src_cpy[i] = src[i];
		i++;
	}
	src_cpy[i] = '\0';
	return (src_cpy);
}

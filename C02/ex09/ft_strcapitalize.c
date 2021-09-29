/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:11:03 by maparigi          #+#    #+#             */
/*   Updated: 2021/09/20 12:05:39 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	n;

	i = 0;
	ft_strlowcase(str);
	while (str[i])
		i++;
	while (*str)
	{
		n = 0;
		while ((*str >= 'a' && *str <= 'z')
			|| (*str >= 'A' && *str <= 'Z')
			|| (*str >= '0' && *str <= '9'))
		{
			if ((*str >= 'a' && *str <= 'z') && n == 0)
				*str -= 32;
			str++;
			n++;
		}
		str++;
	}
	return (str - i);
}

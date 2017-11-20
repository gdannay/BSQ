/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 19:46:35 by gdannay           #+#    #+#             */
/*   Updated: 2017/07/26 19:48:40 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_atoi(char *str)
{
	int				i;
	unsigned int	nombre;

	i = 0;
	nombre = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nombre = (nombre * 10) + (str[i] - '0');
		i++;
	}
	return (nombre);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strconcat(char *str1, int str1_len, char *str2, int str2_len)
{
	char	*str1str2;
	int		str1str2_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str1str2_len = str1_len + str2_len + 1;
	if ((str1str2 = (char *)malloc(sizeof(char) * str1str2_len)) == NULL)
		return (0);
	while (str1[i] != '\0')
	{
		str1str2[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		str1str2[i] = str2[j];
		i++;
		j++;
	}
	str1str2[i] = '\0';
	return (str1str2);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

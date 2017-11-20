/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 23:34:52 by gdannay           #+#    #+#             */
/*   Updated: 2017/07/26 21:38:38 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		check(char *s, int i)
{
	if (s[i] == '\n')
		return (0);
	if (s[i] == '\0')
		return (0);
	return (1);
}

int		remplissage(char *str, int ***tab, t_info_map **i_map, int *i)
{
	int j;
	int k;

	j = 0;
	while (j < (*i_map)->nb_lines && (k = 0) != 1)
	{
		if (((*tab)[j] = malloc(sizeof(int) * ((*i_map)->nb_col + 2))) == NULL)
			return (0);
		while (str[*i] != '\0' && str[*i] != '\n')
		{
			if (str[*i] == (*i_map)->obs)
				(*tab)[j][k++] = 0;
			else if (str[*i] == (*i_map)->vide)
				(*tab)[j][k++] = 1;
			else
				return (0);
			*i = *i + 1;
		}
		if (k != (*i_map)->nb_col)
			return (0);
		(*tab)[j++][k] = '\0';
		*i = *i + 1;
	}
	(*tab)[j] = 0;
	return (1);
}

int		taille_ligne(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (0);
	else
		return (i);
}

int		ft_split_whitespaces(char *s, t_info_map **info_map, int ***tab)
{
	int i;

	i = 0;
	if (((*tab) = malloc(sizeof(int*) * ((*info_map)->nb_lines + 1))) == NULL)
		return (0);
	if (!((*info_map)->nb_col = taille_ligne(s)))
		return (0);
	if (!remplissage(s, tab, info_map, &i))
		return (0);
	if (s[i] != '\0')
		return (0);
	return (1);
}

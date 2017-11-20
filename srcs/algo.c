/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_fuck_yourself.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 03:18:11 by gdannay           #+#    #+#             */
/*   Updated: 2017/07/26 23:20:58 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	pars_first_line(t_info_map *info_map, t_val_max **val_max, int **tab)
{
	int i;

	i = 0;
	if (info_map->nb_col == 1)
	{
		while (i < info_map->nb_lines && tab[i][0] != 1)
			i++;
		if (i != info_map->nb_lines && tab[i][0] == 1)
		{
			(*val_max)->valeur = tab[i][0];
			(*val_max)->line = i;
			(*val_max)->col = 0;
		}
	}
	else
	{
		while (i < info_map->nb_col && tab[0][i] != 1)
			i++;
		if (i != info_map->nb_col && tab[0][i] == 1)
		{
			(*val_max)->valeur = tab[0][i];
			(*val_max)->line = 0;
			(*val_max)->col = i;
		}
	}
}

void	demin(int i, int j, int *valeur_act, int ***tab)
{
	*valeur_act = (*tab)[i - 1][j - 1];
	if ((*tab)[i - 1][j] < *valeur_act)
		*valeur_act = (*tab)[i - 1][j];
	if ((*tab)[i][j - 1] < *valeur_act)
		*valeur_act = (*tab)[i][j - 1];
	(*tab)[i][j] = *valeur_act + 1;
}

int		**algo(int **tab, t_info_map *info_map, t_val_max **val_max)
{
	int i;
	int j;
	int valeur_act;

	if (((*val_max) = malloc(sizeof(t_val_max))) == NULL)
		return (NULL);
	pars_first_line(info_map, val_max, tab);
	i = 0;
	while (++i < info_map->nb_lines)
	{
		j = 0;
		while (++j < info_map->nb_col)
		{
			while (tab[i][j] == 0 && j < info_map->nb_col)
				j++;
			demin(i, j, &valeur_act, &tab);
			if (tab[i][j] > (*val_max)->valeur)
			{
				(*val_max)->line = i;
				(*val_max)->col = j;
				(*val_max)->valeur = tab[i][j];
			}
		}
	}
	return (tab);
}

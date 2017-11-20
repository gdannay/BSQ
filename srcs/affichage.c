/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 05:04:33 by gdannay           #+#    #+#             */
/*   Updated: 2017/07/26 19:44:34 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	affichage(int **tab, t_info_map *info_map, t_val_max *val_max)
{
	int i;
	int j;

	i = 0;
	while (i < info_map->nb_lines)
	{
		j = 0;
		while (j < info_map->nb_col)
		{
			if (i > val_max->line - val_max->valeur && i <= val_max->line
					&& j > val_max->col - val_max->valeur && j <= val_max->col)
				ft_putchar(info_map->plein);
			else if (tab[i][j] == 0)
				ft_putchar(info_map->obs);
			else
				ft_putchar(info_map->vide);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

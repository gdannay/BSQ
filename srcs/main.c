/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 19:47:39 by gdannay           #+#    #+#             */
/*   Updated: 2017/07/26 22:36:28 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int argc, char **argv)
{
	t_info_map	*info_map;
	char		*str_map;
	int			**tab_split;
	t_val_max	*val_max;
	int			i;

	if (argc > 1)
		i = 1;
	else
		i = 0;
	while (i < argc)
	{
		if ((str_map = get_map(argc, argv[i], &info_map)) != 0 &&
					ft_split_whitespaces(str_map, &info_map, &tab_split) != 0 &&
					(tab_split = algo(tab_split, info_map, &val_max)) != NULL)
		{
			affichage(tab_split, info_map, val_max);
		}
		else
			ft_putstr("map error\n");
		if (argc > 2 && i < argc - 1)
			ft_putchar('\n');
		i++;
	}
	return (0);
}

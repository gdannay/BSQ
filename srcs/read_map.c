/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atastet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 22:18:31 by atastet           #+#    #+#             */
/*   Updated: 2017/07/26 22:19:00 by atastet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*get_map_infos(char *str_map, t_info_map **info_map)
{
	int	i;

	i = 0;
	if ((*info_map = malloc(sizeof(t_info_map))) == NULL)
		return (NULL);
	if (str_map[i] < '0' || str_map[i] > '9')
		return (NULL);
	while (str_map[i + 3] != '\0' && str_map[i + 3] != '\n')
		i++;
	(*info_map)->vide = str_map[i];
	(*info_map)->obs = str_map[i + 1];
	(*info_map)->plein = str_map[i + 2];
	str_map[i] = '\0';
	if ((*info_map)->vide == ((*info_map)->plein))
		return (NULL);
	if ((*info_map)->vide == ((*info_map)->obs))
		return (NULL);
	if ((*info_map)->obs == ((*info_map)->plein))
		return (NULL);
	(*info_map)->nb_lines = ft_atoi(str_map);
	return (str_map + i + 4);
}

int		check_argv(int argc, char *argv)
{
	int fd;

	if (argc == 1)
		return (0);
	else
	{
		if ((fd = open(argv, O_RDONLY)) < 0)
			return (-1);
		else
			return (fd);
	}
}

char	*read_on_stdin(int argc, char *argv, char *str_map)
{
	char	buff[BUFF_SIZE];
	int		buff_len;
	int		str_map_len;
	int		fd;
	char	*temp;

	if ((fd = check_argv(argc, argv)) == -1)
		return (NULL);
	str_map_len = 0;
	while ((buff_len = read(fd, buff, BUFF_SIZE - 1)) > 0)
	{
		buff[buff_len] = '\0';
		temp = str_map;
		str_map = ft_strconcat(str_map, str_map_len, buff, buff_len);
		free(temp);
		str_map_len += buff_len;
	}
	close(fd);
	return (str_map);
}

char	*get_map(int argc, char *argv, t_info_map **info_map)
{
	char	*str_map;

	str_map = NULL;
	if ((str_map = malloc(sizeof(str_map))) == NULL)
		return (NULL);
	*str_map = '\0';
	if ((str_map = read_on_stdin(argc, argv, str_map)) == NULL)
		return (NULL);
	str_map = get_map_infos(str_map, info_map);
	return (str_map);
}

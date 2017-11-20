/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 22:13:39 by gdannay           #+#    #+#             */
/*   Updated: 2017/07/26 21:38:13 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 100000

typedef struct	s_info_map
{
	char		vide;
	char		plein;
	char		obs;
	int			nb_lines;
	int			nb_col;
}				t_info_map;

typedef struct	s_val_max
{
	int			valeur;
	int			line;
	int			col;
}				t_val_max;

char			*get_map_infos(char *str, t_info_map **info_map);
char			*get_map(int argc, char *argv, t_info_map **info_map);
void			ft_putstr(char *str);
int				ft_atoi(char *str);
char			*ft_strconcat(char *str1, int str1_len,
				char *str2, int str2_len);
int				ft_strlen(char *str);
int				check(char *s, int i);
int				taille_chaine(char *str);
void			remplisssage(char *str, int **tab,
				t_info_map **info_map, int *i);
int				ft_split_whitespaces(char *s,
				t_info_map **info_map, int ***tab_split);
void			ft_print_words_tables(int **tab, t_info_map *info_map);
void			ft_putchar(char c);
int				**algo(int **tab, t_info_map *info_map, t_val_max **max);
void			affichage(int **tab, t_info_map *info_map, t_val_max *val_max);
void			pars_first_line(t_info_map *info_map,
				t_val_max **val_max, int **tab);
void			demin(int i, int j, int *valeur_act, int ***tab);

#endif

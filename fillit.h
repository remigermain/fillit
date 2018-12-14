/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 16:50:01 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 12:34:46 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_map	t_map;

struct	s_map
{
	char			map[4][4];
	char			letter;
	int				nb_tet;
	struct s_map	*next;
};

/*
** main fonctions
*/
int		main_manager(char *files);
char	*read_files(int fd, char *str);

/*
** tetris map check_files
*/
int		ft_checkfiles(char *str, int a, int b, int c);
int		ft_check_allbloc(char *str);
int		ft_check_bloc(char **tab, int i_c, int i_l);
int		ft_check_tetri(char **tab, int i_c, int i_l);

/*
** tetris map list : init && create
*/
int		lst_create(t_map **list_map, char *str_map);
char	add_digit(char c, t_map *lst);

/*
** resolve
*/

void	resolve_manager(t_map **lst);
int		resolve(t_map **lst, char ***map, int size);
int		place_test(char tet[4][4], char **map, int i, int j);
int		place_tetri(char tet[4][4], char **map, int i, int j);

/*
** utils
*/
void	copy_tab(char **src, char ***dest2, int size);
int		check_finalmap(char **map, int nb);
int		initposition_a(char tet[4][4]);
int		initposition_b(char tet[4][4]);
int		ft_sqrt2(int nb);

#endif

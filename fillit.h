/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 16:50:01 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 17:33:53 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/includes/libft.h"
# include <stdio.h>
# include "color.h"

typedef struct s_pos	t_pos;

struct	s_pos
{
	int				pos[4][2];
	char			letter;
	struct s_pos	*next;
};

typedef struct s_map	t_map;

struct	s_map
{
	int				map[4][4];
	char			letter;
	int				type;
	int				nb_tet;
	struct s_map	*next;
};

typedef struct s_algo	t_algo;

struct	s_algo
{
	int				tmax;
	int				cmax;
	int				lmax;
	int				c_pos;
};

/*
** main fonctions
*/
int		main_manager(char *files);
char	*read_files(int fd, char *str);

/*
** check_files
*/
int		ft_checkfiles(char *str, int a, int b, int c);
int		ft_check_allbloc(char *str);
int		ft_check_bloc(char **tab, int i_c, int i_l);
int		ft_check_tetri(char **tab, int i_c, int i_l);

/*
** init list && create list
*/
int		lst_create(t_map **list_map, char *str_map);
int		lst_populate(t_map **list_map, char *str_map, int i_c, int i_l);
int		add_digit(char c);

/*
** init tab && add posibility
*/
int		tab_init_manager(t_map **list_map);
void	tab_init_tet(t_map **list_map, int **tab, int map);
int		**add_posibility(t_map *lst_tmp, int **tab, int map, int i);
int		square_tet(t_map *lst_tmp, int a, int b, int index);
int		**copy_line(t_map *lst_tmp, int **tab, int map, int i);

/*
** algorithme
*/
int		algo_solve(t_map **lst_map, int **t_option, int cmax, int lmax);
int		algo_solve_step(int **t_option, int tmax, int cmax, int lmax);
int		**find_select(int **t_solved, t_algo *algos);
t_algo	*algo_v_init(int tmax_val, int cmax_val, int lmax_val, int c_pos_val);
int		**algo_t_init(int **t_option, int cmax, int lmax);
int		find_min(int vala, int valb);
int		find_c_pos(int **t_solve, t_algo *algos);
//int		find_c_one(int **t_solved, t_algo *algos, int c_one);
int		find_l_one(int **t_solved, t_algo *algos, int l_one);
int		**remove_col(int **t_solved, t_algo *algos, int c_one);
int		**remove_line(int **t_solved, t_algo *algos, int l_one);
int		**remove_cl_(int **t_solved, t_algo *algos, int l_one);

/*
** utils
*/
int		lst_print_tab(t_map **list_map);
int		check_type(int map[4][4], int i, int j);
int		calcule_posibility(t_map **list_map, int map);
int		calcule_posibility_one(int type, int map);
int		**ft_create_ntab2(int lin, int col, int nb);
void	ft_print_ntab(int **tab, int lin, int col);
void	ft_print_ntab2(int **tab, int lin, int col);
int		index_base(int *tab, int map, int nb_tet, int base);

#endif

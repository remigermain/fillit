/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 16:50:01 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 11:55:53 by rgermain    ###    #+. /#+    ###.fr     */
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
	int				t_num;
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
int		tab_manager(t_map **list_map);
int		**tab_init_manager(t_map **list_map, int map, int lmax);
void	tab_init_tet(t_map **list_map, int **tab, int map);
int		**add_posibility(t_map *lst_tmp, int **tab, int map, int i);

/*
** tab utils
*/
int		**copy_line(t_map *lst_tmp, int **tab, int map, int i);
int		square_tet(t_map *lst_tmp, int a, int b, int index);
int		tab_def_map(t_map *lst_tmp);

/*
** algorithme
*/
int		algo_solve(t_map **lst_map, int **i_option, int cmax, int lmax);
t_algo	*algo_v_init(int tmax_v, int cmax_v, int lmax_v, int t_num_v);
int		**algo_t_init(int **i_option, int cmax, int lmax);
//t_pos	*sol_init(int t_num, t_pos **t_solpos);
t_pos	*sol_init(t_pos **t_solpos);

t_pos	*find_select(int **i_solve, t_algo *algos);
int		find_c_pos(int **i_solve, t_algo *algos);
int		find_l_one(int **i_solve, t_algo *algos, int l_one);
t_pos	*find_sol(t_pos **t_solpos, int **i_solve, t_algo *algos, int l_o);

int		**remove_col(int **i_solve, t_algo *algos, int c_one);
int		**remove_line(int **i_solve, t_algo *algos, int l_one);
int		**remove_cl(int **i_solve, t_algo *algos, int l_one);

int		col_min(int vala, int valb);
int		col_sum(int **i_solve, t_algo *algos, int i_c);
//t_pos	*tpos_new(char letter);
t_pos	*tpos_new(void);
void	tpos_add(t_pos **alst, t_pos *blst);

/*
** tab validation
*/
int		lig_sum(int **t_solved, t_algo *algos, int i_l);
int		isolve_check(int **t_option, t_algo *algos);

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
int		printlst_final(t_pos *lst, int map);
int		ft_printabn(char **tab);

#endif

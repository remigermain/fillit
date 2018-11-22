/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab_manager.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 17:48:57 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 11:56:08 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		**add_possibility(t_map *lst_tmp, int **tab, int map, int i)
{
	int j;
	int a;
	int b;
	int tmpb;
	int ij;

	j = lst_tmp->nb_tet;
	a = square_tet(lst_tmp, 0, 0, 1);
	tmpb = square_tet(lst_tmp, a, 0, 0);
	while (j < ((map * map) + lst_tmp->nb_tet) && a < 4)
	{
		b = tmpb;
		ij = 0;
		while (b < 4)
			tab[i][j + ij++] = lst_tmp->map[a][b++];
		a = square_tet(lst_tmp, a + 1, 0, 1);
		j += map;
	}
	tab = copy_line(lst_tmp, tab, map, i);
	return (tab);
}

void	tab_init_tet(t_map **list_map, int **tab, int map)
{
	t_map	*lst_tmp;
	int		i;

	lst_tmp = *list_map;
	i = 0;
	while (lst_tmp != NULL)
	{
		tab[i][lst_tmp->letter - 'A'] = 1;
		tab = add_possibility(lst_tmp, tab, map, i);
		i += calcule_posibility_one(lst_tmp->type, map);
		lst_tmp = lst_tmp->next;
	}
}

int		**tab_init_manager(t_map **list_map, int map, int lmax)
{
	t_map	*lst_tmp;
	int		**tab;

	lst_tmp = *list_map;
	tab = ft_create_ntab2(lmax, (lst_tmp->nb_tet + (map * map)), 0);
	tab_init_tet(list_map, tab, map);
	ft_print_ntab2(tab, lmax, (lst_tmp->nb_tet + (map * map)));
	return (tab);
}

int		tab_manager(t_map **list_map)
{
	int		map;
	int		lmax;
	int		**tab;
	t_map	*lst_tmp;
	int		algo_map;

	algo_map = 0;
	lst_tmp = *list_map;
	map = tab_def_map(lst_tmp);
	while (algo_map == 0)
	{
		lmax = calcule_posibility(list_map, map);
		tab = tab_init_manager(list_map, map, lmax);
		if (algo_solve(&lst_tmp, tab, (lst_tmp->nb_tet + (map * map)), lmax) == -1)
		{
printf("\n%s\n\n", "!!!!! NO SOLUTION found --> increase map size !!!!!");
			map = map + 1;
			algo_map = 0;
		}
		else
			algo_map = 1;
	}
	return (1);
}

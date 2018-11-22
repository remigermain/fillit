/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab_utils.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 12:23:41 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 11:56:49 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "fillit.h"

int		**copy_line(t_map *lst_tmp, int **tab, int map, int i)
{
	int		j;
	int		tmpi;
	int		base;
	int		pos_max;

	pos_max = (calcule_posibility_one(lst_tmp->type, map) - 1);
	base = 0;
	tmpi = i;
	while (pos_max--)
	{
		base = index_base(tab[i], map, lst_tmp->nb_tet, base);
		j = (lst_tmp->nb_tet);
		tab[i + 1][lst_tmp->letter - 'A'] = 1;
		while ((j + base) < ((map * map) + lst_tmp->nb_tet))
		{
			tab[i + 1][j + base] = tab[tmpi][j];
			j++;
		}
		i++;
	}
	return (tab);
}


int		square_tet(t_map *lst_tmp, int a, int b, int index)
{
	if (index == 1)
	{
		while (lst_tmp->map[a][b] != 1 && a < 4)
		{
			while (lst_tmp->map[a][b] != 1 && b < 4)
				b++;
			if (b != 4)
				return (a);
			a++;
			b = 0;
		}
		return (a);
	}
	while (lst_tmp->map[a][b] != 1 && b < 4)
	{
		while (lst_tmp->map[a][b] != 1 && a < 4)
			a++;
		if (a != 4)
			return (b);
		b++;
		a = 0;
	}
	return (b);
}

int		tab_def_map(t_map *lst_t)
{
	t_map	*lst_tmp;
	int 	tmp;

	lst_tmp = lst_t;
	tmp = 0;
	while (lst_tmp != NULL)
	{
		if (lst_tmp->type == 1 && tmp <= 3)
			tmp = 3;
		if (lst_tmp->type == 2 && tmp <= 2)
			tmp = 2;
		if (lst_tmp->type == 3 && tmp <= 4)
			tmp = 4;
		lst_tmp = lst_tmp->next;
	}
	return (tmp);
}

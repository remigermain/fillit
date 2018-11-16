/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab_init_manager.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 17:48:57 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 16:56:51 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		**copy_line(t_map *lst_tmp, int **tab, int map, int i)
{
	int	j;
	int	tmpi;
	int	base;
	int	pos_max;

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

int		tab_init_manager(t_map **list_map)
{
	t_map	*lst_tmp;
	int		**tab;
	int		map;
	int		nb;

	lst_tmp = *list_map;
	if (lst_tmp->nb_tet < 4)
		map = 3 + lst_tmp->nb_tet;
	else
		map = 2 + lst_tmp->nb_tet;
	lst_tmp = *list_map;
	nb = calcule_posibility(list_map, map);
	tab = ft_create_ntab2(nb, (lst_tmp->nb_tet + (map * map)), 0);
	tab_init_tet(list_map, tab, map);
	ft_print_ntab2(tab, nb, (lst_tmp->nb_tet + (map * map)));

	ft_putchar('\n');
	if (algo_solve(&lst_tmp, tab, nb, (lst_tmp->nb_tet +(map * map))) == -1)
		return (-1);
	return (1);
}

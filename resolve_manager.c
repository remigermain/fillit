/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve_manager.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 16:11:42 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:18:31 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		place_tetri(char tet[4][4], char **map, int i, int j)
{
	int a;
	int b;
	int f;
	int g;

	a = 0;
	f = initposition_a(tet);
	g = initposition_b(tet);
	while ((a + f) < 4 && map[i + a] != NULL)
	{
		b = 0;
		while ((b + g) < 4 && map[i + a][j + b] != '\0')
		{
			if (map[i + a][j + b] == '.' && tet[f + a][b + g] != '.')
				map[i + a][j + b] = tet[f + a][b + g];
			b++;
		}
		a++;
	}
	return (1);
}

int		place_test(char tet[4][4], char **map, int i, int j)
{
	int a;
	int b;
	int f;
	int g;
	int c;

	a = 0;
	f = initposition_a(tet);
	g = initposition_b(tet);
	c = 0;
	while ((a + f) < 4 && map[i + a] != NULL)
	{
		b = 0;
		while ((b + g) < 4 && map[i + a][j + b] != '\0')
		{
			if (map[i + a][j + b] == '.' && tet[f + a][b + g] != '.')
				c++;
			b++;
		}
		a++;
	}
	if (c == 4)
		return (1);
	return (0);
}

int		resolvefinal(char ***map2, char **map)
{
	ft_memdeltab((*map2));
	*map2 = map;
	return (1);
}

int		resolve(t_map **lst, char ***map2, int size)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	while ((*map2)[i] != NULL)
	{
		j = 0;
		while ((*map2)[i][j] != '\0')
		{
			if (place_test((*lst)->map, (*map2), i, j) == 1)
			{
				copy_tab((*map2), &map, size);
				place_tetri((*lst)->map, map, i, j);
				if ((*lst)->next == NULL || resolve(&(*lst)->next, &map, size))
					return (resolvefinal(map2, map));
				ft_memdeltab(map);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	resolve_manager(t_map **lst_base)
{
	char	**map;
	int		size;
	int		index;
	int		nb_tet;

	index = 0;
	nb_tet = (*lst_base)->nb_tet;
	size = ft_sqrt2(nb_tet * 4);
	while (index == 0)
	{
		map = ft_createtab(size, '.');
		resolve(lst_base, &map, size);
		index = check_finalmap(map, nb_tet);
		size++;
		if (index == 0)
			ft_memdeltab(map);
	}
	ft_printtab(map);
	ft_memdeltab(map);
}

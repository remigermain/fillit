/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 23:05:33 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:16:57 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		initposition_a(char tet[4][4])
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (tet[a][b] == '.' && a < 4)
	{
		b++;
		if (b == 4)
		{
			b = 0;
			a++;
		}
	}
	return (a);
}

int		initposition_b(char tet[4][4])
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (tet[a][b] == '.' && b < 4)
	{
		a++;
		if (a == 4)
		{
			a = 0;
			b++;
		}
	}
	return (b);
}

void	copy_tab(char **src, char ***dest2, int size)
{
	char	**dest;
	int		a;
	int		b;

	if (!(dest = malloc(sizeof(char*) * size + 1)))
		return ;
	a = 0;
	while (src[a] != NULL)
	{
		b = 0;
		if (!(dest[a] = malloc(sizeof(char) * size + 1)))
			return ;
		while (src[a][b] != '\0')
		{
			dest[a][b] = src[a][b];
			b++;
		}
		dest[a][b] = '\0';
		a++;
	}
	dest[a] = NULL;
	*dest2 = dest;
}

int		ft_sqrt2(int nb)
{
	int i;

	i = 1;
	while ((i * i) < nb)
		i++;
	return (i);
}

int		check_finalmap(char **map, int nb_tet)
{
	int a;
	int b;
	int tet;

	a = 0;
	b = 0;
	tet = 0;
	while (map[a] != NULL)
	{
		b = 0;
		while (map[a][b] != '\0')
		{
			if (map[a][b] != '.')
				tet++;
			b++;
		}
		a++;
	}
	if ((tet / nb_tet) == 4)
		return (1);
	return (0);
}

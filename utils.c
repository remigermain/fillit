/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 16:00:06 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 17:37:37 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** print la list_chainees
*/

int		lst_print_tab(t_map **list_map)
{
	t_map *list_temp;
	int i;
	int j;
	int a;

	i = 0;
	j = 0;
	a = 0;
	list_temp = *list_map;
	while (list_temp != NULL)
	{
		while (i != 4)
		{
			while (j != 4)
			{
				ft_putchar(' ');
				ft_putchar(list_temp->map[i][j++] + '0');
			}
			j = 0;
			i++;
			ft_putchar('\n');
		}
		a++;
		ft_putstr("letter = ");
		ft_putchar(list_temp->letter);
		ft_putchar('\n');
		ft_putstr("type = ");
		ft_putnbr(list_temp->type);
		ft_putchar('\n');
		if (list_temp->next != NULL)
			ft_putchar('\n');
		list_temp = list_temp->next;
		i = 0;
	}
//	ft_putstr("\n nombre de posibility = ");
//	if (a < 4)
//		ft_putnbr(calcule_posibility(list_map, 4 + a));
//	else
//		ft_putnbr(calcule_posibility(list_map,(12)));
//	ft_putchar('\n');
	return (1);
}

/*
**   trouve de quel type est le tetriminos
**   1 == les autes
**   2 == un care en 4x4
**   3 == une longeur de 4x1 ou 1x4
*/


int		check_type_line(int map[4][4], int i, int j, int count2)
{
	int count;

	count = 0;
	while (i != 4) 
	{
		if (map[i][j] == 1)
			count++;
		j++;
		if (j == 4)
		{
			if (((count2 == 0 || ((count < count2) && count != 0)) && 
						count2 != 4) || count == 4)
				count2 = count;
			i++;
			j = 0;
			count = 0;
		}
	}
	return (count2);
}


int		check_type_col(int map[4][4], int i, int j, int count2)
{
	int count;

	count = 0;
	while (j != 4) 
	{
		if (map[i][j] == 1)
			count++;
		i++;
		if (i == 4)
		{
			if (((count2 == 0 || ((count < count2) && count != 0)) && 
						count2 != 4) || count == 4)
				count2 = count;
			j++;
			i = 0;
			count = 0;
		}
	}
	return (count2);
}
	

int		check_type(int map[4][4], int i, int j)
{
	int count2;

	count2 = check_type_col(map, i, j, 0);
	count2 = check_type_line(map, i, j, count2);
	if (count2 == 1)
		return (1);
	if (count2 == 2)
		return (2);
	return (3);
}


/*
** calcule le nb de posibiliter des tetriminos par rapport a la taille de la maps
*/

int		calcule_posibility(t_map **list_map, int map)
{
	t_map	*lst_temp;
	unsigned int 	count;

	lst_temp = *list_map;
	count = 0;
	while (lst_temp != NULL)
	{
		if (lst_temp->type == 1)
			count += ((map - 1) * ( map - 2));
		else if (lst_temp->type == 2)
			count += ((map - 1) * ( map - 1));
		else if (lst_temp->type == 3)
			count += (map * (map - 3));
		lst_temp = lst_temp->next;
	
	}
	return (count);
}

/*
** pareille mais pour un seul type a la fois
*/

int		calcule_posibility_one(int type, int map)
{
	int count;

	count = 0;
	if (type == 1)
		count += ((map - 1) * ( map - 2));
	else if (type == 2)
		count += ((map - 1) * ( map - 1));
	else if (type == 3)
		count += (map * (map - 3));
	return (count);
}




/*
** cree tab de n colone et de n ligne  , initialiter de 0
*/

int	**ft_create_ntab2(int lin, int col, int nb)
{
	int	i;
	int j;
	int	**tab;

	i = 0;
	tab = (int **)malloc(sizeof(int *) * lin);
	while (i < lin)
	{
		j = 0;
		tab[i] = (int *)malloc(sizeof(int) * col);
		while (j < col)
			tab[i][j++] = nb;
		i++;
	}
	return (tab);
}
/*
**  le vrais printtab
*/

void	ft_print_ntab(int **tab, int lin, int col)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < lin)
	{
		j = 0;
		while (j < col)
			ft_putnbr(tab[i][j++]);
		ft_putchar('\n');
		i++;
	}
}


/*
**  print  tab int avec col et ligne  et affichage debug
*/
void	ft_print_ntab2(int **tab, int lin, int col)
{
	int i;
	int j;

	i = 0;
	j = col;
	ft_putstr("     ");
	while (j--)
	{
		if (i < 10)
			ft_putstr("| 0");
		else
			ft_putstr("| ");
		ft_putnbr(i);
		ft_putstr("");
		i++;
	}
	ft_putstr("|\n");
	i = 0;
	j = 0;
	while (i < lin)
	{
		j = 0;
		if (i < 10)
			ft_putstr("[0");
		else
			ft_putstr("[");
		ft_putnbr(i);
		ft_putstr("]");
		while (j < col)
		{
			ft_putstr(" | ");
			if ((tab[i][j] + '0') != 47)
//				ft_putchar(tab[i][j++] + '0');
				ft_putchar(tab[i][j] + '0');
			else
				ft_putchar(' ');
			j++;
		}
		ft_putstr(" |\n");
		i++;
	}
}

/*
**   uniquement pour le copy_line ( pas asser de place );
*/

int		index_base(int *tab, int map, int nb_tet, int base)
{
	int j;

	j = 0;
	j = (nb_tet);
	j += (map - 1);
	while (tab[j] == 0 && j < ((map * map) + nb_tet))
		j += map;
	if (tab[j] == 1)
			return (j - nb_tet + 1);
	else
		base++;
	return (base);
}




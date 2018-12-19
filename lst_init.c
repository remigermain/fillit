/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_init.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 15:57:16 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:17:41 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_freelist(t_map *lst)
{
	if (lst != NULL)
	{
		ft_freelist(lst->next);
		free(lst);
	}
}

char	add_digit(char c, t_map *l_tmp)
{
	if (c == '.')
		return ('.');
	return (l_tmp->letter);
}

int		lst_populate(t_map **list_map, char *str_map, int i_c, int i_l)
{
	int		i;
	t_map	*l_tmp;

	l_tmp = *list_map;
	i = 0;
	while (str_map[i] != '\0')
	{
		while (i_l != 4)
			l_tmp->map[i_c][i_l++] = add_digit(str_map[i++], l_tmp);
		i_c++;
		i_l = 0;
		if (str_map[i] == '\n' && str_map[i + 1] == '\n')
		{
			i++;
			l_tmp = l_tmp->next;
			i_c = 0;
		}
		i++;
	}
	free(str_map);
	return (1);
}

int		lst_create(t_map **list_map, char *str_map)
{
	int		i;
	int		nb_tet;
	t_map	*l_tmp;
	int		nb_temp;
	char	c;

	i = 0;
	nb_tet = 1;
	while (str_map[i++] != '\0')
		if (str_map[i] == '\n' && str_map[i + 1] == '\n')
			nb_tet++;
	nb_temp = nb_tet;
	c = 'A' + (nb_temp - 1);
	while (nb_tet--)
	{
		if (!(l_tmp = (t_map*)malloc(sizeof(t_map))))
			return (-1);
		l_tmp->nb_tet = nb_temp;
		l_tmp->letter = c--;
		l_tmp->next = *list_map;
		*list_map = l_tmp;
	}
	return (lst_populate(list_map, str_map, 0, 0));
}

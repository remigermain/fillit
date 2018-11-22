/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_u_remove.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 10:07:07 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		**remove_col(int **i_solved, t_algo *algos, int c_one)
{
	int		i_l;

printf("col(%d)\n", c_one);
	i_l = 0;
	while (i_l < algos->lmax)
	{
			i_solved[i_l][c_one] = -1;
		i_l = i_l + 1;
	}
	return (i_solved);
}

int		**remove_line(int **i_solved, t_algo *algos, int l_one)
{
	int		i_c;

printf("lig(%d), ", l_one);
	i_c = 0;
	while (i_c <= algos->cmax)
	{
			i_solved[l_one][i_c] = -1;
		i_c = i_c + 1;
	}
	return (i_solved);
}

int		**remove_cl(int **i_solved, t_algo *algos, int l_one)
{
	int		i_c;
	int		i_l;

	i_c = 0;
	while (i_c < algos->cmax)
	{
		if (i_solved[l_one][i_c] == 1)
		{
if (i_c < 10)
	printf("col[0%d] : ", i_c);
else
	printf("col[%d] : ", i_c);
			i_l = 0;
			while (i_l < algos->lmax)
			{
				if ((i_solved[i_l][i_c] == 1) && (i_l != l_one))
					i_solved = remove_line(i_solved, algos, i_l);
				i_l = i_l + 1;
			}
			if (i_c != algos->c_pos)
				i_solved = remove_col(i_solved, algos, i_c);
		}
		i_c = i_c + 1;
	}
	return (i_solved);
}

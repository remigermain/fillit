/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_u_remove.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 18:03:48 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		**remove_col(int **t_solved, t_algo *algos, int c_one)
{
	int		i_l;

printf("%s ", "- remove col  ");
printf("(%d)\n", c_one);
//printf("c_pos : %d | ", algos->c_pos);
//printf("l_pos : %d | ", algos->l_pos);
//printf("c_one : %d\n", c_one);
	i_l = 0;
	while (i_l < algos->lmax - 1)
	{
//printf("l[%d] | ", i_l);
//		if (i_l != algos->l_pos)
			t_solved[i_l][c_one] = -1;
//			t_solved[i_l][algos->c_pos] = -1;
		i_l = i_l + 1;
	}
//	i_l = c_one;
	return (t_solved);
}

int		**remove_line(int **t_solved, t_algo *algos, int l_one)
{
	int		i_c;

printf("%s ", "- remove line ");
printf("(%d)\n", l_one);
//printf("c_pos : %d | ", algos->c_pos);
//printf("l_pos : %d | ", algos->l_pos);
//printf("l_one : %d\n", l_one);
	i_c = 0;
	while (i_c <= algos->cmax)
	{
//printf("c[%d] | ", i_c);
//		if (i_c != algos->c_pos)
			t_solved[l_one][i_c] = -1;
//			t_solved[algos->l_pos][i_c] = -1;
		i_c = i_c + 1;
	}
//	i_c = l_one;
	return (t_solved);
}

int		**remove_cl_(int **t_solved, t_algo *algos, int l_one)
{
	int		i_l;
	int		i_c;

	i_c = 0;
//	i_c = algos->tmax;
	while (i_c < algos->cmax)
	{
printf("i_c[%d],", i_c);
printf(" ts[%d]", t_solved[l_one][i_c]);
		if (t_solved[l_one][i_c] == 1)
		{
printf(" | col[%d]\n", i_c);
			i_l = 0;
//			i_l = l_one;
			while (i_l < algos->lmax - 1)
			{
//printf("lig[%d]\n", i_l);
				if ((t_solved[i_l][i_c] == 1) && (i_l != l_one))
					t_solved = remove_line(t_solved, algos, i_l);
				i_l = i_l + 1;
			}
			if (i_c != algos->c_pos)
				t_solved= remove_col(t_solved, algos, i_c);
		}
printf("%s", "\n");
		i_c = i_c + 1;
	}
	return (t_solved);
}

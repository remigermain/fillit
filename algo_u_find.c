/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_u_find.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 12:28:09 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		find_c_pos(int **i_solved, t_algo *algos)
{
	int		i_c;
	int		c_sum;
	int		c_min;
	int		t_min;

	c_min = algos->cmax;
	i_c = algos->c_pos + 1;
printf("c_min.init[%d], ic[%d]->", c_min, i_c);
	while (i_c < algos->cmax)
	{
		c_sum = col_sum(i_solved, algos, i_c);
		if (c_sum != 0)
		{
			t_min = c_min;
			c_min = col_min(c_min, c_sum);

//			if (c_min != t_min)
//				algos->c_pos = i_c;

			if (algos->t_num == 1)
			{
				if ((c_min != t_min) && (c_min >= algos->tmax))
//				if ((c_min != t_min) && (c_min > 1))
					algos->c_pos = i_c;
			}
			else
			{
				if (c_min != t_min)
					algos->c_pos = i_c;
			}

		}
		i_c = i_c + 1;
	}
printf("c_min[%d] --> [c_pos: %d]", c_min, algos->c_pos);
	return (algos->c_pos);
}

int		find_l_one(int **i_solve, t_algo *algos, int c_one)
{
	int		i_l;

	i_l = 0;
	while (i_l < algos->lmax)
	{
		if (i_solve[i_l][c_one] == 1)
		{
printf(" --> [l_one: %d]\n", i_l);
			return (i_l);
		}
		i_l = i_l + 1;
	}
printf("--> [l_one: %s]\n", "-1");
	return (-1);
}

t_pos	*find_sol(t_pos **t_sol, int **i_sol, t_algo *alg, int l_one)
{
	int		i;
	int		t;
	int		i_c;
	t_pos	*tmp_sol;

	i = 0;
	i_c = 0;
	tmp_sol = *t_sol;
	t = ft_sqrt(alg->cmax - alg->tmax);
printf("SOL[%d] -> [%dx%d]", alg->t_num, t, t);
printf("%s", " (isol: ");
	tmp_sol->letter = ' ';
	while (i_c < alg->tmax)
	{
if (i_c != alg->tmax - 1)
	printf("%d, ", i_sol[l_one][i_c]);
else
	printf("%d", i_sol[l_one][i_c]);
		if (i_sol[l_one][i_c] == 1)
			tmp_sol->letter = 'A' + i_c;
		i_c = i_c + 1;
	}
printf(") | letter[%c]", tmp_sol->letter);
	if ((tmp_sol->letter == ' ') || (tmp_sol->letter < 'A') || (tmp_sol->letter > 'Z'))
	{
printf("%s", "!!! bad letter !!!");
		return (NULL);
	}
	i_c = alg->tmax;
	while (i_c < alg->cmax)
	{
		if (i_sol[l_one][i_c] == 1)
		{
			tmp_sol->pos[i][0] = (i_c - alg->tmax) / t;
			tmp_sol->pos[i][1] = (i_c - alg->tmax) % t;
printf(" | ic[%d]->pos[%d]: %d,%d",
		i_c, i, tmp_sol->pos[i][0], tmp_sol->pos[i][1]);
			i = i + 1;
		}
		i_c = i_c + 1;
	}
printf("%s", "\n");
	return (*t_sol);
}

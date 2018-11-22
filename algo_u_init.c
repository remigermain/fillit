/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_u_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 15:54:40 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_algo	*algo_v_init(int tmax_v, int cmax_v, int lmax_v, int t_num_v)
{
	t_algo	*algos;

	if (!(algos = (t_algo*)malloc(sizeof(t_algo) * (4))))
		return (NULL);
	algos->tmax = tmax_v;
	algos->cmax = cmax_v;
	algos->lmax = lmax_v;
	algos->c_pos = tmax_v - 1;
	algos->t_num = t_num_v;
	return (algos);
}

int		**algo_t_init(int **i_option, int cmax, int lmax)
{
	int		i;
	int		j;
	int		**i_init;

	if (!(i_init = (int**)malloc(sizeof(int*) * lmax)))
		return (NULL);
	i = 0;
	while (i < lmax)
	{
		if (!(i_init[i] = (int*)malloc(sizeof(int) * cmax)))
			return (NULL);
		j = 0;
		while (j < cmax)
		{
			i_init[i][j] = i_option[i][j];
			j = j + 1;
		}
		i = i + 1;
	}
	return (i_init);
}

t_pos	*sol_init(t_pos **t_solpos)
{
	t_pos	*tmp_sol;

	tmp_sol = *t_solpos;
	tmp_sol = tpos_new();
	tpos_add(t_solpos, tmp_sol);
	return (tmp_sol);
}

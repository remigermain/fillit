/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_u_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 11:35:58 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_algo	*algo_v_init(int tmax_val, int cmax_val, int lmax_val, int c_pos_val)
{
	t_algo	*algos;

	if (!(algos = (t_algo*)malloc(sizeof(t_algo) * (4))))
		return (NULL);
	algos->tmax = tmax_val;
	algos->cmax = cmax_val;
	algos->lmax = lmax_val;
	algos->c_pos = c_pos_val;
	return (algos);
}

int		**algo_t_init(int **t_option, int cmax, int lmax)
{
	int		i;
	int		j;
	int		**t_init;

	if (!(t_init = (int**)malloc(sizeof(int*) * lmax)))
		return (NULL);
	i = 0;
	while (i < lmax - 1)
	{
		if (!(t_init[i] = (int*)malloc(sizeof(int) * cmax)))
			return (NULL);
		j = 0;
		while (j < cmax + 1)
		{
			t_init[i][j] = t_option[i][j];
			j = j + 1;
		}
		i = i + 1;
	}
	return (t_init);
}

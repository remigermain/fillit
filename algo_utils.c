/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_utils.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 15:55:02 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		col_min(int vala, int valb)
{
	if (vala <= valb)
		return (vala);
	else
		return (valb);
}

int		col_sum(int **t_solved, t_algo *algos, int i_c)
{
	int	i_l;
	int	c_sum;

	i_l = 0;
	c_sum = 0;
	while (i_l < algos->lmax)
	{
		if (t_solved[i_l][i_c] != -1)
			c_sum = c_sum + t_solved[i_l][i_c];
		i_l = i_l + 1;
	}
	return (c_sum);
}

t_pos	*tpos_new(void)
{
	t_pos	*t_new;

	if (!(t_new = (t_pos*)malloc(sizeof(t_pos))))
		return (NULL);
	t_new->next = NULL;
	return (t_new);
}

void	tpos_add(t_pos **alst, t_pos *blst)
{
	if ((!alst) || (!blst))
		return ;
	else
	{
		blst->next = *alst;
		*alst = blst;
		return ;
	}
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_u_find.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 17:33:19 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		find_min(int vala, int valb)
{
	if (vala <= valb)
		return (vala);
	else
		return (valb);
}

int		find_c_pos(int **t_solve, t_algo *algos)
{
	int		i_c;
	int		i_l;
	int		c_sum;
	int		c_min;
	int		t_min;

printf("%s | ", "find_c_pos");
printf("cmax : %d | ", algos->cmax);
printf("lmax : %d | ", algos->lmax);
printf("c_pos : %d | ", algos->c_pos);
	c_min = algos->cmax;
	i_c = algos->c_pos + 1;
printf("c_min : %d | ", c_min);
printf("i_c : %d |", i_c);
	while (i_c < algos->cmax)
	{
		i_l = 0;
		c_sum = 0;
		while (i_l < algos->lmax - 1)
		{
			if (t_solve[i_l][i_c] != -1)
				c_sum = c_sum + t_solve[i_l][i_c];
			i_l = i_l + 1;
		}
		if (c_sum != 0)
		{
			t_min = c_min;
			c_min = find_min(c_min, c_sum);
			if (c_min != t_min)
				algos->c_pos = i_c;
		}
		i_c = i_c + 1;
	}
printf(" --> [c_pos: %d]\n", algos->c_pos);
	return (algos->c_pos);
}

/*
int		find_c_one(int **t_solved, t_algo *algos, int l_one)
{
	int		i_c;

printf("%s", "find_c_one");
////printf("c_pos : %d | ", algos->c_pos);
//	i_c = (c_one == 0) ? 0 : c_one + 1;

	i_c = 0;
	while (i_c < algos->cmax)
	{
		if (t_solved[l_one][i_c] == 1)
		{
printf(" --> [c_one: %d]\n", i_c);
			return (i_c);
		}
		i_c = i_c + 1;
	}
printf("--> [c_one: %s]\n", "-1");
	return (-1);
}
*/

int		find_l_one(int **t_solved, t_algo *algos, int c_one)
{
	int		i_l;

printf("%s", "find_l_one");
////printf("c_pos : %d | ", algos->c_pos);
//	i_c = (c_one == 0) ? 0 : c_one + 1;

	i_l = 0;
	while (i_l < algos->lmax - 1)
	{
////printf("t_s[%d]", i_l);
////printf("[%d] : ", c_one);
////printf("%d", t_solved[i_l][c_one]);
		if (t_solved[i_l][c_one] == 1)
		{
printf(" --> [l_one: %d]\n", i_l);
			return (i_l);
		}
////printf("\n%s", "");
		i_l = i_l + 1;
	}
printf("--> [l_one: %s]\n", "-1");
	return (-1);
}

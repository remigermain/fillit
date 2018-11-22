/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_valid.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 12:09:37 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		lig_sum(int **t_solved, t_algo *algos, int i_l)
{
	int	i_c;
	int	l_sum;

	i_c = 0;
	l_sum = 0;
	while (i_c < algos->cmax)
	{
		if (t_solved[i_l][i_c] != -1)
			l_sum = l_sum + t_solved[i_l][i_c];
		i_c = i_c + 1;
	}
	return (l_sum);
}

int		**isolve_csum(int **i_check, int **i_option, t_algo *algos)
{
	int	i_c;
	int	i_l;
	int	c_sum;

	i_c = 0;
	while (i_c < algos->cmax)
	{
		i_l = 0;
		c_sum = 0;
		while (i_l < algos->lmax)
		{
			i_check[i_l][i_c] = i_option[i_l][i_c];
			c_sum = c_sum + i_option[i_l][i_c];
			i_l = i_l + 1;
		}
		i_check[algos->lmax][i_c] = c_sum;
		i_c = i_c + 1;
	}
	return (i_check);
}

int		**isolve_lsum(int **i_check, int **i_option, t_algo *algos)
{
	int	i_c;
	int	i_l;
	int	l_sum;

	i_l = 0;
	l_sum = 0;
	while (i_l < algos->lmax)
	{
		i_c = 0;
		l_sum = 0;
		while (i_c < algos->cmax)
		{
			l_sum = l_sum + i_option[i_l][i_c];
			i_c = i_c + 1;
		}
		i_check[i_l][algos->cmax] = l_sum;
//		if (l_sum != 5)
//			return (-1);
		i_l = i_l + 1;
	}
	return (i_check);
}

int		check_error(int **i_check, t_algo *algos)
{
	int	i_l;

	i_l = 0;
	while (i_l < algos->lmax)
	{
		if (i_check[i_l][algos->cmax] != 5)
		{
printf("\n%s\n | ", "!!! tsolve ERROR in possibilities !!!");
			return (-1);
		}
		i_l = i_l + 1;
	}
	return (1);
}

int		isolve_check(int **i_option, t_algo *algos)
{
	int	**i_check;

	i_check = ft_create_ntab2(algos->lmax + 1, algos->cmax + 1, 0);
	i_check = isolve_csum(i_check, i_option, algos);
	i_check = isolve_lsum(i_check, i_option, algos);
ft_putchar('\n');
ft_print_ntab2(i_check, algos->lmax + 1, algos->cmax + 1);
	if (check_error(i_check, algos) == -1)
		return (-1);
	return (1);
}

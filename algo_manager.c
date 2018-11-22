/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 11:16:25 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 11:46:57 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_pos	*find_select(int **i_solve, t_algo *algos)
{
	int		l_one;
	t_pos	*t_solpos;

printf("\nCONFIG -> cmax: %d | lmax: %d | c_pos.init: %d | \n",
	algos->cmax, algos->lmax, algos->c_pos);
	t_solpos = tpos_new();
	while (algos->t_num <= algos->tmax)
	{
printf("TNB[%d] -> ", algos->t_num);
		algos->c_pos = find_c_pos(i_solve, algos);
		l_one = find_l_one(i_solve, algos, algos->c_pos);
		if (l_one == -1)
			return (NULL);
		t_solpos = find_sol(&t_solpos, i_solve, algos, l_one);
		if (algos->t_num == algos->tmax)
			return (t_solpos);
		i_solve = remove_cl(i_solve, algos, l_one);
printf("%s", "l_one --> ");
		i_solve = remove_line(i_solve, algos, l_one);
printf("%s", "c_pos --> ");
		i_solve = remove_col(i_solve, algos, algos->c_pos);
ft_print_ntab2(i_solve, algos->lmax, algos->cmax);
		algos->c_pos = algos->tmax - 1;
		algos->t_num = algos->t_num + 1;
		t_solpos = sol_init(&t_solpos);
	}
	return (t_solpos);
}

int		algo_solve(t_map **lst_map, int **i_option, int cmax, int lmax)
{
	t_algo	*algos;
	t_map	*l_solve;
	int		**i_solve;
	t_pos	*t_solpos;

	l_solve = *lst_map;
	algos = algo_v_init(l_solve->nb_tet, cmax, lmax, 1);
	if (isolve_check(i_option, algos) == -1)
		return (-1);
	i_solve = algo_t_init(i_option, cmax, lmax);
	t_solpos = find_select(i_solve, algos);
	free(i_solve);
	if (t_solpos == NULL)
		return (-1);
printf("\n%s\n", "---> SOLUTION <---");
	printlst_final(t_solpos, ft_sqrt(cmax - l_solve->nb_tet));
	return (1);
}

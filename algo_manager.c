/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alepercq <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 16:44:36 by alepercq     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 17:32:59 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		**find_select(int **t_solved, t_algo *algos)
{
	int		l_one;

printf("\n%s | ", "find_select");
printf("cmax : %d | ", algos->cmax);
printf("lmax : %d | ", algos->lmax);
printf("c_pos : %d\n", algos->c_pos);
//printf("l_pos : %d\n", algos->l_pos);
//printf("\n%s\n", "begin find select");
//ft_print_ntab2(t_solved, (algos->lmax - 1), (algos->cmax + 1));

	while (algos->c_pos < algos->cmax)
	{
printf("c_pos[%d] | ", algos->c_pos);
		l_one = find_l_one(t_solved, algos, algos->c_pos);
		if (l_one != -1)
		{
			t_solved = remove_cl_(t_solved, algos, l_one);
ft_print_ntab2(t_solved, (algos->lmax - 1), (algos->cmax + 1));
printf("%s", "l_one -->-");
			t_solved = remove_line(t_solved, algos, l_one);
		}
printf("%s", "c_pos -->-");
		t_solved = remove_col(t_solved, algos, algos->c_pos);
ft_print_ntab2(t_solved, (algos->lmax - 1), (algos->cmax + 1));
		algos->c_pos = algos->c_pos + 1;
		algos->c_pos = find_c_pos(t_solved, algos);
	}
	return (t_solved);
}

int		algo_solve_step(int **t_option, int tmax, int cmax, int lmax)
{
	int		t_num;
	int		**t_solved;
	t_algo	*algos;

	t_num = 1;
	algos = algo_v_init(tmax, cmax, lmax, tmax - 1);
	while (t_num <= tmax)
	{
		t_solved = algo_t_init(t_option, cmax, lmax);
printf("##### IN Tm[%d]\n", t_num);
		algos->c_pos = find_c_pos(t_solved, algos);
		t_solved = find_select(t_solved, algos);
printf("\n##### OUT Tm[%d]\n", t_num);
ft_print_ntab2(t_solved, (algos->lmax - 1), (algos->cmax + 1));
		free(t_solved);
		t_num = t_num + 1;
	}
	return (0);
}

int		algo_solve(t_map **lst_map, int **t_option, int cmax, int lmax)
{
//	int		t_num;
//	int		**t_solved;
	t_map	*l_solve;
//	t_algo	*algos;

//	t_num = 1;
	l_solve = *lst_map;

	algo_solve_step(t_option, l_solve->nb_tet, cmax, lmax);

////	algos = algo_v_init(cmax, lmax, l_solve->nb_tet - 1, 0);
//	algos = algo_v_init(cmax, lmax, l_solve->nb_tet - 1);
//	while (t_num <= l_solve->nb_tet)
//	{
//		t_solved = algo_t_init(t_option, cmax, lmax);
//printf("##### IN Tm[%d]\n", t_num);
//		algos->c_pos = find_c_pos(t_solved, algos);
////		algos->l_pos = find_l_pos(t_solved, algos);
//		t_solved = find_select(t_solved, algos);
//printf("\n##### OUT Tm[%d]\n", t_num);
//ft_print_ntab2(t_solved, (algos->lmax - 1), (algos->cmax + 1));
//		free(t_solved);
//		t_num = t_num + 1;
//	}
	return (1);
}

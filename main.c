/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 16:49:34 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 12:22:28 by alepercq    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_usage(char *prog_name)
{
	ft_putstr("usage: ");
	ft_putstr(prog_name);
	ft_putendl(" \"source_file\" ");
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		if (main_manager(argv[1]) == -1)
			ft_putendl("error");
	if (argc != 2)
		ft_usage(argv[0]);
	return (0);
}

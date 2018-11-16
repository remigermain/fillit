/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:24:32 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 15:08:30 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *str)
{
	int count;

	count = 0;
	if (!str)
		return ;
	while (str[count] != '\0')
		ft_putchar(str[count++]);
}

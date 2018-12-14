/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:59:00 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 12:45:03 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t len_dst;
	size_t len_src;
	size_t count;

	len_dst = ft_strlen(s1);
	len_src = ft_strlen(s2);
	count = 0;
	if (!s1 || !s2)
		return (0);
	if ((int)len_dst > (int)(size - 1))
		return (len_src + size);
	while ((len_dst + count) < (size - 1) && count < len_src)
	{
		s1[len_dst + count] = s2[count];
		count++;
	}
	s1[len_dst + count] = '\0';
	return (len_dst + len_src);
}

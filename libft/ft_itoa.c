/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:24:04 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 18:07:44 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_nb(int n)
{
	int count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 9)
	{
		count++;
		n = n / 10;
	}
	return (count + 1);
}

static char	*ft_itoa_cal(char *str, int n, int len)
{
	str[len--] = (char)(n % 10) + '0';
	while (n > 9)
	{
		n = n / 10;
		str[len--] = (char)(n % 10) + '0';
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		nb;
	int		len;
	char	*str;

	nb = 0;
	len = ft_len_nb(n);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			str[1] = '2';
			n = -147483648;
		}
		str[0] = '-';
		n = n * -1;
	}
	len--;
	return (ft_itoa_cal(str, n, len));
}

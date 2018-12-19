/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_manager.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 15:57:16 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:18:22 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	*read_files(int fd, char *str_map)
{
	int		i_ret;
	char	*s_buff;
	char	*s_tmp;

	if ((read(fd, str_map, 0) < 0) || !(s_buff = ft_strnew(1024)))
		return (NULL);
	while ((i_ret = read(fd, s_buff, 1024)) > 0)
	{
		s_buff[i_ret] = '\0';
		if (!str_map)
			str_map = ft_strdup(s_buff);
		else
		{
			s_tmp = ft_strjoin(str_map, s_buff);
			ft_memdel((void**)&str_map);
			str_map = s_tmp;
		}
	}
	free(s_buff);
	return (str_map);
}

int		main_manager(char *files)
{
	int		fd;
	char	*str_map;
	t_map	*list_map;

	str_map = NULL;
	list_map = NULL;
	if ((fd = open(files, O_RDONLY)) < 1)
		return (-1);
	if ((str_map = read_files(fd, str_map)) == NULL)
		return (-1);
	if (ft_checkfiles(str_map, 0, 0, 0) == -1)
		return (-1);
	if (lst_create(&list_map, str_map) == -1)
		return (-1);
	resolve_manager(&list_map);
	ft_freelist(list_map);
	return (1);
}

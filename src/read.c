/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:38:46 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/12/08 13:19:39 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mat	**ft_read(char *av, t_ptr *ptr)
{
	t_list	*list;
	int		fd;
	int		i;
	char	*line;
	t_mat	**crd;

	i = 0;
	fd = ft_check_file(av);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_wordcount(line, 32) > 0)
		{
			if (i == 0)
				list = ft_lstnew(line, sizeof(char) * (ft_strlen(line) + 1));
			else
				ft_lstaddback(&list, line, sizeof(char) *
					(ft_strlen(line) + 1));
			i++;
		}
		free(line);
	}
	ptr->ly = i;
	crd = ft_write_map(list, i, ptr);
	ft_dellst(&list);
	return (crd);
}

int		ft_rgb_check(char *str)
{
	int		res;
	int		i;
	int		len;

	res = 0;
	i = 2;
	len = (ft_strlen(str) - 3);
	while (str[i] && len >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res += (str[i] - '0') * pow(16, len);
			len--;
		}
		if ((str[i] >= 65 && str[i] <= 70) || (str[i] >= 97 && str[i] <= 102))
		{
			res += ft_get_num(str[i]) * pow(16, len);
			len--;
		}
		i++;
	}
	ft_valid_res(res);
	return (res);
}

int		ft_rgb(char *map, int z)
{
	int		i;
	int		rgb;

	i = 0;
	while (map[i] && map[i] != ',')
		i++;
	if (map[i] != ',' && z < 0)
		return (rgb = ft_rgb_check("0xffff00"));
	else if (map[i] != ',' && z > 0)
		return (rgb = ft_rgb_check("0x00c900"));
	else if (map[i] != ',' && z == 0)
		return (rgb = ft_rgb_check("0x8e09c6"));
	i++;
	return (rgb = ft_rgb_check(map + i));
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

t_mat	**ft_write_map(t_list *list, int j, t_ptr *ptr)
{
	char	**map;
	t_mat	**crd;
	int		i;

	MLC((crd = (t_mat**)malloc(sizeof(t_mat*) * j)));
	j = -1;
	ptr->lx = ft_wordcount(list->content, 32);
	while (list)
	{
		map = ft_strsplit(list->content, 32);
		MLC((crd[++j] = (t_mat*)malloc(sizeof(t_mat) *
			ft_wordcount(list->content, 32))));
		i = -1;
		while (map[++i])
		{
			ft_error_check(ptr, list->content);
			crd[j][i].x = i;
			crd[j][i].y = j;
			crd[j][i].z = ft_atoi(map[i]);
			crd[j][i].rgb = ft_rgb(map[i], crd[j][i].z);
		}
		list = list->next;
		ft_free_map(map);
	}
	return (crd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:14:49 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/12/04 15:14:50 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		ft_get_num(char c)
{
	int		res;

	if (c == 65 || c == 97)
		res = 10;
	if (c == 66 || c == 98)
		res = 11;
	if (c == 67 || c == 99)
		res = 12;
	if (c == 68 || c == 100)
		res = 13;
	if (c == 69 || c == 101)
		res = 14;
	if (c == 70 || c == 102)
		res = 15;
	return (res);
}

void	ft_valid_res(int res)
{
	if (res < 0 || res > 16777215)
	{
		ERROR_COLOR(0);
		exit(EXIT_FAILURE);
	}
}

int		ft_check_file(char *av)
{
	int		fd;

	fd = 0;
	if (!(ft_strstr(av, ".fdf")))
	{
		ERROR_FILE(0);
		exit(0);
	}
	if ((fd = open(av, O_DIRECTORY)) >= 0)
	{
		ERROR_FILE(0);
		exit(0);
	}
	if ((fd = open(av, O_RDONLY)) < 0)
	{
		ERROR_FILE(0);
		exit(0);
	}
	return (fd);
}

void	ft_error_check(t_ptr *ptr, char *str)
{
	if ((size_t)ptr->lx != ft_wordcount(str, 32))
	{
		ERROR_FILE(0);
		exit(EXIT_FAILURE);
	}
}

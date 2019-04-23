/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:53:56 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/12/14 17:53:57 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_orto_projection(t_ptr *ptr)
{
	int		i;
	int		j;
	int		x1;
	int		y1;

	ft_map_coords(ptr);
	i = -1;
	while (++i < ptr->ly)
	{
		j = -1;
		while (++j < ptr->lx)
		{
			x1 = ptr->crd[i][j].x;
			y1 = ptr->crd[i][j].y;
			ptr->crd[i][j].x = x1 - y1;
			ptr->crd[i][j].y = (x1 + y1) / 2 - ptr->crd[i][j].z;
		}
	}
	ft_draw(ptr);
}

void	ft_persp_projection(int key, t_ptr *ptr)
{
	int	i;
	int	j;
	int	x1;
	int y1;

	if (key == P_BUTTON)
		ptr->pm = 1;
	else if (key == L_BUTTON)
		ptr->pm = -1;
	ptr->pr = 0;
	x1 = ptr->lx;
	y1 = ptr->ly;
	i = -1;
	while (++i < ptr->ly)
	{
		j = -1;
		while (++j < ptr->lx)
		{
			ptr->crd[i][j].x -= x1 * ptr->pm;
			ptr->crd[i][j].y += (y1 - ptr->crd[i][j].z) * ptr->pm;
		}
		x1--;
		y1--;
	}
	ft_draw(ptr);
}

void	ft_z_coord(int key, t_ptr *ptr)
{
	int		i;
	int		j;

	if (key == Z_UP)
		ptr->pm = 1;
	else if (key == Z_DOWN)
		ptr->pm = -1;
	if (key == Z_UP || key == Z_DOWN)
	{
		i = -1;
		while (++i < ptr->ly)
		{
			j = -1;
			while (++j < ptr->lx)
			{
				if (ptr->crd[i][j].z != 0)
					ptr->crd[i][j].z += 9 * ptr->pm;
			}
		}
	}
	ft_map_coords(ptr);
}

void	ft_check_zoom(t_ptr *ptr, int key)
{
	if (key == NUM_PLUS)
		ptr->pm = 1;
	else
		ptr->pm = -1;
}

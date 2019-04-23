/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:45:33 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/12/14 17:45:35 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_brezen(t_ptr *ptr)
{
	while (ptr->crd[ptr->d->i1][ptr->d->j1].nx !=
		ptr->crd[ptr->d->i2][ptr->d->j2].x ||
		ptr->crd[ptr->d->i1][ptr->d->j1].ny !=
		ptr->crd[ptr->d->i2][ptr->d->j2].y)
	{
		ft_pixel_put(ptr, ptr->crd[ptr->d->i1][ptr->d->j1].nx + ptr->d->wid,
			ptr->crd[ptr->d->i1][ptr->d->j1].ny + ptr->d->hei,
			ptr->crd[ptr->d->i1][ptr->d->j1].rgb);
		ptr->delta->error[1] = ptr->delta->error[0] * 2;
		if (ptr->delta->error[1] > -ptr->delta->dy)
		{
			ptr->delta->error[0] -= ptr->delta->dy;
			ptr->crd[ptr->d->i1][ptr->d->j1].nx += ptr->delta->sx;
		}
		if (ptr->delta->error[1] < ptr->delta->dx)
		{
			ptr->delta->error[0] += ptr->delta->dx;
			ptr->crd[ptr->d->i1][ptr->d->j1].ny += ptr->delta->sy;
		}
	}
}

void	ft_pixel_put(t_ptr *ptr, int x, int y, int rgb)
{
	int	i;

	if (x >= 0 && x < WIDHT && y >= 0 && y < HEIGHT)
	{
		i = (x * ptr->bits_per_pixel / 8 + y * ptr->size_line);
		ptr->simg[i] = rgb;
		ptr->simg[++i] = rgb >> 8;
		ptr->simg[++i] = rgb >> 16;
	}
}

void	ft_draw_init(t_ptr *ptr)
{
	ptr->delta->dx = abs(ptr->crd[ptr->d->i2][ptr->d->j2].x -
		ptr->crd[ptr->d->i1][ptr->d->j1].x);
	ptr->delta->dy = abs(ptr->crd[ptr->d->i2][ptr->d->j2].y -
		ptr->crd[ptr->d->i1][ptr->d->j1].y);
	ptr->delta->sx = ptr->crd[ptr->d->i1][ptr->d->j1].x <
	ptr->crd[ptr->d->i2][ptr->d->j2].x ? 1 : -1;
	ptr->delta->sy = ptr->crd[ptr->d->i1][ptr->d->j1].y <
	ptr->crd[ptr->d->i2][ptr->d->j2].y ? 1 : -1;
	ptr->delta->error[0] = ptr->delta->dx - ptr->delta->dy;
}

void	ft_draw_map(t_ptr *ptr)
{
	ptr->crd[ptr->d->i1][ptr->d->j1].nx = ptr->crd[ptr->d->i1][ptr->d->j1].x;
	ptr->crd[ptr->d->i1][ptr->d->j1].ny = ptr->crd[ptr->d->i1][ptr->d->j1].y;
	ft_draw_init(ptr);
	ft_pixel_put(ptr, ptr->crd[ptr->d->i2][ptr->d->j2].x + ptr->d->wid,
		ptr->crd[ptr->d->i2][ptr->d->j2].y + ptr->d->hei,
		ptr->crd[ptr->d->i2][ptr->d->j2].rgb);
	ft_brezen(ptr);
}

void	ft_draw(t_ptr *ptr)
{
	int		i;
	int		j;

	i = -1;
	ptr->img = mlx_new_image(ptr->mlx, WIDHT, HEIGHT);
	ptr->simg = mlx_get_data_addr(ptr->img, &ptr->bits_per_pixel,
		&ptr->size_line, &ptr->endian);
	while (++i < ptr->ly)
	{
		j = 0;
		while (j < ptr->lx)
		{
			ptr->d->i1 = i;
			ptr->d->j1 = abs(j - 1);
			ptr->d->i2 = i;
			ptr->d->j2 = j;
			ft_draw_map(ptr);
			ptr->d->i1 = abs(i - 1);
			ptr->d->j1 = j;
			ft_draw_map(ptr);
			j++;
		}
	}
	ft_mlx(ptr);
}

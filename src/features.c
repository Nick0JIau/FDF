/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:38:26 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/12/14 17:38:30 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_move(int key, t_ptr *ptr)
{
	if (key == DOWN)
	{
		ptr->d->hei -= 5;
		ft_draw(ptr);
	}
	else if (key == UP)
	{
		ptr->d->hei += 5;
		ft_draw(ptr);
	}
	else if (key == RIGHT)
	{
		ptr->d->wid -= 5;
		ft_draw(ptr);
	}
	else if (key == LEFT)
	{
		ptr->d->wid += 5;
		ft_draw(ptr);
	}
}

void	ft_check_y(int i, int j, int l, t_ptr *ptr)
{
	if (i < ptr->ly / 2)
		ptr->crd[i][j].y -= l * ptr->pm;
	if (i > ptr->ly / 2)
		ptr->crd[i][j].y += (l + 1) * ptr->pm;
}

int		ft_check_x(int i, int j, int k, t_ptr *ptr)
{
	if (j < ptr->lx / 2)
	{
		ptr->crd[i][j].x -= k * ptr->pm;
		k--;
	}
	if (j > ptr->lx / 2)
	{
		k++;
		ptr->crd[i][j].x += k * ptr->pm;
	}
	return (k);
}

void	ft_feature(t_ptr *ptr)
{
	int i;
	int j;
	int k;
	int l;

	i = -1;
	l = ptr->ly / 2;
	while (++i < ptr->ly)
	{
		j = 0;
		k = ptr->lx / 2;
		while (j < ptr->lx)
		{
			ft_check_y(i, j, l, ptr);
			k = ft_check_x(i, j, k, ptr);
			j++;
		}
		if (i < ptr->ly / 2)
			l--;
		if (i > ptr->ly / 2)
			l++;
	}
	ft_draw(ptr);
}

int		ft_key(int key, t_ptr *ptr)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
		ft_move(key, ptr);
	if ((key == NUM_PLUS || key == NUM_MINUS) && ptr->pr != 1)
	{
		ft_check_zoom(ptr, key);
		ft_feature(ptr);
	}
	if (key == O_BUTTON)
	{
		ptr->pr = 1;
		ft_orto_projection(ptr);
	}
	if (key == C_BUTTON)
	{
		ptr->pr = 0;
		ft_map_coords(ptr);
	}
	if (key == P_BUTTON || key == L_BUTTON)
		ft_persp_projection(key, ptr);
	if (key == Z_UP || key == Z_DOWN)
		ft_z_coord(key, ptr);
	return (0);
}

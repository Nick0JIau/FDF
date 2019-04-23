/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:29:35 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/12/08 14:49:30 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_mlx(t_ptr *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	mlx_string_put(ptr->mlx, ptr->win, 0, 0, 16777215, "Usage:");
	mlx_string_put(ptr->mlx, ptr->win, 0, 20, 16711680, "ESC to exit");
	mlx_string_put(ptr->mlx, ptr->win, 0, 40, 16739840, "ARROWS to move");
	mlx_string_put(ptr->mlx, ptr->win, 0, 60, 15924992,
		"Press 'O' to 1-st projection");
	mlx_string_put(ptr->mlx, ptr->win, 0, 80, 3269888,
		"Press 'P' or 'L' to 2-nd projection");
	mlx_string_put(ptr->mlx, ptr->win, 0, 100, 40447,
		"Press 'C' to go to change projection");
	mlx_string_put(ptr->mlx, ptr->win, 0, 120, 786687,
		"Press 'NUM_PLUS' or 'NUM_MINUS' to magic zoom");
	mlx_string_put(ptr->mlx, ptr->win, 0, 140, 8847615,
		"Press 'PAGE_UP' or 'PAGE_DOWN' to change height");
	mlx_destroy_image(ptr->mlx, ptr->img);
}

int		ft_step(t_ptr *ptr)
{
	int	i;
	int j;

	i = WIDHT / ptr->lx / 2;
	j = HEIGHT / ptr->ly / 2;
	return (i > j ? j : i);
}

void	ft_map_coords(t_ptr *ptr)
{
	int		i;
	int		j;

	i = -1;
	ptr->d->wid = (WIDHT - ptr->lx * ft_step(ptr)) / 3;
	ptr->d->hei = (HEIGHT - ptr->ly * ft_step(ptr)) / 6;
	while (++i < ptr->ly)
	{
		j = -1;
		while (++j < ptr->lx)
		{
			ptr->crd[i][j].x = ptr->d->wid + ft_step(ptr) * j;
			ptr->crd[i][j].y = ptr->d->hei + ft_step(ptr) * i;
		}
	}
	ft_draw(ptr);
}

int		main(int ac, char **av)
{
	t_ptr	*ptr;
	t_mat	**crd;

	if (ac == 2)
	{
		ptr = (t_ptr*)malloc(sizeof(t_ptr));
		crd = ft_read(av[1], ptr);
		ptr->delta = (t_delta*)malloc(sizeof(t_delta));
		ptr->d = (t_draw*)malloc(sizeof(t_draw));
		ptr->crd = crd;
		ptr->mlx = mlx_init();
		ptr->win = mlx_new_window(ptr->mlx, WIDHT, HEIGHT, TITTLE);
		ft_map_coords(ptr);
		mlx_hook(ptr->win, 2, 5, ft_key, ptr);
		mlx_loop(ptr->mlx);
	}
	else
	{
		ERROR_USAGE(0);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrusevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:20:38 by ntrusevi          #+#    #+#             */
/*   Updated: 2018/11/27 14:20:40 by ntrusevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDHT 1920
# define HEIGHT 1080
# define TITTLE "FDF"

# include "mlx.h"
# include "../libft/inc/libft.h"
# include <fcntl.h>
# include <math.h>

# define ESC		53
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define NUM_PLUS	69
# define NUM_MINUS	78
# define O_BUTTON	31
# define P_BUTTON	35
# define L_BUTTON	37
# define C_BUTTON	8
# define Z_UP		116
# define Z_DOWN		121

# define MLC(x) if (!x) {free(x); exit(EXIT_FAILURE);}
# define ERROR_USAGE(x) if (x == 0) {ft_putendl("Usage: ./fdf Map_file");}
# define ERROR_COLOR(x) if (x == 0) {ft_putendl("Invalid color");}
# define ERROR_FILE(x) if (x == 0) {ft_putendl("Invalid file");}

typedef struct	s_draw
{
	int		i1;
	int		j1;
	int		i2;
	int		j2;
	int		wid;
	int		hei;
}				t_draw;

typedef struct	s_mat
{
	int		x;
	int		y;
	int		z;
	int		nx;
	int		ny;
	int		rgb;
}				t_mat;

typedef struct	s_delta
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		error[2];
}				t_delta;

typedef struct	s_ptr
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*simg;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		lx;
	int		ly;
	int		pm;
	int		pr;
	t_draw	*d;
	t_mat	**crd;
	t_delta	*delta;
}				t_ptr;

t_mat			**ft_read(char *av, t_ptr *ptr);
t_mat			**ft_write_map(t_list *list, int j, t_ptr *ptr);
int				ft_get_num(char c);
int				ft_rgb_check(char *str);
int				ft_rgb(char *map, int z);
int				ft_key(int key, t_ptr *ptr);
int				ft_check_file(char *av);
void			ft_lstaddback(t_list **list, char const *content,
	size_t content_size);
void			ft_dellst(t_list **list);
void			ft_valid_res(int res);
void			ft_valid_map(t_list *list, int i);
void			ft_free_map(char **map);
void			ft_draw_map(t_ptr *ptr);
void			ft_draw(t_ptr *ptr);
void			ft_pixel_put(t_ptr *ptr, int x, int y, int rgb);
void			ft_orto_projection(t_ptr *ptr);
void			ft_persp_projection(int key, t_ptr *ptr);
void			ft_z_coord(int key, t_ptr *ptr);
void			ft_map_coords(t_ptr *ptr);
void			ft_mlx(t_ptr *ptr);
void			ft_error_check(t_ptr *ptr, char *str);
void			ft_check_zoom(t_ptr *ptr, int key);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:47:29 by gdara             #+#    #+#             */
/*   Updated: 2022/02/14 10:47:29 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_data
{
	void	*mlx_win;
	void	*mlx;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	ymin;
	double	xmax;
	double	ymax;
	double	xmin;
	int		iter_x;
	int		iter_y;
	int		color;
	double	change_y;
	double	change_x;
	char	flag;
}	t_data;

int		mandelbrot(t_data *mlx);
int		julia(t_data *mlx);
int		close_cross(void);
void	make_move(int keycode, t_data *mlx);
int		event_keys(int keycode, t_data *mlx);
void	start_fractal(t_data *data);
int		event_zoom(int keycode, int x, int y, t_data *mlx);
void	img_pix_put(t_data *data, int x, int y, int color);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
void	instruction(void);
void	wrong_mame(void);
void	wrong_count_of_args(void);

#endif

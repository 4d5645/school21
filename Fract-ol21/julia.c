/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:46:23 by gdara             #+#    #+#             */
/*   Updated: 2022/02/14 10:46:23 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_set(double x, double y, t_data *mlx)
{
	int		i;
	double	xx;
	double	yy;
	double	temp;

	xx = x;
	yy = y;
	i = 1;
	while (i < 150)
	{
		temp = xx;
		xx = (xx * xx - yy * yy) - 0.2 + mlx->change_x;
		yy = (2 * temp * yy) + 0.75 + mlx->change_y;
		if (xx * xx + yy * yy > 4)
		{
			img_pix_put(mlx, mlx->iter_x, mlx->iter_y, (mlx->color)
				+ 0x00BA55D3 * i);
			return (0);
		}
		i++;
	}
	img_pix_put(mlx, mlx->iter_x, mlx->iter_y, 0x000E0E0E);
	return (0);
}

int	julia(t_data *data)
{
	double	x;
	double	y;

	data->iter_y = 0;
	mlx_clear_window(data->mlx, data->mlx_win);
	while (data->iter_y < HEIGHT)
	{
		data->iter_x = 0;
		while (data->iter_x < WIDTH)
		{
			x = data->xmin + (data->iter_x
					* ((data->xmax - data->xmin) / WIDTH));
			y = data->ymax - (data->iter_y
					* ((data->ymax - data->ymin) / HEIGHT));
			julia_set(x, y, data);
			data->iter_x++;
		}
		data->iter_y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

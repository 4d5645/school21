/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:40:16 by gdara             #+#    #+#             */
/*   Updated: 2022/02/14 10:40:16 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

/*
** In the loop, consider whether the given pixel 
** is included in the Mandlbrot set and paint it 
** in the corresponding color.
*/

int	mandelbrot_set(double x, double y, t_data *data)
{
	int		i;
	double	xx;
	double	yy;
	double	temp;

	xx = 0;
	yy = 0;
	i = 1;
	while (i < 150)
	{
		temp = xx;
		xx = (xx * xx - yy * yy) + x;
		yy = (2 * temp * yy) + y;
		if (xx * xx + yy * yy > 4)
		{
			img_pix_put(data, data->iter_x, data->iter_y,
				(data->color) + 0x006495ED * i);
			return (0);
		}
		i++;
	}
	img_pix_put(data, data->iter_x, data->iter_y, 0x000E0E0E);
	return (0);
}

/*
** Use nested loop.
** Find the current pixel coordinates.
*/

int	mandelbrot(t_data *data)
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
			y = data->ymin + (data->iter_y
					*((data->ymax - data->ymin) / HEIGHT));
			mandelbrot_set(x, y, data);
			data->iter_x++;
		}
		data->iter_y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

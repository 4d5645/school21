/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:50:10 by gdara             #+#    #+#             */
/*   Updated: 2022/02/14 10:50:10 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_move(int key_code, t_data *data)
{
	float	dx;
	float	dy;

	dx = (data->xmax - data->xmin);
	dy = (data->ymax - data->ymin);
	if (key_code == 123 || key_code == 124)
	{
		if (key_code == 123)
			dx *= -1;
		data->xmin += dx / 7.5;
		data->xmax += dx / 7.5;
	}
	if (key_code == 126 || key_code == 125)
	{
		if (key_code == 126 && data->flag == 'm')
			dy *= -1;
		if (key_code == 125 && data->flag == 'j')
			dy *= -1;
		data->ymin += dy / 7.5;
		data->ymax += dy / 7.5;
	}
}

int	event_keys(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 124
		|| keycode == 126 || keycode == 125)
		make_move(keycode, data);
	if (keycode == 49)
		data->color += 0x00111111;
	if (keycode == 1)
		data->change_y += 0.1;
	if (keycode == 13)
		data->change_y -= 0.1;
	if (keycode == 0)
		data->change_x -= 0.1;
	if (keycode == 2)
		data->change_x += 0.1;
	start_fractal(data);
	return (0);
}

int	event_zoom(int keycode, int x, int y, t_data *data)
{
	float	dx;
	float	dy;

	dx = (data->xmax - data->xmin) / WIDTH;
	dy = (data->ymax - data->ymin) / HEIGHT;
	if (keycode == 5)
	{
		data->xmin = (data->xmin + ((dx * x) * 0.3));
		data->xmax = (data->xmax - ((dx * (WIDTH - x)) * 0.3));
		data->ymax = (data->ymax - ((dy * y) * 0.3));
		data->ymin = (data->ymin + ((dy * (HEIGHT - y)) * 0.3));
	}
	if (keycode == 4)
	{
		data->xmin = (data->xmin - ((dx * x) * 0.3));
		data->xmax = (data->xmax + ((dx * (WIDTH - x)) * 0.3));
		data->ymax = (data->ymax + ((dy * y) * 0.3));
		data->ymin = (data->ymin - ((dy * (HEIGHT - y)) * 0.3));
	}
	start_fractal(data);
	return (0);
}

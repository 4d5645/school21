/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:45:06 by gdara             #+#    #+#             */
/*   Updated: 2022/02/14 10:45:06 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	instruction(void)
{
	ft_putstr_fd("\033[32mHow to use: ./fractol <name> \e[0m\n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\033[32mFractals you can draw: \e[0m\n", 1);
	ft_putstr_fd("1. Mandelbrot\n", 1);
	ft_putstr_fd("2. Julia\n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\033[32mWhat can be clicked: \e[0m\n", 1);
	ft_putstr_fd("1. To navigate - arrows\n", 1);
	ft_putstr_fd("2. To zoom in - scroll up\n", 1);
	ft_putstr_fd("3. To zoom out - scroll down\n", 1);
	ft_putstr_fd("4. To change colors - space\n", 1);
	ft_putstr_fd("5. To change view of Julia - W,D,S,A\n", 1);
	ft_putstr_fd("\n", 1);
}

void	initialize(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
	data->img = mlx_new_image(data, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->xmin = -2;
	data->xmax = 2;
	data->ymin = -2;
	data->ymax = 2;
	data->color = 0;
}

void	start_fractal(t_data *data)
{
	if (data->flag == 'm')
		mandelbrot(data);
	if (data->flag == 'j')
		julia(data);
}

/*
** Initialize the structure and determine which fractal is given as an argument.
** Draw fractal and read events.
*/

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		initialize(&data);
		if (!ft_strcmp(argv[1], "Mandelbrot"))
		{
			data.flag = 'm';
			start_fractal(&data);
		}
		else if (!ft_strcmp(argv[1], "Julia"))
		{
			data.flag = 'j';
			start_fractal(&data);
		}
		else
			wrong_mame();
		mlx_hook(data.mlx_win, 17, 2, close_cross, NULL);
		mlx_key_hook(data.mlx_win, event_keys, &data);
		mlx_mouse_hook(data.mlx_win, event_zoom, (void *)&data);
		mlx_loop(data.mlx);
	}
	else
		wrong_count_of_args();
}

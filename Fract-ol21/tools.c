/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:45:06 by gdara             #+#    #+#             */
/*   Updated: 2022/02/21 10:45:06 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Because we can't compare two strings in if() statement
*/

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s2[i] && s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
** Calculate the location of the pixel in the screen and paint it.
*/

void	img_pix_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(int *)pixel = color;
}

/*
** Close window when press cross
*/

int	close_cross(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	errors(int flag)
{
	if (flag == 1)
	{
		instruction();
		ft_putstr_fd("\033[31mWrong count of argumens\e[0m\n", 1);
	}
	else if (flag == 2)
	{
		instruction();
		ft_putstr_fd("\033[31mWrong name of fractal\e[0m\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	else
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}

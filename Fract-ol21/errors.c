/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:45:06 by gdara             #+#    #+#             */
/*   Updated: 2022/02/26 10:45:06 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	wrong_count_of_args(void)
{
	instruction();
	ft_putstr_fd("\033[31mWrong count of argumens\e[0m\n", 1);
}

void	wrong_mame(void)
{
	instruction();
	ft_putstr_fd("\033[31mWrong name of fractal\e[0m\n", 1);
	exit(EXIT_FAILURE);
}

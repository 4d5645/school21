/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:00:05 by gdara             #+#    #+#             */
/*   Updated: 2021/10/24 11:17:14 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int	c;

	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(fd, "-", 1);
			nb = -nb;
			ft_putnbr_fd(nb, fd);
		}
		else if (nb < 10)
		{
			c = nb + '0';
			write(fd, &c, 1);
		}
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			c = (nb % 10) + '0';
			write(fd, &c, 1);
		}
	}
}

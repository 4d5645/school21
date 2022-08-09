/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:43:02 by gdara             #+#    #+#             */
/*   Updated: 2022/06/05 11:43:02 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philosophers.h"

uint64_t	get_time(void)
{
	static struct timeval	time;

	if (gettimeofday(&time, 0))
		error("\033[31mTime error\e[0m\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

uint64_t	currtime(uint64_t now, uint64_t start)
{
	uint64_t	curr;

	curr = now - start;
	return (curr);
}

void	ft_usleep(uint64_t time)
{
	uint64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(500);
}

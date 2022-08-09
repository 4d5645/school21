/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:52:10 by gdara             #+#    #+#             */
/*   Updated: 2022/06/05 12:52:40 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

/*
** Philosopher thinks
*/

void	ft_think(t_ph *philo)
{
	ft_echo(1, "is thinking\n", currtime(get_time(), philo->data->start), philo);
}

/*
** Philosopher eats
*/

void	ft_eat(t_ph *philo)
{
	pthread_mutex_lock(philo->left);
	ft_echo(1, "\x1b[0;33mhas taken left fork\x1b[0m\n",
		currtime(get_time(), philo->data->start), philo);
	pthread_mutex_lock(philo->right);
	ft_echo(1, "\x1b[0;33mhas taken right fork\x1b[0m\n",
		currtime(get_time(), philo->data->start), philo);
	philo->last_eat = get_time();
	pthread_mutex_lock(&philo->mute);
	ft_echo(1, "\x1b[0;32mis eating\x1b[0m\n",
		currtime(get_time(), philo->data->start), philo);
	pthread_mutex_unlock(&philo->mute);
	ft_usleep(philo->data->time_to_eat);
	philo->count_eat += 1;
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

/*
** Philosopher sleeps
*/

void	ft_sleep(t_ph *philo)
{
	ft_echo(1, "is sleeping\n", currtime(get_time(), philo->data->start), philo);
	ft_usleep(philo->data->time_to_sleep);
}

/*
** Philosophers with an even id go to sleep so that 
** the philosophers with an odd id have time to eat, 
** and then an endless loop is started for all of them.
*/

void	*simulation(void *philo)
{
	t_ph		*ph;

	ph = (t_ph *)philo;
	ph->last_eat = ph->data->start;
	ft_think(ph);
	if (ph->id % 2 == 0)
		ft_usleep(ph->data->time_to_eat / 2);
	while (1)
	{
		ft_eat(ph);
		ft_sleep(ph);
		ft_think(ph);
	}
}

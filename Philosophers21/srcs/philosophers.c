/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:50:05 by gdara             #+#    #+#             */
/*   Updated: 2022/06/05 14:50:05 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	monitoring(t_data *data, t_ph **ph, pthread_t **thread)
{
	int	i;
	int	flag;

	ft_usleep(data->time_to_die / 2);
	while (1)
	{
		i = 0;
		flag = 1;
		while (i < data->number_of_philosophers)
		{
			if (currtime(get_time(), (*ph)[i].last_eat) >= data->time_to_die)
			{
				ft_echo(0, "\x1b[1;31mdied\x1b[0m\n",
					currtime(get_time(), data->start), &(*ph)[i]);
				return (free_threads(data, thread, 0));
			}
			if (data->number_must_eat > 0
				&& (*ph)[i].count_eat < data->number_must_eat)
				flag = 0;
			i++;
		}
		if (data->number_must_eat > 0 && flag == 1)
			return (free_threads(data, thread, 0));
	}
}

/*
** Creating threads for philosophers, starting simulation 
** and monitoring (if sb died)
*/

static void	threads(t_data *data, t_ph **ph)
{
	int			i;
	pthread_t	*thread;

	i = 0;
	thread = malloc(data->number_of_philosophers * sizeof(pthread_t));
	if (!thread)
		error("\033[31mMalloc error\e[0m\n");
	data->start = get_time();
	while (i < data->number_of_philosophers)
	{
		pthread_create(&thread[i], 0, simulation, &((*ph)[i]));
		i++;
	}
	monitoring(data, ph, &thread);
}

/*
** Allocating memory for each philosoph and mutexes
*/

static void	philosophers(t_data *data)
{
	t_ph			*ph;
	pthread_mutex_t	*mtxs;

	ph = malloc(data->number_of_philosophers * sizeof(t_ph));
	mtxs = malloc(data->number_of_philosophers * sizeof(pthread_mutex_t));
	if (ph && mtxs)
	{
		initialization(data, &ph, &mtxs);
		threads(data, &ph);
	}
	else
		error("\033[31mCan't allocate memory\e[0m\n");
}

/*
**	Programm takes the following arguments:
**	
**	number of philosophers,
** 
**	time to die - time (milliseconds) that philosopher'll live 
**	from beginning of the programm if he doesn't eat, 
**	
**	time to eat - time it takes for a philosopher to eat 
**	(he need 2 forks), 
**
**	time to sleep - time a philosopher'll spend sleeping,
**
**	number_of_times_each_philosopher_must_eat - simulation stops then. 
*/

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		data.number_of_philosophers = get_argument(argv[1]);
		data.time_to_die = get_argument(argv[2]);
		data.time_to_eat = get_argument(argv[3]);
		data.time_to_sleep = get_argument(argv[4]);
		if (argc == 6)
			data.number_must_eat = get_argument(argv[5]);
		else
			data.number_must_eat = -6022002;
		if (data.number_of_philosophers == 0 || data.number_must_eat == 0
			|| data.number_of_philosophers > 200 || data.time_to_die < 60
			|| data.time_to_eat < 60 || data.time_to_sleep < 60)
			error("\033[31mIncorrect data\e[0m\n");
		philosophers(&data);
	}
	else
		error("\033[31mWrong amount of argumens\e[0m\n");
}

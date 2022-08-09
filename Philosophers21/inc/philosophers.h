/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:09:16 by gdara             #+#    #+#             */
/*   Updated: 2022/06/05 12:09:15 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				number_of_philosophers;
	uint64_t		start;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				number_must_eat;
	pthread_mutex_t	out;
}	t_data;

typedef struct s_ph
{
	struct s_data	*data;
	int				id;
	int				count_eat;
	pthread_mutex_t	mute;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	uint64_t		last_eat;
}	t_ph;

void		error(char *name);
uint64_t	get_time(void);
void		initialization(t_data *data, t_ph **philo, pthread_mutex_t **mtxs);
int			get_argument(char *argument);
void		*simulation(void *philo);
uint64_t	currtime(uint64_t now, uint64_t start);
void		free_threads(t_data *data, pthread_t **treads, int flag);
void		ft_echo(int flag, char *str, uint64_t time, t_ph *ph);
void		ft_usleep(uint64_t time);

#endif
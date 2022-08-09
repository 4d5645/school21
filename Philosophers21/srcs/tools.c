/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:45:23 by gdara             #+#    #+#             */
/*   Updated: 2022/06/05 11:45:23 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ft_atoi(const char *str)
{
	size_t		i;
	short		sign;
	long long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (str[i] == 0)
		return (0);
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - 48);
	return (nbr * sign);
}

void	ft_echo(int flag, char *str, uint64_t time, t_ph *ph)
{
	pthread_mutex_lock(&ph->data->out);
	printf("%lldms %d philo %s", time, ph->id + 1, str);
	if (flag != 0)
		pthread_mutex_unlock(&ph->data->out);
}

void	free_threads(t_data *data, pthread_t **treads, int flag)
{
	int	nme;

	nme = data->number_must_eat;
	if (flag != 0)
		pthread_mutex_lock(&data->out);
	while (nme > 0)
	{
		pthread_detach((*treads)[nme - 1]);
		nme--;
	}
	free(*treads);
	return ;
}

/*
** Initializing the structure of each philosopher
*/

void	initialization(t_data *data, t_ph **philo, pthread_mutex_t **mtxs)
{
	int	i;
	int	nofp;

	i = 0;
	nofp = data->number_of_philosophers;
	while (i < nofp)
	{
		if (pthread_mutex_init(&(*mtxs)[i], 0) ||
			pthread_mutex_init(&(*philo)[i].mute, 0))
			error("\033[31mIncorrect data\e[0m\n");
		(*philo)[i].data = data;
		(*philo)[i].id = i;
		(*philo)[i].count_eat = 0;
		(*philo)[i].left = &(*mtxs)[i];
		if (i != nofp - 1)
			(*philo)[i + 1].right = &(*mtxs)[i];
		else
			(*philo)[0].right = (*philo)[i].left;
		i++;
	}
}

/*
** Parsing data from input
*/

int	get_argument(char *argument)
{
	int	i;
	int	content;

	i = 0;
	content = ft_atoi(argument);
	if (content < INT16_MIN || content > INT16_MAX)
		error("\033[31mGreater than INT_MAX or less than INT_MIN\e[0m\n");
	if ((argument[i] == '-') || (argument[i] > '9' || argument[i] < '0'))
		error("\033[31mInvalid arguments\e[0m\n");
	i++;
	while (argument[i] != '\0')
	{
		if (argument[i] > '9' || argument[i] < '0')
			error("\033[31mInvalid arguments\e[0m\n");
		i++;
	}
	return (content);
}

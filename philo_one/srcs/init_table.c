/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_base_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:59:11 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/28 16:49:05 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	init_table(char **args, t_table *table)
{
	int					i;
	pthread_mutex_t		*forks;
	struct timeval		tmp;

	table->num_of_philo = ft_atoi(args[1]);
	table->time_to_die = ft_atoi(args[2]);
	table->time_to_eat = ft_atoi(args[3]);
	table->time_to_sleep = ft_atoi(args[4]);
	if (args[5])
		table->philo_must_eat = ft_atoi(args[5]);
	else
		table->philo_must_eat = -1;
	i = -1;
	forks = (pthread_mutex_t *)malloc(sizeof(*forks) * table->num_of_philo);
	while (++i < table->num_of_philo)
		pthread_mutex_init(&(forks[i]), NULL);
	pthread_mutex_init(&table->output, NULL);
	pthread_mutex_init(&table->dead_lock, NULL);
	pthread_mutex_init(&table->time_lock, NULL);
	table->death = 0;
	table->is_first_death = 0;
	table->forks = forks;
	gettimeofday(&tmp, NULL);
	table->start_time = transform_time(tmp);
}

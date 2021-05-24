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

#include "philo_three.h"

void	init_table(char **args, t_table *table)
{
	struct timeval		tmp;

	sem_unlink("output");
	sem_unlink("time_lock");
	sem_unlink("dead_lock");
	sem_unlink("forks");
	sem_unlink("steward");
	table->num_of_philo = ft_atoi(args[1]);
	table->time_to_die = ft_atoi(args[2]);
	table->time_to_eat = ft_atoi(args[3]);
	table->time_to_sleep = ft_atoi(args[4]);
	if (args[5])
		table->philo_must_eat = ft_atoi(args[5]);
	else
		table->philo_must_eat = -1;
	table->output = sem_open("output", O_CREAT, 0644, 1);
	table->time_lock = sem_open("time_lock", O_CREAT, 0644, 1);
	table->dead_lock = sem_open("dead_lock", O_CREAT, 0644, 1);
	table->forks = sem_open("forks", O_CREAT, 0644, table->num_of_philo);
	table->steward = sem_open("steward", O_CREAT, 0644, 1);
	table->death = 0;
	table->is_first_death = 0;
	gettimeofday(&tmp, NULL);
	table->start_time = transform_time(tmp);
}

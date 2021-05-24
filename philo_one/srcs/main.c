/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:14:35 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/22 13:14:37 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long			transform_time(struct timeval time)
{
	return (1000 * time.tv_sec + time.tv_usec * 0.001);
}

void			*someone_died(void *args)
{
	t_all			*all;
	struct timeval	time;

	all = (t_all *)(args);
	gettimeofday(&time, NULL);
	while (all->philo->table->time_to_die >=
		(transform_time(time) - all->philo->last_eat))
	{
		pthread_mutex_lock(&all->philo->table->time_lock);
		gettimeofday(&time, NULL);
		pthread_mutex_unlock(&all->philo->table->time_lock);
	}
	pthread_mutex_lock(&all->philo->table->dead_lock);
	if (all->philo->table->philo_must_eat ==
		all->philo->eats)
	{
		all->philo->table->death = 1;
		pthread_mutex_unlock(&all->philo->table->dead_lock);
		return (NULL);
	}
	if (all->philo->table->philo_must_eat < 0)
		all->philo->table->death = 1;
	print_dead_message(all->philo, "\033[31m is dead\033[39m\n");
	pthread_mutex_unlock(&all->philo->table->dead_lock);
	return (NULL);
}

void			*philos_life(void *args)
{
	t_all			*all;
	pthread_t		dead;
	struct timeval	tmp;

	all = (t_all *)(args);
	pthread_create(&dead, NULL, someone_died, all);
	while (!all->philo->table->death)
	{
		take_fork(all);
		gettimeofday(&tmp, NULL);
		all->philo->last_eat = transform_time(tmp);
		print_message(all->philo, "\033[32m is eating\033[39m\n");
		all->philo->eats += 1;
		ft_usleep(all->philo->table->time_to_eat);
		put_fork(all);
		if (all->philo->eats == all->philo->table->philo_must_eat)
			break ;
		print_message(all->philo, "\033[35m is sleeping\033[39m\n");
		ft_usleep(all->philo->table->time_to_sleep);
		print_message(all->philo, "\033[36m is thinking\033[39m\n");
	}
	pthread_join(dead, NULL);
	return (NULL);
}

static void		clear_all(t_table *table, t_philo **philos, t_all **all)
{
	pthread_mutex_destroy(&table->output);
	pthread_mutex_destroy(&table->dead_lock);
	pthread_mutex_destroy(&table->time_lock);
	free(*philos);
	free(*all);
	free(table->forks);
}

int				main(int argc, char *argv[])
{
	t_table				table;
	t_philo				*philos;
	t_all				*all;
	int					i;
	pthread_t			threads[ft_atoi(argv[1])];

	if (check_args(argc, argv))
		return (1);
	init_table(argv, &table);
	philos = init_philos(&table);
	if (!(all = (t_all *)malloc(sizeof(*all) * table.num_of_philo)))
		return (1);
	table.death = 0;
	i = -1;
	while (++i < table.num_of_philo)
		all[i].philo = &philos[i];
	i = -1;
	while (++i < table.num_of_philo)
		pthread_create(&threads[i], NULL, philos_life, &all[i]);
	i = -1;
	while (++i < table.num_of_philo)
		pthread_join(threads[i], NULL);
	clear_all(&table, &philos, &all);
	return (0);
}

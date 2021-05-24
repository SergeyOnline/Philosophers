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

#include "philo_three.h"

void			*someone_died(void *phil)
{
	t_philo			*philo;
	struct timeval	time;

	philo = (t_philo *)(phil);
	gettimeofday(&time, NULL);
	while (philo->table->time_to_die >=
		(transform_time(time) - philo->last_eat))
	{
		sem_wait(philo->table->time_lock);
		gettimeofday(&time, NULL);
		sem_post(philo->table->time_lock);
	}
	sem_wait(philo->table->dead_lock);
	if (philo->table->philo_must_eat == philo->eats)
	{
		philo->table->death = 1;
		sem_post(philo->table->dead_lock);
		return (NULL);
	}
	if (philo->table->philo_must_eat < 0)
		philo->table->death = 1;
	print_dead_message(philo, "\033[31m is dead\033[39m\n");
	exit(1);
	return (NULL);
}

void			philos_life(t_philo *philo)
{
	pthread_t		dead;
	struct timeval	tmp;

	pthread_create(&dead, NULL, someone_died, philo);
	while (!philo->table->death)
	{
		take_fork(philo);
		gettimeofday(&tmp, NULL);
		philo->last_eat = transform_time(tmp);
		print_message(philo, "\033[32m is eating\033[39m\n");
		philo->eats += 1;
		ft_usleep(philo->table->time_to_eat);
		put_fork(philo);
		if (philo->eats == philo->table->philo_must_eat)
			break ;
		print_message(philo, "\033[35m is sleeping\033[39m\n");
		ft_usleep(philo->table->time_to_sleep);
		print_message(philo, "\033[36m is thinking\033[39m\n");
	}
	pthread_join(dead, NULL);
}

static void		clear_all(t_table *table, t_philo **philos)
{
	sem_post(table->output);
	sem_post(table->dead_lock);
	sem_close(table->output);
	sem_close(table->dead_lock);
	sem_close(table->time_lock);
	sem_close(table->forks);
	free(*philos);
}

int				main(int argc, char *argv[])
{
	t_table		table;
	t_philo		*philos;
	int			i;
	pid_t		pids[ft_atoi(argv[1])];

	if (check_args(argc, argv))
		return (1);
	init_table(argv, &table);
	philos = init_philos(&table);
	i = -1;
	while (++i < table.num_of_philo)
		if ((pids[i] = fork()) == -1)
		{
			while (i >= 0)
				kill(pids[--i], SIGKILL);
			clear_all(&table, &philos);
			return (1);
		}
		else if (pids[i] == 0)
			philos_life(&philos[i]);
	waitpid(-1, 0, 0);
	while (--i > -1)
		kill(pids[i], SIGKILL);
	clear_all(&table, &philos);
	return (0);
}

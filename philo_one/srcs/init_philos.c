/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_ring.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:36:58 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/28 16:51:00 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void		fill_philo(int *i, t_philo **philos, t_table *table)
{
	if (*i % 2 == 0)
	{
		(*philos)[(*i)].l_fork = *i + 1;
		(*philos)[(*i)].r_fork = *i;
	}
	else
	{
		(*philos)[(*i)].l_fork = *i;
		(*philos)[(*i)].r_fork = *i + 1;
	}
	(*philos)[(*i)].identifier = *i;
	(*philos)[(*i)].eats = 0;
	(*philos)[(*i)].last_eat = table->start_time;
	(*philos)[(*i)].table = table;
	*i += 1;
}

t_philo			*init_philos(t_table *table)
{
	t_philo			*philos;
	int				i;

	philos = (t_philo *)malloc(sizeof(*philos) * table->num_of_philo);
	i = 0;
	while (i < table->num_of_philo - 1)
		fill_philo(&i, &philos, table);
	philos[i].identifier = i;
	philos[i].eats = 0;
	philos[i].last_eat = table->start_time;
	philos[i].table = table;
	philos[i].l_fork = i;
	philos[i].r_fork = 0;
	return (philos);
}

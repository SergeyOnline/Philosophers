/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:57:39 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/28 18:58:15 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	take_fork(t_all *all)
{
	sem_wait(all->philo->table->steward);
	sem_wait(all->philo->table->forks);
	print_message(all->philo, "\033[33m taken a fork\033[39m\n");
	sem_wait(all->philo->table->forks);
	print_message(all->philo, "\033[33m taken a fork\033[39m\n");
	sem_post(all->philo->table->steward);
}

void	put_fork(t_all *all)
{
	sem_post(all->philo->table->forks);
	sem_post(all->philo->table->forks);
}

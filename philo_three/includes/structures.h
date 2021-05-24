/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:20:24 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/28 19:02:51 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct				s_table
{
	long					start_time;
	int						num_of_philo;
	long					time_to_die;
	long					time_to_eat;
	long					time_to_sleep;
	int						philo_must_eat;
	int						death;
	int						is_first_death;
	sem_t					*output;
	sem_t					*dead_lock;
	sem_t					*time_lock;
	sem_t					*forks;
	sem_t					*steward;
}							t_table;

typedef struct				s_philo
{
	unsigned int			identifier;
	long					last_eat;
	int						eats;
	t_table					*table;
}							t_philo;

#endif

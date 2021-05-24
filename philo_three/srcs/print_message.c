/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:07:54 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/28 19:08:13 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void		ft_write(char *str)
{
	int	strlen;

	strlen = ft_strlen(str);
	write(1, str, strlen);
}

void			print_message(t_philo *philo, char *msg)
{
	char			*str;
	char			*tmp;
	char			*tmp2;
	struct timeval	event;

	str = ft_strdup(" ");
	tmp2 = ft_itoa(philo->identifier + 1);
	tmp = str;
	str = ft_strjoin(str, tmp2);
	free(tmp);
	free(tmp2);
	tmp = str;
	str = ft_strjoin(str, msg);
	free(tmp);
	tmp = str;
	gettimeofday(&event, NULL);
	tmp2 = ft_itoa((int)(transform_time(event) - philo->table->start_time));
	str = ft_strjoin(tmp2, str);
	free(tmp);
	free(tmp2);
	sem_wait(philo->table->output);
	if (!philo->table->death)
		ft_write(str);
	free(str);
	sem_post(philo->table->output);
}

static void		ft_death_write(t_philo *philo, char *str)
{
	int	strlen;

	strlen = ft_strlen(str);
	sem_wait(philo->table->output);
	write(1, str, strlen);
	philo->table->is_first_death = 1;
}

void			print_dead_message(t_philo *philo, char *msg)
{
	char			*str;
	char			*tmp;
	char			*tmp2;
	struct timeval	event;

	if (philo->table->is_first_death)
		return ;
	str = ft_strdup(" ");
	tmp2 = ft_itoa(philo->identifier + 1);
	tmp = str;
	str = ft_strjoin(str, tmp2);
	free(tmp);
	free(tmp2);
	tmp = str;
	str = ft_strjoin(str, msg);
	free(tmp);
	tmp = str;
	gettimeofday(&event, NULL);
	tmp2 = ft_itoa((int)(transform_time(event) - philo->table->start_time));
	str = ft_strjoin(tmp2, str);
	free(tmp2);
	free(tmp);
	ft_death_write(philo, str);
	free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:16:36 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/22 13:16:38 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include "structures.h"

int						ft_strlen(char *str);
char					*ft_strjoin_char(char *str, char c);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_itoa(int n);
int						ft_isdigit(int c);
int						ft_is_all_digit_in_str(char *str);
int						check_args(int argc, char **argv);
int						ft_atoi(const char *str);
void					init_table(char **args, t_table *base);
void					ft_usleep(long u_time);
char					*ft_strdup(const char *s1);
t_philo					*init_philos(t_table *base);
void					take_fork(t_all *all);
void					put_fork(t_all *all);
void					print_message(t_philo *philo, char *msg);
void					print_dead_message(t_philo *philo, char *msg);
long					transform_time(struct timeval time);

#endif

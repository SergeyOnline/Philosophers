/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:42:35 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/11/28 16:52:37 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_char(char *str, char c)
{
	char	*result;
	int		i;

	if (!str)
		return (NULL);
	if (!(result = (char *)malloc(sizeof(char) * ((ft_strlen(str)) + 2))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	result[i++] = c;
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		index;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return ((s1 == NULL) ? (char *)s2 : (char *)s1);
	index = 0;
	len = ft_strlen((char *)s1);
	len += ft_strlen((char *)s2);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
		str[index++] = s1[i++];
	i = 0;
	while (s2[i])
		str[index++] = s2[i++];
	str[index] = '\0';
	return (str);
}

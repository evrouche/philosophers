/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by edessain          #+#    #+#             */
/*   Updated: 2021/03/02 15:02:28 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

void	print_str(t_data *two, int phi, char *mess)
{
	char	*time;
	char	*philo;
	char	*str;

	sem_wait(two->sem_global);
	time = ft_itoa((int)get_time(two));
	philo = ft_itoa(phi);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo);
	str = ft_strjoin_free_all(str, mess);
	write(1, str, ft_strlen(str));
	free(str);
	sem_post(two->sem_global);
}

void	print_str_eat(t_data *two, int i)
{
	char	*philo;
	char	*time;
	char	*str;
	char	*mess;

	sem_wait(two->sem_global);
	time = ft_itoa((int)(get_time(two)));
	mess = ft_strdup(" is eating\n");
	philo = ft_itoa(i);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo);
	str = ft_strjoin_free_all(str, mess);
	write(1, str, ft_strlen(str));
	two->count_eat[i - 1]++;
	free(str);
	sem_post(two->sem_global);
}

void	print_str_dead(t_data *two, int i, long int diff)
{
	char	*philo;
	char	*time;
	char	*str;
	char	*mess;

	sem_wait(two->sem_global);
	mess = ft_strdup(" died\n");
	philo = ft_itoa(i);
	time = ft_itoa((int)diff);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo);
	str = ft_strjoin_free_all(str, mess);
	write(1, str, ft_strlen(str));
	free(str);
	sem_post(two->sem_dead);
}

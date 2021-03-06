/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edessain <edessain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 09:16:31 by edessain          #+#    #+#             */
/*   Updated: 2021/02/23 19:49:25 by edessain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_data
{
	int			nbr_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_of_time_each_philo_must_eat;
	long int	t_start;
	int			*count_eat;
	int			*has_eat;
	int			*iter;
	pthread_t	*thread;
	pthread_t	thread_time;
	sem_t		*sem_forks;
	sem_t		*sem_global;
	sem_t		*sem_dead;
	long int	*last_eat;
	int			status;
}				t_data;

/*
*** Philo_two and main
*/

void			*routine(void *arg);
void			*routine_time(void *arg);
t_data			*get_struct(void);
int				eating(t_data *two, int i);
int				sleeping(t_data *two, int i);
int				thinking(t_data *two, int i);

/*
*** Utils
*/

int				check_count_eat(void);
int				only_digit(char *str);
int				parse_values(t_data *two, int argc, char **argv);
int				complete_values(t_data *two);
long			get_time(t_data *two);
void			ft_sleep(t_data *two, int time);
int				check_time(t_data *two);

/*
*** Print
*/

void			print_str_dead(t_data *two, int i, long int diff);
void			print_str_eat(t_data *two, int i);
void			print_str(t_data *two, int phi, char *mess);

/*
*** Errors, init and free
*/

int				error_arg(int argc, char **argv);
int				init_struct(t_data *two);
int				free_all(t_data *two);

/*
*** Libft
*/

long long		ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_strjoin_free_all(char *s1, char *s2);

#endif

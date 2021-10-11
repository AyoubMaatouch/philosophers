/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:13:48 by aymaatou          #+#    #+#             */
/*   Updated: 2021/10/11 19:13:49 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	task_divider(int id, char *task, t_philo *philo)
{
	pthread_mutex_lock(philo->t_info->print);
	printf("%ld %d %s\n", (get_time() / 1000), id, task);
	pthread_mutex_unlock(philo->t_info->print);
}

void	philo_reaper(t_philo *philo)
{
	int		i;
	t_philo	*d_philo;

	d_philo = philo;
	while (TRUE)
	{
		i = 0;
		while (i < philo->t_info->num_philo)
		{
			if ((get_time() - d_philo->eat) >= philo->t_info->time_to_die)
				death_philo(d_philo, d_philo->id_philo, "\e[0;31mdied\033[0m");
			d_philo = d_philo->next;
			i++;
		}
	}
}

void	*task_manager(t_philo *philo)
{
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;

	lfork = philo->philo_mutex;
	rfork = philo->next->philo_mutex;
	while (TRUE)
	{
		pthread_mutex_lock(lfork);
		task_divider(philo->id_philo, "\e[0;32mhas taken a fork\033[0m", philo);
		pthread_mutex_lock(rfork);
		task_divider(philo->id_philo, "\e[0;32mhas taken a fork\033[0m", philo);
		philo->eat = get_time();
		task_divider(philo->id_philo, "\e[0;33mis eating\033[0m", philo);
		ft_usleep(philo->t_info->time_to_eat);
		pthread_mutex_unlock(lfork);
		pthread_mutex_unlock(rfork);
		task_divider(philo->id_philo, "\e[0;34mis sleeping\033[0m", philo);
		ft_usleep(philo->t_info->time_to_sleep);
		task_divider(philo->id_philo, "\e[0;35mis thinking\033[0m", philo);
		if (philo->t_info->num_of_eats > 0
			&& ++philo->ate == philo->t_info->num_of_eats)
			break ;
	}
	exit(EXIT_SUCCESS);
}

void	philo_exec(t_philo *philo)
{
	int		i;
	t_philo	*f_philo;

	f_philo = philo;
	i = 0;
	while (i < philo->t_info->num_philo)
	{
		f_philo->eat = get_time();
		pthread_create(f_philo->philo_thread, NULL,
			(void *)task_manager, f_philo);
		usleep(100);
		f_philo = f_philo->next;
		i++;
	}
	philo_reaper(philo);
}

int	main(int ac, char **av)
{
	t_info	*info;
	t_philo	*philo;

	if (ac == 5 || ac == 6)
	{
		info = malloc(sizeof(t_info));
		if (!check_ar(av))
			return (ft_error("invalid arguments\n"));
		philo = init_philo(av, info);
		philo_exec(philo);
	}
	else
		return (ft_error("invalid arguments\n"));
	return (EXIT_SUCCESS);
}

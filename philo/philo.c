#include "philo.h"

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

void	task_divider(int id, char *task, t_philo *philo)
{
	pthread_mutex_lock(philo->t_info->print);
	printf("%ld %d %s\n",(get_time()) / 1000, id, task);
	pthread_mutex_unlock(philo->t_info->print);
}

void	philo_reaper(t_philo *philo)
{
	t_philo	*d_philo;
	int i;

	d_philo = philo;
	while (TRUE)
	{
		i = 0;
		while (i < philo->t_info->num_philo)
		{
			if ((get_time() - d_philo->eat) >= philo->t_info->time_to_die)
				death_philo(d_philo, d_philo->id_philo, "died");

			d_philo = d_philo->next;
			i++;
		}
	}
}

void *task_manager(t_philo *philo)
{
	pthread_mutex_t *lfork;
	pthread_mutex_t *rfork;

	lfork = philo->philo_mutex;
	rfork = philo->next->philo_mutex;
	while (TRUE)
	{
		pthread_mutex_lock(lfork);
		task_divider(philo->id_philo, "\e[0;31mhas taken a fork\033[0m", philo);
		pthread_mutex_lock(rfork);
		task_divider(philo->id_philo, "\e[0;31mhas taken a fork\033[0m", philo); 
		task_divider(philo->id_philo, "\e[0;32mis eating\033[0m", philo);
		ft_usleep(philo->t_info->time_to_eat);
		philo->eat = get_time();
		pthread_mutex_unlock(lfork);
		pthread_mutex_unlock(rfork);
		task_divider(philo->id_philo, "\e[0;33mis sleeping\033[0m", philo);
		ft_usleep(philo->t_info->time_to_sleep);
		task_divider(philo->id_philo, "\e[0;34mis thinking\033[0m", philo);
	}
}

void	philo_exec(t_philo *philo)
{
		int i;
		t_philo *f_philo;

		f_philo = philo;
		i = 0;
		while (i < philo->t_info->num_philo)
		{
			f_philo->eat = get_time();
			pthread_create(f_philo->philo_thread, NULL, (void *)task_manager, f_philo);
			usleep(100);
			f_philo = f_philo->next;
			i++;
		}
		philo_reaper(philo);
		// i = 0;
		// f_philo = philo;
		// while (i < philo->t_info->num_philo)
		// {
		// 	pthread_join(*f_philo->philo_thread, NULL);
		// 	f_philo = f_philo->next;
		// 	i++;
		// }

}

int main(int ac, char **av)
{
	
	if (ac == 5 || ac == 6)
	{
		t_info *info;
		t_philo *philo;
		int i;

		i = 0;
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
#include "philo.h"

void *task_manager(t_philo *philo)
{
	pthread_mutex_t *lfork = philo->philo_mutex;
	pthread_mutex_t *rfork = philo->next->philo_mutex;

	while (TRUE)
	{
		pthread_mutex_lock(lfork );
		printf("%ld %d has taken a fork\n", get_time() / 1000, philo->id_philo);
		pthread_mutex_lock(rfork);
		printf("%ld %d has taken a fork\n", get_time() / 1000, philo->id_philo);
		printf("%ld %d is eating\n", get_time() / 1000, philo->id_philo);
		usleep(100);
		pthread_mutex_unlock(lfork);
		pthread_mutex_unlock(rfork);

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
			pthread_create(f_philo->philo_thread, NULL, (void *)task_manager, f_philo);
			usleep(100);
			f_philo = f_philo->next;
			i++;
		}
		i = 0;
		f_philo = philo;
		while (i < philo->t_info->num_philo)
		{
			pthread_join(*f_philo->philo_thread, NULL);
			f_philo = f_philo->next;
			i++;
		}

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
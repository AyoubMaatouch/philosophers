#include "philo.h"

void *task_manager(t_philo_info *info_philo )
{
	int i = 0;
	// {
		i = pthread_mutex_lock(info_philo->count_mutex);
		i = pthread_mutex_lock(info_philo->count_mutex + 1);
		// i = pthread_mutex_lock(info_philo->count_mutex + 2);
		printf("[%d]\n", i);
		printf("[%.2ld] Thread Created\n", get_time());
		pthread_mutex_unlock(info_philo->count_mutex);
		pthread_mutex_unlock(info_philo->count_mutex + 1);
		// pthread_mutex_unlock(info_philo->count_mutex + 2);
	
	// }
	// while (1);

	return 0;
}
void	philo_exec(t_philo_info *info_philo)
{
	int i;

	i = 0;

	while (i < info_philo->num_philo)
	{
		pthread_create(&info_philo->philo_thread[i], NULL, (void *)task_manager, (void*)info_philo);
		usleep(100);
		i++;
	}
	i = 0;

	while (i < info_philo->num_philo)
	{
		pthread_join(info_philo->philo_thread[i], NULL);
		i++;
	}
}

int main(int ac, char **av)
{
	
	if (ac == 5 || ac == 6)
	{
		t_philo_info *info_philo;
		/*
			to check if the fork is taken check mutex lock first then see if it is
			or not
		*/
		info_philo = malloc(sizeof(t_philo_info));
		if (!check_ar(av))
			return (ft_error("invalid arguments\n"));
		init_philo(av, info_philo);
		philo_exec(info_philo);
		free(info_philo);
	}
	else
		return (ft_error("invalid arguments\n"));
	return (EXIT_SUCCESS);
}
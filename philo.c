#include "philo.h"

void *task_manager(t_info *info )
{
	int i = 0;

		pthread_mutex_lock(info->count_mutex);
		pthread_mutex_lock(info->count_mutex + 1);
		// i = pthread_mutex_lock(info->count_mutex + 2);
		printf("[%d]\n", i);
		printf("[%.2ld] Thread Created\n", get_time());
		pthread_mutex_unlock(info->count_mutex);
		pthread_mutex_unlock(info->count_mutex + 1);

	return 0;
}
void	philo_exec(t_info *info)
{
	int i;

	i = 0;

	while (i < info->num_philo)
	{
		pthread_create(&info->philo_thread[i], NULL, (void *)task_manager, (void*)info);
		usleep(100);
		i++;
	}
	i = 0;

	while (i < info->num_philo)
	{
		pthread_join(info->philo_thread[i], NULL);
		i++;
	}
}

int main(int ac, char **av)
{
	
	if (ac == 5 || ac == 6)
	{
		t_info *info;
		t_philo **philo;
		/*
			to check if the fork is taken check mutex lock first then see if it is
			or not
		*/
		info = malloc(sizeof(t_info));
		if (!check_ar(av))
			return (ft_error("invalid arguments\n"));
		philo = init_philo(av, info);
		printf ("[%d][%d]\n", philo[0]->id_philo, philo[0]->t_info->num_philo);
		printf ("[%d][%d]\n", philo[1]->id_philo, philo[1]->t_info->num_philo);
		// philo_exec(info);
		free(info);
	}
	else
		return (ft_error("invalid arguments\n"));
	return (EXIT_SUCCESS);
}
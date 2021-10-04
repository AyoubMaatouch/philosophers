#include "philo.h"

void	task_divider(int id, char *task, t_philo *philo)
{
	pthread_mutex_lock(philo->t_info->print);
	if (ft_strncmp(task, "is eat", 5) == 0)
		{
			printf("%ld %d %s\n",(get_time() / 1000 - philo->eat), id, task);
			philo->eat = get_time() / 1000;
		}
	else
		printf("%ld %d %s\n",(get_time()) / 1000, id, task);
	pthread_mutex_unlock(philo->t_info->print);
}

void *task_manager(t_philo *philo)
{
	pthread_mutex_t *lfork;
	pthread_mutex_t *rfork;

	lfork = philo->philo_mutex;
	rfork = philo->next->philo_mutex;
	while (TRUE)
	{
		pthread_mutex_lock(lfork );
		task_divider(philo->id_philo, "has taken a fork", philo);
		pthread_mutex_lock(rfork);
		task_divider(philo->id_philo, "has taken a fork", philo); 
		task_divider(philo->id_philo, "is eating", philo);
		usleep(philo->t_info->time_to_eat);
		pthread_mutex_unlock(lfork);
		pthread_mutex_unlock(rfork);
		task_divider(philo->id_philo, "is sleeping", philo);
		usleep(philo->t_info->time_to_sleep);
		task_divider(philo->id_philo, "is thinking", philo);
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
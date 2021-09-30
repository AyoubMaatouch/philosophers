#include "philo.h"

pthread_mutex_t count_mutex;

void *print_info()
{
	int i = 0;
	while (i++ < 1000000)
	{
		pthread_mutex_lock(&count_mutex);

		pthread_mutex_unlock(&count_mutex);
	}

	return NULL;
}

int main(int ac, char **av)
{
	
	if (ac == 5 || ac == 6)
	{
		t_philo_info *info_philo;

		info_philo = malloc(sizeof(t_philo_info));
		if (!check_ar(av))
			return (ft_error("invalid arguments\n"));
		init_philo(av, info_philo);
		free(info_philo);
	}
	else
		return (ft_error("invalid arguments\n"));
	return (EXIT_SUCCESS);
}
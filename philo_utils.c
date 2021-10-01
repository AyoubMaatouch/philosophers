#include "philo.h"

long get_time(void)
{
  struct timeval time;

  gettimeofday(&time, NULL);
  return (time.tv_usec + (time.tv_sec * 1000000));
}

int is_num(char *ar)
{
	int i;

	i = 0;
	while (ar[i])
	{   
		if (ft_isdigit(ar[i++]) == 0)
			return(0);
	}
	return(1);
}

int check_ar(char **ar)
{
	int i;

	i = 1;
	while (ar[i] != NULL)
			if (!(is_num(ar[i++])))
			  return (0);
	return (1);
}

int 	ft_error(char *err_msg)
{
	ft_putstr_fd(err_msg, 2);
	exit(1);
}

t_philo	**init_philo(char **av, t_info *info)
{
	int i;
	t_philo **philo;

	i = 0;
	info->num_philo = ft_atoi(av[1]);
    info->time_to_die = ft_atoi(av[2]) * 1000;
    info->time_to_eat = ft_atoi(av[3]) * 1000;
    info->time_to_sleep = ft_atoi(av[4]) * 1000;
    if (av[5])
		info->num_of_eats = ft_atoi(av[5]);
	else
		info->num_of_eats = 0;
	info->philo_thread = malloc (sizeof(pthread_t) * (info->num_philo));
	info->count_mutex = malloc (sizeof(pthread_mutex_t) * (info->num_philo));
	while (info->num_philo > i)
		pthread_mutex_init(info->count_mutex + (i++), NULL);
	philo = malloc (sizeof(t_philo) * (info->num_philo));
	i = 0;
	while (i < info->num_philo)
	{
		philo[i]->id_philo = i + 1;
		philo[i]->t_info = info;
		i++;
	}
	return 
}

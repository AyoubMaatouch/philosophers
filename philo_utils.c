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

void	init_philo(char **av, t_philo_info *info_philo)
{
	int i;

	i = 0;
	info_philo->num_philo = ft_atoi(av[1]);
    info_philo->time_to_die = ft_atoi(av[2]);
    info_philo->time_to_eat = ft_atoi(av[3]);
    info_philo->time_to_sleep = ft_atoi(av[4]);
    if (av[5])
		info_philo->num_of_eats = ft_atoi(av[5]);
	info_philo->philo_thread = malloc (sizeof(pthread_t) * (info_philo->num_philo));
	info_philo->count_mutex = malloc (sizeof(pthread_mutex_t) * (info_philo->num_philo));
	while (info_philo->num_philo > i)
		pthread_mutex_init(info_philo->count_mutex + (i++), NULL);

}

#include "../includes/philo.h"

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

t_philo	*init_philo_data(t_info *info)
{
	int i;
	t_philo *philo;
	t_philo *first_philo;
	
	i = 0;
	philo = malloc (sizeof(t_philo));
	first_philo = philo;
	while (i < info->num_philo)
	{
		philo->philo_thread = malloc (sizeof(pthread_t));
		philo->philo_mutex = malloc (sizeof(pthread_mutex_t));
		pthread_mutex_init(philo->philo_mutex , NULL);
		philo->id_philo = i + 1;
		philo->t_info = info;
		philo->eat = 0;
		philo->think = 0;
		if (i != info->num_philo - 1)
		{
			philo->next = malloc (sizeof(t_philo));
			philo = philo->next;
		}
		i++;
	}
	philo->next = philo->next = malloc (sizeof(t_philo));
	philo->next = first_philo;
	philo->t_info->dies = malloc (sizeof(pthread_mutex_t));
	pthread_mutex_init(philo->t_info->dies, NULL);
	return (first_philo);
}

t_philo	*init_philo(char **av, t_info *info)
{
	int i;

	i = 0;
	info->num_philo = ft_atoi(av[1]);
    info->time_to_die = (long long)ft_atoi(av[2]) * 1000;
    info->time_to_eat = (long long)ft_atoi(av[3]) * 1000;
    info->time_to_sleep = (long long)ft_atoi(av[4]) * 1000;
    if (av[5])
		{
 			info->exec_eat = 0;
			info->num_of_eats =  ft_atoi(av[5]);
		}
	else
		info->num_of_eats = 0;
	info->print = malloc (sizeof(pthread_mutex_t));
	return (init_philo_data(info));
}


void	death_philo (t_philo *philo, int id, char *task)
{
	pthread_mutex_lock(philo->t_info->dies);
	printf("%ld %d %s\n",(get_time()) / 1000, id, task);
	exit(EXIT_FAILURE);
}
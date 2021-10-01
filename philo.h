#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

#include <errno.h>

int mail;
typedef struct s_philo_info {
	int num_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_of_eats;
	pthread_t *philo_thread;
	pthread_mutex_t *count_mutex;

} t_philo_info;
long    get_time(void);
int     check_ar(char **ar);
void	init_philo(char **av, t_philo_info *info_philo);
int 	ft_error(char *err_msg);
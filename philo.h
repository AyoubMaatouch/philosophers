#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <errno.h>


typedef struct s_info {
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eats;
	pthread_t		*philo_thread;
	pthread_mutex_t	*count_mutex;

}	t_info;

typedef	struct s_philo {
	t_info			*t_info;
	int				id_philo;
	// struct s_philo	*next;
}	t_philo;

long    get_time(void);
int     check_ar(char **ar);
t_philo	**init_philo(char **av, t_info *info);
int 	ft_error(char *err_msg);
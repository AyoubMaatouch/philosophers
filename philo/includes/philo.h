#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <errno.h>

# define TRUE 1

typedef struct s_info {
	int				num_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				num_of_eats;
	int				exec_eat;
	pthread_mutex_t	*print;
	pthread_mutex_t	*dies;

}	t_info;

typedef struct s_philo {
	t_info			*t_info;
	long long		eat;
	long long		think;
	pthread_t		*philo_thread;
	pthread_mutex_t	*philo_mutex;
	int				id_philo;
	struct s_philo	*next;

}	t_philo;

long	get_time(void);
int		check_ar(char **ar);
t_philo	*init_philo(char **av, t_info *info);
int		ft_error(char *err_msg);
void	death_philo(t_philo *philo, int id, char *task);
int		ft_atoi(const char *str);
int		ft_isdigit(int str);
void	ft_putstr_fd(char *s, int fd);
#endif // PHILO_H

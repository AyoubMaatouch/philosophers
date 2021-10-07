#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <errno.h>

#define TRUE	1
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"

typedef struct s_info {
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eats;
	// pthread_t		*philo_thread;
	pthread_mutex_t	*print;
	pthread_mutex_t	*dies;

}	t_info;

typedef	struct s_philo {
	t_info			*t_info;
	long			eat;
	long			think;
	pthread_t		*philo_thread;
	pthread_mutex_t	*philo_mutex;
	int				id_philo;
	struct s_philo	*next;

}	t_philo;

long    get_time(void);
int     check_ar(char **ar);
t_philo	*init_philo(char **av, t_info *info);
int 	ft_error(char *err_msg);
void	death_philo (t_philo *philo, int id, char *task);
int		ft_atoi(const char *str);
int		ft_isdigit(int str);
void	ft_putstr_fd(char *s, int fd);
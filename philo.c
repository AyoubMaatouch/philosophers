#include "philo.h"

pthread_mutex_t count_mutex;

void *print_info()
{
	// time_t t;
	// struct tm *info;
	// char buffer[64];

	// struct timeval current_time;
	// gettimeofday(&current_time, NULL);
	// t = current_time.tv_sec;
	// info = localtime(&t);
	// strftime (buffer, sizeof buffer, "The time is %I:%M:%S %p.\n", info);
	// printf("%s",buffer);
	// while (1)
	// write (1 ,"here", 5);

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
	if (!check_ar(av))
		return 1;
	//     pthread_t p1, p2, p3, p4;
	//     pthread_mutex_init(&count_mutex, NULL);
	//     pthread_create(&p1, NULL, print_info, NULL);
	//     pthread_create(&p2, NULL, &print_info, NULL);
	//     pthread_join(p2, NULL);
	//     pthread_join(p1, NULL);
	//     printf ("mail %d", mail);
	//     pthread_mutex_destroy(&count_mutex);

	return 0;
}
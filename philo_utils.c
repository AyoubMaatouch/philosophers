#include "philo.h"

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

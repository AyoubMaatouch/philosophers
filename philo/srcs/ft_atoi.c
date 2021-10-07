#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/philo.h"

int	ft_atoi_be(const char *str)
{
	long		i;
	long		number;
	int			sign;
	int			l_counter;

	l_counter = 0;
	sign = 1;
	i = 0;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] != '\0')
	{
		if (l_counter > 13 && sign == -1)
			return (0);
		if (l_counter++ > 13 && sign == 1)
			return (-1);
		if (!(str[i] >= 48 && str[i] <= 57))
			return (number * sign);
		number = number * 10 + (str[i++] - 48);
	}
	return (number * sign);
}

int	ft_atoi(const char *str)
{
	int	value;

	value = ft_atoi_be(str);
	if (value <= 0)
		return (ft_error("invalid arguments\n"));
	return (value);
}

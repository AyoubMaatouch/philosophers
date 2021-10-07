#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
void	ft_check(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		{
			write (2, "Error\n", 6);
			exit(1);
		}
}

int	ft_atoi(const char *str)
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
	ft_check(number * sign);
	return (number * sign);
}

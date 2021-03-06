/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:48:47 by aymaatou          #+#    #+#             */
/*   Updated: 2021/10/11 19:12:37 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int str)
{
	if (str >= 48 && str <= 57)
	{
		return (1);
	}
	return (0);
}

int	is_num(char *ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		if (ft_isdigit(ar[i++]) == 0)
			return (0);
	}
	return (1);
}

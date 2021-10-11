/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:13:56 by aymaatou          #+#    #+#             */
/*   Updated: 2021/10/11 19:14:19 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_usleep(long int time)
{
	long long	r;
	long long	mic;

	mic = get_time();
	r = time - 1000;
	usleep(r);
	while ((get_time() - mic) <= (time))
		;
}

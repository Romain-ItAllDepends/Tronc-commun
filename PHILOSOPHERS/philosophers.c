/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:09:09 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/14 17:02:39 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	int	nb_t = ft_atoi(av[1]);
	pthread_t	threads[nb_t];

	(void)ac;
	(void)av;
	(void)threads;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:42:50 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/25 14:25:07 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_mult_prime(unsigned int n)
{
	unsigned int	i;

	i = 2;
	while (n > 1)
	{
		if (n % i == 0)
		{
			printf("%d", i);
			n = n / i;
			i--;
			if (n > 1)
				printf("x");
		}
		
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_mult_prime(atoi(av[1]));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:49:15 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/25 15:32:38 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_fprime()
{
	int	i;
	int	j;

	i = 2;
	j = 2;
	while (i <= 1000)
	{
		while (j <= 1000)
		{
			if (i % j == 0 && j == i)
				printf("%d ", i);
			else if (i % j == 0)
				break ;
			j++;
		}
		j = 2;
		i++;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 2)
		ft_fprime();
	return (0);
}

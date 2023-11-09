/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:45:12 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/03 16:55:34 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int *n, int *sg)
{
	int	i;
	int	temp;

	i = 0;
	temp = *n;
	if (*n == 0)
		return (1);
	if (*n < 0)
	{
		*n *= -1;
		*sg = 1;
		temp *= -1;
		i++;
	}
	while (temp > 0)
	{
		i++;
		temp /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		i;
	int		sg;

	sg = 0;
	i = ft_intlen(&n, &sg);
	tab = ft_calloc(sizeof(char), (i-- + 1));
	if (tab == 0)
		return (0);
	if (n == -2147483648)
	{
		free(tab);
		tab = ft_strdup("-2147483648");
		return (tab);
	}
	while (n > 9)
	{
		tab[i--] = (n % 10) + '0';
		n /= 10;
	}
	tab[i] = n + '0';
	if (sg == 1)
		tab[0] = '-';
	return (tab);
}

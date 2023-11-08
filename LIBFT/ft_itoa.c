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

static int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*reverse(char *str)
{
	char	temp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen1(str) - 1;
	if (str[i] == '-')
		i++;
	while (i <= (len / 2))
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	
	return (str);
}

static int	ft_intlen(int *n, int *sg)
{
	int	i;
	int	temp;

	i = 0;
	temp = *n;
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
	int		len;
	int		sg;

	i = 0;
	len = ft_intlen(&n, &sg);
	tab = ft_calloc(sizeof(char), (len + 1));
	if (tab == 0)
		return (0);
	if (n == -2147483648)
	{
		tab = ft_strdup("-2147483648");
		return (tab);
	}
	while (n > 9)
	{
		tab[i--] = n % 10 + '0';
		n /= 10;
	}
	tab[i - 1] = n + '0';
	if (sg == 1)
		tab[0] = '-';
	return (reverse(tab));
}

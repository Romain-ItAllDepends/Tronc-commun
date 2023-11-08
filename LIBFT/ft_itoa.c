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

static int	ft_intlen(int n)
{
	int	i;

	i = -1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		i;

	i = 0;
	if (n < 0)
		tab = ft_calloc(sizeof(char), (ft_intlen(n) + 2));
	else
		tab = ft_calloc(sizeof(char), (ft_intlen(n) + 1));
	if (tab == 0)
		return (0);
	if (n == -2147483648)
	{
		tab = ft_strdup("-2147483648");
		return (tab);
	}
	if (n < 0)
	{
		tab[i] = '-';
		n *= -1;
		i++;
	}
	while (i <= ft_intlen(n))
	{
		tab[i++] = n % 10 + '0';
		n /= 10;
	}
	return (reverse(tab));
}

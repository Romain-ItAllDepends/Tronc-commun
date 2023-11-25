/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:34:35 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/25 16:40:34 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_gap(int start, int end)
{
	int	i;

	i = start;
	if (start > end && (start < 0 && end < 0))
		while (i > end)
			i--;
	else
	{
		while (i < end)
			i++;
	}
	if(i < 0)
		i *= -1;
	return (i + 1);
}

int	*ft_fill(int start, int end, int *tab, int length)
{
	int	i;

	i = 0;
	while (i <= length)
	{
		if (start < 0)
		{
			if (start < end)
				tab[i] = (start + i);
			else
				tab[i] = (start - i);
		}
		else if (start >= 0)
		{
			if (start < end)
				tab[i] = (start + i);
			else
				tab[i] = (start - i);
		}
		else
			tab[i] = (start + i);
		i++;
	}
	return (tab);
}

int	*ft_range(int start, int end)
{
	int	length;
	int	*tab;

	length = ft_gap(start, end);
	tab = malloc(length * sizeof(int));
	if (tab == 0)
		return (NULL);
	tab = ft_fill(start, end, tab, length);
	return (tab);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	int	*tab;
	int	start;
	int	end;
	int	i;

	i = 0;
	start = atoi(av[1]);
	end = atoi(av[2]);
	if (ac == 3)
	{
		tab = ft_range(start, end);
		if (start < end)
		{
			while (start + i <= end)
			{
				if (tab[i + 1] != end)
					printf("%d, ", tab[i]);
				else
					printf("%d.", tab[i]);
				i++;
			}
		}
		else
		{
			while ((end + i) <= start)
			{
				if (tab[i + 1] != start)
					printf("%d, ", tab[i]);
				else
					printf("%d.", tab[i]);
				i++;
			}
		}
	}
	return (0);
}

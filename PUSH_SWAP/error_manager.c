/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:34:27 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/28 11:09:41 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static long	atol(char **s);

int	error_duplication(int *pa, int length)
{
	int	i;
	int	j;
	int	value;

	i = 0;
	while (i < length)
	{
		value = pa[i];
		j = 0;
		while (j < length)
		{
			if (value == pa[j] && j != i)
			{
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	error_no_number(char **av, int ac)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if (ac[j][i] != ' ' || ac[j][i] >= '0' && ac[j][i] <= '9')
			{
				exit(1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	error_isnt_int(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ')
	{
		if (s[i] == '-' || s[i] == '+')
			i++;
		if (atol(&s[i]) == 1)
		{
			exit(1);
		}
		else
			break ;
		i++;
	}
	return (0);
}

static long	atol(char **s)
{
	long	num;
	int		i;

	while (*s[i] && *s[i] != ' ')
	{
		if (*s[i] == '-' || *s[i] == '+')
			i++;
		num = num * 10 + (*s[i] - '0');
		i++;
	}
	if (num > -2147483647 && 2147483647 > num)
		return (0);
	else
		return (1);
}

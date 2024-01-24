/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:24:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/24 10:57:30 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *s);

/*
* In push_swap.c -> main()
* Verification of the numbers send by the user.
* The numbers can't be two times in the stack a.
*/

int	error_duplication(int *pa, int length, t_vars *vars)
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
				free(pa);
				free(vars);
				write (2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*
* In parsing.c -> ft_strjoin()
* Verification of the numbers send by the user.
* The numbers can't be other than a numeric character, minus, plus or a space
*/

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

int	error_no_number(char **av, int ac, t_vars *vars)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i] || av[j][0] == 0)
		{
			while (av[j][i] == ' ')
				i++;
			if (av[j][i] == '+' || av[j][i] == '-')
				i++;
			if (av[j][i] < '0' || av[j][i] > '9')
				ft_error_zero(vars);
			if ((av[j][i] >= '0' || av[j][i] <= '9')
				&& (av[j][i + 1] == '+' || av[j][i + 1] == '-'))
				ft_error_zero(vars);
			i++;
			while (av[j][i] == ' ')
				i++;
		}
		j++;
	}
	return (0);
}

/*
* In parsing.c -> ft_substr()
* Verification of the numbers send by the user.
* The numbers can't be above the size of a integer or below.
*/

int	error_isnt_int(char *s, int *tab, char *str, t_vars *vars)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ')
	{
		if (ft_atol(&s[i]) == 1)
		{
			free(vars);
			free(tab);
			free(str);
			write (2, "Error\n", 6);
			exit(1);
		}
		else
			break ;
		while (s[i] && s[i] != ' ')
			i++;
	}
	return (0);
}

static long	ft_atol(char *s)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	num = 0;
	sign = 1;
	while (s[i] && s[i] != ' ')
	{
		if (s[i] == '-' || s[i] == '+')
		{
			sign = -1;
			i++;
		}
		num = num * 10 + (s[i] - '0');
		i++;
	}
	num *= sign;
	if (num >= -2147483648 && 2147483648 > num)
		return (0);
	else
		return (1);
}

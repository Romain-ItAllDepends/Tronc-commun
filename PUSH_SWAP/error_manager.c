/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:34:27 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/13 11:41:43 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static long	ft_atol(char *s);

/*
* In push_swap.c -> main()
* Verification of the numbers send by the user.
* The numbers can't be two times in the stack a.
*/

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
				free(pa);
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

int	error_no_number(char **av, int ac)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i] || av[j][0] == 0)
		{
			if (av[j][i] == ' ')
				i++;
			if (av[j][i] == '+' || av[j][i] == '-')
				i++;
			if (av[j][i] < '0' || av[j][i] > '9')
				ft_error();
			if ((av[j][i] >= '0' || av[j][i] <= '9')
				&& (av[j][i + 1] == '+' || av[j][i + 1] == '-'))
				ft_error();
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

int	error_isnt_int(char *s, int *tab, char *str)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ')
	{
		if (ft_atol(&s[i]) == 1)
		{
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

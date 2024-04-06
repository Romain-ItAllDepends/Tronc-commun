/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:24:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/04/06 12:20:12 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = s;
	while (i < n)
	{
		tab[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	s;
	void			*ptr;

	s = nmemb * size;
	if (s < 0 || ((int)nmemb < 0 && (int)size < 0))
		return (NULL);
	ptr = malloc(s);
	if (ptr)
		ft_memset(ptr, 0, s);
	return (ptr);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s);
	}
}

void	error(t_vars *vars, char *s)
{
	int	length;

	length = ft_strlen(s);
	write(2, s, length);
	ft_free(vars->cmd1);
	ft_free(vars->cmd2);
	free(vars);
	exit(1);
}

void	error_g(t_vars *vars, char **path)
{
	ft_free(vars->cmd1);
	ft_free_tab((void **) vars->cmd2);
	ft_free(path);
	free(vars);
	exit(1);
}

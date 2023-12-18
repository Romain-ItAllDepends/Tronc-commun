/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:31:40 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/11 16:27:27 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_replace_ptr(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (&str[i + 1]);
}

static char	*ft_fill(char *str)
{
	int	i;
	char	*tab;

	i = 0;
	tab = malloc((ft_strlen_mod(str)) * sizeof(char));
	if (tab == 0)
		return (0);
	while (str[i] && str[i] != '\n')
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0'; 
	return (tab);
}

char *get_next_line(int fd)
{
	char	*result;
	static int	count;
	static char	*file;

	if (count == 0)
	{
		file = ft_keep_file(fd);
		if (!file)
			return (0);
	}
	result = ft_fill(file);
	file = ft_replace_ptr(file);
	close(fd);
	count++;
	return (result);
}



#include <stdio.h>

int main(void)
{
	int fd;
	int	i;
	char	**tab;

	i = 0;
	tab = (char **)malloc(5 * sizeof(char *));
	fd = open("files/empty", O_RDWR);
	while (i < 2)
	{
		tab[i] = malloc(50 * sizeof(char));
		tab[i] = get_next_line(fd);
		printf("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	close(fd);
	return (0);
}

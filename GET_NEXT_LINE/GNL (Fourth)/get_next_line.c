/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:34:36 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/25 10:50:58 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static int	count;
	static char	buffer[BUFFER_SIZE + 1];
	static char *line;
	int	n;

	if (fd == 0)
		return (NULL);
	if (count > 0)
	{
		line = NULL;
		line = ft_strjoin(line, buffer);
	}
	while (1)
	{
		if (ft_back(line) > 0)
			return (line);
		if (ft_back(line) == 0)
		{
			n = ft_read(fd, buffer);
			if (n == -1)
				return (NULL);
			if (n == 0 && buffer[0] != 0)
				return (line);
			else if (n == 0)
				return (NULL);
			line = ft_split(line, buffer, count);
		}
		count++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int    main(void)
{
    int        fd;
    //int        i;
    //char    rsl[9] = "wsh pelo";
	char	*tab;
	char *nul = NULL;

	*/
	//fd = open("files/41_no_nl", O_RDONLY);*/
/*
    i = 0;
    
    while (i < 6)
    {
        tab = get_next_line(fd);
        if (!tab)
			printf("%s", rsl);
		else
			printf("%s", tab);
        i++;
        free(tab);
    }
    close(fd);
*//*
	fd = open("files/empty", O_RDWR);
	tab = get_next_line(fd);
	if (strcmp(tab, "01234567890123456789012345678901234567890\n") != 0)
		printf("error");
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	if (strcmp(tab, "\n") != 0)
		printf("error");
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	if (strcmp(tab, "987654321098765432109876543210987654321090\n") != 0)
		printf("error");
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	if (strcmp(tab, "\n") != 0)
		printf("error");
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	if (strcmp(tab, "0123456789012345678901234567890123456789012\n") != 0)
		printf("error");
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	if (strcmp(tab, "\n") != 0)
		printf("error");
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	if (strcmp(tab, "987654321098765432109876543210987654321090\n") != 0)
		printf("error");
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	if (strcmp(tab, "\n") != 0)
		printf("error");
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	if (strcmp(tab, "01234567890123456789012345678901234567890\n") != 0)
		printf("error");
	printf("%s", tab);
	free(tab);
			////////////////////////////////////////////////////////////////
	tab = get_next_line(fd);
	if (strcmp(tab, nul) != 0)
		printf("error");
	printf("%s", tab);
	free(tab);
}
			tab = get_next_line(fd);
	if (strcmp(tab, "01234567890123456789012345678901234567890") != 0)
		printf("error");
		 	printf("%s", tab);
			free(tab);
			tab = get_next_line(fd);

		 	printf("%s", tab);
			free(tab);
	close(fd);
    return (0);
}
*/

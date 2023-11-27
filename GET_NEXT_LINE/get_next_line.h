/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:36:05 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/25 10:32:32 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char *s2);
char	*ft_split(char *line, char *buffer, int count);
int	ft_read(int fd, char *s);
int		ft_back(char *s);
int		ft_strlen(char const *s);

#endif

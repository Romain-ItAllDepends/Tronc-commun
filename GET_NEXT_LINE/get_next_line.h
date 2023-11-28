/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:26:51 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/28 13:58:40 by rgobet           ###   ########.fr       */
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
char	*ft_split(char *stash, char *buffer, int count);
char	*ft_fill(char *line, char *buffer, char *tab);
void	ft_clear(char *s, char *buffer);
int	ft_strlen(char *s);
int	ft_back(char *s);


#endif

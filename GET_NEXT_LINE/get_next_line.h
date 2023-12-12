/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:01:25 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/11 17:01:38 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *b, char *s, int count);
char	*ft_cut(char *s, char *b);
char	*ft_finish(char *s);
void	ft_save(char *s, char *b);
int		ft_strchr(char *s, int c);
int		ft_strlen(char *s);

#endif

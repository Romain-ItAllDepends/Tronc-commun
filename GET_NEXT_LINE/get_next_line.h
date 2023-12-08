/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:57:02 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/08 15:25:48 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*ft_strdup(char *s);
char	*get_next_line(int fd);
char	*ft_core(int fd, char **stash, char *buffer, char *new_line);
char	*ft_join(char *s, char *b);
char	*ft_join_d(char *s, char *b);
char	*ft_split(char *stash, char *buffer);
int		ft_read(int fd, char *buffer, char *stash);
int		ft_strchr(char *s, int c);
int		ft_strlen(char *s);

#endif
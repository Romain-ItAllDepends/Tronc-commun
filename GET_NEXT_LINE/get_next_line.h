/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:57:02 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/09 16:27:14 by rgobet           ###   ########.fr       */
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

char	*get_next_line(int fd);
char	*ft_strjoin(char *b, char *s, int count);
char	*cut(char *s, char *b);
char	*finish(char *s);
void	save(char *s, char *b, int i);
int		ft_strchr(char *s, int c);
int		ft_strlen(char *s);

#endif
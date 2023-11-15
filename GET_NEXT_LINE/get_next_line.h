/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:30:07 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/15 14:41:15 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strlen(const char *s);
int		ft_strlen_mod(char const *str);
int		ft_read(int fd, char *buffer);
int		ft_bn(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_swap(char *buffer, char *stash);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);

#endif

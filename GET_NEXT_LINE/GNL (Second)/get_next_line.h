/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:30:07 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/18 14:53:49 by rgobet           ###   ########.fr       */
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
int		ft_read(int fd, char *buffer, int buff);
int		ft_bn(char *s, int opt);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
void	*ft_calloc(char *buffer, char *stash);
void	ft_swap(char *buffer, char *stash, int opt);
void	ft_join(char *buffer, char *stash, int opt, char *v);

#endif

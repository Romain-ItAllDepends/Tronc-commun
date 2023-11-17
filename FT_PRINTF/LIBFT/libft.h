/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:05:17 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/16 14:08:09 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "../ft_printf.h"

int	ft_strlen(const char *str);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbru_fd(unsigned int n, int fd);
int	ft_puthex_fd(unsigned int n, int fd, char *base);
int	ft_putptr_fd(unsigned long long n, int fd, char *base);

#endif

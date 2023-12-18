/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:08:56 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/18 12:28:27 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "FT_PRINTF/ft_printf.h"

int	*ft_swap(int *tab, char c);
void	ss(int **pa, int **pb, int la, int lb);
int	*ft_push(int *tab, int x, int length, char c);
int	*ft_rotate(int *tab, int length, char c);
void	rr(int **pa, int **pb, int la, int lb);
int	*ft_reverse_rotate(int *tab, int length, char c);
void	rrr(int **pa, int **pb, int la, int lb);

#endif

/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:08:56 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/22 14:19:55 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "FT_PRINTF/ft_printf.h"
# include "FT_PRINTF/LIBFT/libft.h"

int		*ft_swap(int *tab, char c);
void	ss(int **pa, int **pb);
int		*ft_push(int *p, int *length, int n, char c);
int		*ft_push_balance(int *p, int *length);
int		*ft_rotate(int *tab, int length, char c);
void	rr(int **pa, int **pb, int la, int lb);
int		*ft_reverse_rotate(int *tab, int length, char c);
void	rrr(int **pa, int **pb, int la, int lb);
int		*conversion_char_to_int_array(char const *s, char c, int *length);
int		*ft_split_initb(int **pa, int **pb, int *lengtha, int *lengthb);
int		*ft_split_inita(int **pb, int **pa, int *lengtha, int *lengthb);
char	*ft_strjoin(char **s, int nbList);
int		sort_bubble(int *tab, int length);
int		ft_midpoint(int *tab, int length);

#endif

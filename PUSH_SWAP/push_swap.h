/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:08:56 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/06 11:25:26 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "FT_PRINTF/ft_printf.h"
# include "FT_PRINTF/LIBFT/libft.h"

typedef struct s_vars{
	int	len_a;
	int	len_b;
	int	len_c;
	int	nb_chunk;
	int	*chunk;
	int	*midpoint;
	int	*pa;
	int	*pb;
}	t_vars;

/*
* Instructions of Push Swap
*/
void	ft_swap(int *tab, char c);
void	ss(t_vars *vars);
int		*ft_push(int *p, int *length, int n, char c);
int		*ft_push_balance(int *p, int *length);
int		*ft_rotate(int *tab, int length, char c);
void	rr(t_vars *vars);
int		*ft_reverse_rotate(int *tab, int length, char c);
void	rrr(t_vars *vars);

/*
* Parsing
*/
int		*conversion_char_to_int_array(char const *s, char c, int *length);
char	*ft_strjoin(char **s, int nbList);

/*
* Sort
*/
void	ft_split_initb(t_vars *vars);
int		sort_bubble(int *tab, int length);
int		ft_midpoint(int *tab, int length);
int		decreasing(int *pb, int lengthb);
int		crescent(int *pb, int lengthb);
int		alone(int midpoint, t_vars *vars);
int		*ft_switch(int *sort, int j);
int		*ft_fill(int *tab, int length);
int		*chunk_init(int newmidpoint, t_vars *vars);
void	reverse_split(t_vars *vars);
void	ft_chunk_check(t_vars *vars, int ind);
int		max_chunk(t_vars *vars, int index_midpoint);
int		min_chunk(t_vars *vars, int index_midpoint);
int		nb_sup(t_vars *vars, int n);
int		max(t_vars *vars, int index_midpoint);
void	special_case(t_vars *vars);
void	reverse(t_vars *vars, int c);
void	order_a(t_vars *vars);

/*
* Error
*/
int		error_duplication(int *pa, int length);
int		error_no_number(char **av, int ac);
int		error_isnt_int(char *s, int *tab, char *str);

/*
* Allocs
*/
void	*ft_calloc(size_t nmemb, size_t size);


#endif

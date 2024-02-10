/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:24:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/27 14:20:14 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	*np;
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
int		*conversion_char_to_int_array(char const *s,
			char c, int *length, t_vars *vars);
char	*ft_strjoin(char **s, int nbList, t_vars *vars);

/*
* Sort
*/
void	alone_push(t_vars *vars);
void	ft_split_initb(t_vars *vars);
int		select_chunk_size(int *sort, int length);
int		sort_bubble(int *tab, int length);
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
int		*normalisation(int *p, int length);
void	ft_four(t_vars *vars);
int		nb_min(int *p, int length);
int		nb_max(int *p, int length);
void	ft_one_hundred(t_vars *vars);
int		sort(int *tab, int length);
int		nb_inf(t_vars *vars, int n);
void	ss_or_sa(t_vars *vars);

/*
* Error
*/
int		error_duplication(int *pa, int length, t_vars *vars);
int		error_no_number(char **av, int ac, t_vars *vars);
int		error_isnt_int(char *s, int *tab, char *str, t_vars *vars);

/*
* Allocs and free
*/
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_error_zero(t_vars *vars);

#endif

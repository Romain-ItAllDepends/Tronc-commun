/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:08:56 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/01 13:53:34 by rgobet           ###   ########.fr       */
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
	int	*midpoint;
	int	*pa;
	int	*pb;
}	t_vars;

/*
* Instructions of Push Swap
*/
int		*ft_swap(int *tab, char c);
void	ss(int **pa, int **pb);
int		*ft_push(int *p, int *length, int n, char c);
int		*ft_push_balance(int *p, int *length);
int		*ft_rotate(int *tab, int length, char c);
void	rr(int **pa, int **pb, int la, int lb);
int		*ft_reverse_rotate(int *tab, int length, char c);
void	rrr(int **pa, int **pb, int la, int lb);

/*
* Parsing
*/
int		*conversion_char_to_int_array(char const *s, char c, int *length);
char	*ft_strjoin(char **s, int nbList);

/*
* Sort
*/
int		*ft_split_initb(int **pa, int **pb, int *lengtha, int *lengthb);
int		*ft_split_inita(int **pb, int **pa, int *lengtha, int *lengthb);
int		sort_bubble(int *tab, int length);
int		ft_midpoint(int *tab, int length);
int		decreasing(int *pb, int lengthb);
int		*ft_switch(int *sort, int j);
int		*ft_fill(int *tab, int length);
int		**chunk_init(int newmidpoint, int *p, int **chunk);
int		*prepare(int lengtha, int lengthb);
void	reverse_split(int **pa, int **pb, int *lengtha, int *lengthb);

/*
* Error
*/
int		error_duplication(int *pa, int length);
int		error_no_number(char **av, int ac);
int		error_isnt_int(char *s, int *tab, char *str);

/*
* Free / allocs
*/
void	ft_free(int	**list, int length);
void	*ft_calloc(size_t nmemb, size_t size);


#endif

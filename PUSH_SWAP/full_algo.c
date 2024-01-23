/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:28:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/23 11:32:19 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "algo.h"
#include "FT_PRINTF/ft_printf.h"
#include "FT_PRINTF/LIBFT/libft.h"

/*
* Parsing
*/
int		*conversion_char_to_int_array(char const *s, char c, int *length, t_vars *vars);
char	*ft_strjoin(char **s, int nbList, t_vars *vars);

/*
* Sort
*/
void	ft_split_initb(t_vars *vars);
int		sort_bubble(int *tab, int length);
int		ft_midpoint(int *tab, int length);
int		decreasing(int *pb, int lengthb);
int		crescent(int *pb, int lengthb);
int		alone(int midpoint, t_vars *vars);
void	alone_push(t_vars *vars);
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
void	ft_sort_three(t_vars *vars);
void	ft_four(t_vars *vars);
int		nb_min(int *p, int length);
int		nb_max(int *p, int length);

/*
* Error
*/
int		error_duplication(int *pa, int length, t_vars *vars);
int		error_no_number(char **av, int ac, t_vars *vars);
int		error_isnt_int(char *s, int *tab, char *str, t_vars *vars);

/*
* Allocs
*/
void	*ft_calloc(size_t nmemb, size_t size);





// Permet de swap les deux premiers nombre de la pile a ou b selon c et la liste en param.
void	ft_swap(int *tab, char c)
{
	int	b;

	b = tab[1];
	tab[1] = tab[0];
	tab[0] = b;
	if (c != 'x')
		ft_printf("s%c\n", c);
}

void	ss(t_vars *vars)
{
	ft_swap(vars->pa, 's');
	ft_swap(vars->pb, 'x');
	return ;
}

int	*ft_push(int *p, int *length, int n, char c)
{
	// Prend le premier élément au sommet de b et le met sur a. Et vice versa selon les params.
	//Ne fait rien si b est vide.
	int	i;
	int	*pn;

	i = 1;
	*length += 1;
	pn = malloc(*length * sizeof(int));
	if (!pn)
		return (NULL);
	pn[0] = n;
	while (*length > i && *length - 1 > 0)
	{
		pn[i] = p[i - 1];
		i++;
	}
	ft_printf("p%c\n", c);
	free(p);
	return (pn);
}

int	*ft_rotate(int *tab, int length, char c)
{
	//Décale d’une position vers le haut tous les élements de la pile a ou b.
	//Le premier élément devient le dernier.
	//Exemple 6, 5, 8 -> 5, 8, 6
	int	*res;
	int	i;

	i = 0;
	//ft_printf("\n\n\n\n\n\n\nl %d\n\n\n\n\n\n", length);
	res = malloc (length * sizeof(int));
	if (!res)
		return (NULL);
	while ((i + 1) < length)
	{
		res[i] = tab[i + 1];
		i++;
	}
	//ft_printf("\n\n\n\n\n\n\ni %d\n\n\n\n\n\n", i);
	res[i] = tab[0];
	if (c != 'x')
		ft_printf("r%c\n", c);
	free(tab);
	return (res);
}

void	rr(t_vars *vars)
{
	vars->pa = ft_rotate(vars->pa, vars->len_a, 'r');
	vars->pb = ft_rotate(vars->pb, vars->len_b, 'x');
}

int	*ft_reverse_rotate(int *tab, int length, char c)
{
	//Décale d’une position vers le bas tous les élements de la pile a ou b selon les params.
	//Le dernier élément devient le premier.
	int	*rr;
	int	i;

	i = 0;
	rr = malloc (length * sizeof(int));
	if (!rr)
		return (NULL);
	rr[0] = tab[length - 1];
	while (length - 1 > i)
	{
		rr[i + 1] = tab[i];
		i++;
	}
	if (c != 'x')
		ft_printf("rr%c\n", c);
	free(tab);
	return (rr);
}

void	rrr(t_vars *vars)
{
	vars->pa = ft_reverse_rotate(vars->pa, vars->len_a, 'r');
	vars->pb = ft_reverse_rotate(vars->pb, vars->len_b, 'x');
}

int	*ft_push_balance(int *p, int *length)
{
	int	i;
	int	*pn;

	*length -= 1;
	pn = malloc(*length * sizeof(int));
	if (!pn)
		return (NULL);
	i = 0;
	while (*length > i)
	{
		pn[i] = p[i + 1];
		i++;
	}
	free(p);
	return (pn);
}

int	nb_min(int *p, int length)
{
	int	i;
	int	nb;

	i = 1;
	nb = p[0];
	while (i < length)
	{
		if (nb > p[i])
			nb = p[i];
		i++;
	}
	return (nb);
}

int	nb_max(int *p, int length)
{
	int	i;
	int	nb;

	i = 1;
	nb = p[0];
	while (i < length)
	{
		if (nb < p[i])
			nb = p[i];
		i++;
	}
	return (nb);
}

/* ----------------------------------------------------------- */

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = s;
	while (i < n)
	{
		tab[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	long	s;
	void			*ptr;

	s = nmemb * size;
	if (s < 0 || ((int)nmemb < 0 && (int)size < 0))
		return (NULL);
	ptr = malloc(s);
	if (ptr)
		ft_memset(ptr, 0, s);
	return (ptr);
}

/* ----------------------------------------------------------- */

/*
* A chunk is an area in which the midpoint and the range of index of your chunk.
* We need the chunk to send the integer in the stack b in the stack a.
*/

int	*chunk_init(int newmidpoint, t_vars *vars)
{
	int	*newchunk;
	int	i;

	vars->len_c++;
	newchunk = malloc (sizeof(int) * (vars->len_c));
	if (!newchunk)
		return (NULL);
	i = 0;
	newchunk[i] = newmidpoint;
	while (i < vars->len_c - 1)
	{
		i++;
		newchunk[i] = vars->chunk[i - 1];
	}
	if (vars->len_c > 1)
		free(vars->chunk);
	// i = 0;
	// while (i < vars->len_c)
	// {
	// 	ft_printf("\n%d", newchunk[i]);
	// 	i++;
	// }
	// ft_printf("\n\n\n\n%d\n\n\n\n\n", vars->len_c);
	return (newchunk);
}

/* ------------------------------------------------------------- */

int	*normalisation(int *p, int length)
{
	int	i;
	int	j;
	int	c;
	int	*np;

	np = malloc(sizeof(int) * length);
	if (np == 0)
		return (0);
	i = 0;
	while (i < length)
	{
		j = 0;
		c = 0;
		while (j < length)
		{
			if (p[i] > p[j])
				c++;
			j++;
		}
		np[i] = c;
		i++;
	}
	return (np);
}

void	ft_sort_three(t_vars *vars)
{
	if (vars->np[0] == 1 && vars->np[1] == 0)
		ft_swap(vars->pb, 'b');
	else if (vars->np[0] == 2 && vars->np[1] == 1)
	{
		vars->pb = ft_rotate(vars->pb, vars->len_b, 'b');
		ft_swap(vars->pb, 'b');
	}
	else if (vars->np[0] == 2 && vars->np[1] == 0)
		vars->pb = ft_rotate(vars->pb, vars->len_b, 'b');
	else if (vars->np[0] == 0 && vars->np[1] == 2)
	{
		ft_swap(vars->pb, 'b');
		vars->pb = ft_rotate(vars->pb, vars->len_b, 'b');
	}
	else if (vars->np[0] == 1 && vars->np[1] == 2)
		vars->pb = ft_reverse_rotate(vars->pb, vars->len_b, 'b');
	vars->pb = ft_reverse_rotate(vars->pb, vars->len_b, 'b');
	ft_swap(vars->pb, 'b');
	while (0 < vars->len_b)
	{
		vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
		vars->pb = ft_push_balance(vars->pb, &vars->len_b);
	}
	free(vars->np);
}

/* ---------------------------------------------------------- */































































/* ------------------------------------------------------------ */














































































static int	ft_compare(int *pb, int *sort, int length);

int	decreasing(int *pb, int lengthb)
{
	int	*sort;
	int	i;
	int	j;
	int	l;

	i = 0;
	l = lengthb;
	sort = ft_fill(pb, lengthb);
	while (i < lengthb - 1)
	{
		j = 0;
		while (j < l - 1)
		{
			if (sort[j] < sort[j + 1])
				sort = ft_switch(sort, j);
			j++;
		}
		i++;
	}
	i = ft_compare(pb, sort, lengthb);
	free(sort);
	return (i);
}

int	crescent(int *pb, int lengthb)
{
	int	*sort;
	int	i;
	int	j;
	int	l;

	i = 0;
	l = lengthb;
	sort = ft_fill(pb, lengthb);
	while (i < lengthb)
	{
		j = 0;
		while (j < l - 1)
		{
			if (sort[j] > sort[j + 1])
				sort = ft_switch(sort, j);
			j++;
		}
		l--;
		i++;
	}
	i = ft_compare(pb, sort, lengthb);
	free(sort);
	return (i);
}

void	ft_four(t_vars *vars)
{
	vars->pb = ft_push(vars->pb, &vars->len_b, vars->pa[0], 'b');
	vars->pa = ft_push_balance(vars->pa, &vars->len_a);
	vars->pb = ft_push(vars->pb, &vars->len_b, vars->pa[0], 'b');
	vars->pa = ft_push_balance(vars->pa, &vars->len_a);
	if (vars->pb[0] < vars->pb[1])
		ft_swap(vars->pb, 'b');
	if (vars->pa[0] > vars->pa[1])
		ft_swap(vars->pa, 'a');
	vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
	vars->pb = ft_push_balance(vars->pb, &vars->len_b);
	vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
	vars->pb = ft_push_balance(vars->pb, &vars->len_b);
	free(vars->pb);
}

static int	ft_compare(int *pb, int *sort, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (pb[i] != sort[i])
			return (1);
		i++;
	}
	return (0);
}

/* ----------------------------------------------------------- */

int	nb_sup(t_vars *vars, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->len_a)
	{
		if (n > vars->pa[i])
			j++;
		i++;
	}
	return (j);
}

/*
* Get the range of the chunk.
* Normalement corriger mais pas sur d'etre ok avecle reste du code.
*/

int	min_chunk(t_vars *vars, int index_midpoint)
{
	int	i;

	i = 0;
	if (index_midpoint == 0)
		return (0);
	while (i < vars->len_b)
	{
		if (vars->chunk[index_midpoint] > vars->pb[i]
			&& vars->chunk[index_midpoint - 1] <= vars->pb[i])
			return (i);
		i++;
	}
	return (0);
}

int	max_chunk(t_vars *vars, int index_midpoint)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (index_midpoint >= vars->len_c)
		return (vars->len_b - 1);
	while (i < vars->len_b)
	{
		if (vars->chunk[index_midpoint] > vars->pb[i]
			&& vars->chunk[index_midpoint + 1] <= vars->pb[i])
			j++;
		else
			break ;
		i++;
	}
	if (j == 0)
		return (-1);
	return (j);
}

/*
* Biggest number of the stack.
*/

int	max(t_vars *vars, int index_midpoint)
{
	int	i;
	int	j;

	i = 0;
	j = vars->pb[i];
	while (i < vars->len_b)
	{
		if (vars->chunk[index_midpoint] > vars->pb[i] && j < vars->pb[i])
			j = vars->pb[i];
		i++;
	}
	return (j);
}

void	reverse(t_vars *vars, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		vars ->pa = ft_reverse_rotate(vars->pa, vars->len_a, 'a');
		i++;
	}
}

/* ----------------------------------------------------------- */

void	alone_push(t_vars *vars)
{
	if (vars->len_a > 1 && vars->pa[0] > vars->pa[1])
		ft_swap(vars->pa, 'a');
	if (vars->len_b > 1 && vars->pb[0] < vars->pb[1])
		ft_swap(vars->pb, 'b');
	order_a(vars);
	vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
	vars->pb = ft_push_balance(vars->pb, &vars->len_b);
	order_a(vars);
}

int	alone(int midpoint, t_vars *vars)
{
	int	i;
	int	j;
	int	ac;

	i = 0;
	j = 0;
	ac = 0;
	while (vars->chunk[ac] != midpoint)
		ac++;
	if (ac == 0 && vars->len_b == 1)
		return (1);
	else if (ac == vars->len_c - 1 && vars->len_b == 1)
		return (1);
	else if (ac == vars->len_c - 1)
		return (0);
	while (i < vars->len_b)
	{
		if (midpoint > vars->pb[i] && vars->pb[i] >= vars->chunk[ac + 1])
			j++;
		i++;
	}
	if (j == 1)
		return (1);
	return (0);
}

static void	finish(t_vars *vars)
{
	int	j;
	int	length;

	j = 0;
	length = vars->len_b;
	while (j < length)
	{
		vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
		vars->pb = ft_push_balance(vars->pb, &vars->len_b);
		j++;
	}
	return ;
}

/*
* Algorithme de tri pas ouf
*
*
**/


void	order_a(t_vars *vars)
{
	int	i;
	int	s;

	i = 0;
	if (vars->len_a > 0)
		s = vars->pa[0];
	while (i < vars->len_a - 1 && vars->pa[0] > vars->pa[1])
	{
		if (vars->pa[0] > vars->pa[1] && nb_sup(vars, s) > 1)
		{
			ft_swap(vars->pa, 'a');
			if (i < vars->len_a - 1 && (vars->pa[0] > vars->pa[1]
					|| vars->pa[1] > vars->pa[2]))
			{
				vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
				i++;
			}
		}
		else if (nb_sup(vars, s) == 1)
			ft_swap(vars->pa, 'a');
		else if (nb_sup(vars, s) == 0)
			break ;
	}
	while (i >= 1)
	{
		if (i < vars->len_b - 1 && vars->pa[0] > vars->pb[0]
			&& vars->pa[vars->len_a - 1] < vars->pb[0])
		{
			vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
			vars->pb = ft_push_balance(vars->pb, &vars->len_b);
		}
		else if (i < vars->len_b - 1 && vars->pa[0] > vars->pb[1]
			&& vars->pa[vars->len_a - 1] < vars->pb[1] && i >= 1)
		{
			ft_swap(vars->pb, 'b');
			vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
			vars->pb = ft_push_balance(vars->pb, &vars->len_b);
		}
		vars->pa = ft_reverse_rotate(vars->pa, vars->len_a, 'a');
		i--;
	}
}

static void	order_b(t_vars *vars, int i_max)
{
	int	r;
	int	m;

	r = 1;
	m = vars->pb[i_max];
	if (vars->len_b / 2 >= i_max)
		r = 0;
	while (vars->pb[0] != m)
	{
		if (r == 0 || r == 1)
			vars->pb = ft_rotate(vars->pb, vars->len_b, 'b');
		else if (r == 1)
			vars->pb = ft_reverse_rotate(vars->pb, vars->len_b, 'b');
	}
	vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
	vars->pb = ft_push_balance(vars->pb, &vars->len_b);
}

void	ft_chunk_check(t_vars *vars, int ind)
{
	int	i;
	int	max;
	// int	m;

	max = max_chunk(vars, ind); //A refaire
	i = min_chunk(vars, ind); //A refaire
	// if (max != -1)
	// 	m = sort_bubble(vars->pb, max - i);
	if (i - max <= 2 && vars->pb[0] < vars->pb[1])
		ft_swap(vars->pb, 'b');
	while (i < max)
	{
		if (vars->pb[0] > vars->pb[1])
		{
			vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
			vars->pb = ft_push_balance(vars->pb, &vars->len_b);
			order_a(vars);
			i++;
		}
		else if (vars->pb[0] < vars->pb[1])
			ft_swap(vars->pb, 'b');
	}
}

void	special_case(t_vars *vars)
{
	int	j;
	int	mx;

	while (vars->len_b)
	{
		mx = max(vars, vars->len_c - 1);
		j = 0;
		while (j < vars->len_b)
		{
			if (vars->pb[j] != mx)
				j++;
			else
				break ;
		}
		order_b(vars, j);
		order_a(vars);
	}
}

/* ----------------------------------------------------------- */

void	reverse_split(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->len_c)
	{
		if (alone(vars->chunk[i], vars) != 0) // Si il reste qu'un nombre dans le chunk
			alone_push(vars); // DONE
		else if (i < vars->len_c - 1) // Lecture des autres chunk
			ft_chunk_check(vars, i);
		else if (decreasing(vars->pb, vars->len_b) == 0) // Si la pile b est decroissante
		{
			finish(vars); // DONE
			break ;
		}
		else if (i == vars->len_c - 1)
			special_case(vars);
		if (crescent(vars->pa, vars->len_a) == 1)
			order_a(vars);
		i++;
	}
}




























































/* ------------------------------------------------------------ */
























































static long	ft_atol(char *s);

/*
* In push_swap.c -> main()
* Verification of the numbers send by the user.
* The numbers can't be two times in the stack a.
*/

int	error_duplication(int *pa, int length, t_vars *vars)
{
	int	i;
	int	j;
	int	value;

	i = 0;
	while (i < length)
	{
		value = pa[i];
		j = 0;
		while (j < length)
		{
			if (value == pa[j] && j != i)
			{
				free(pa);
				free(vars);
				write (2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*
* In parsing.c -> ft_strjoin()
* Verification of the numbers send by the user.
* The numbers can't be other than a numeric character, minus, plus or a space
*/

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

void	ft_error_zero(t_vars *vars)
{
	write (2, "Error\n", 6);
	free(vars);
	exit(1);
}

int	error_no_number(char **av, int ac, t_vars *vars)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i] || av[j][0] == 0)
		{
			while (av[j][i] == ' ')
				i++;
			if (av[j][i] == '+' || av[j][i] == '-')
				i++;
			if (av[j][i] < '0' || av[j][i] > '9')
				ft_error_zero(vars);
			if ((av[j][i] >= '0' || av[j][i] <= '9')
				&& (av[j][i + 1] == '+' || av[j][i + 1] == '-'))
				ft_error_zero(vars);
			i++;
			while (av[j][i] == ' ')
				i++;
		}
		j++;
	}
	return (0);
}

/*
* In parsing.c -> ft_substr()
* Verification of the numbers send by the user.
* The numbers can't be above the size of a integer or below.
*/

int	error_isnt_int(char *s, int *tab, char *str, t_vars *vars)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ')
	{
		if (ft_atol(&s[i]) == 1)
		{
			free(vars);
			free(tab);
			free(str);
			write (2, "Error\n", 6);
			exit(1);
		}
		else
			break ;
		while (s[i] && s[i] != ' ')
			i++;
	}
	return (0);
}

static long	ft_atol(char *s)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	num = 0;
	sign = 1;
	while (s[i] && s[i] != ' ')
	{
		if (s[i] == '-' || s[i] == '+')
		{
			sign = -1;
			i++;
		}
		num = num * 10 + (s[i] - '0');
		i++;
	}
	num *= sign;
	if (num >= -2147483648 && 2147483648 > num)
		return (0);
	else
		return (1);
}

static int	ft_charcount(char const *str, char c)
{
	int	i;
	int	j;

	if (!str[0])
		return (0);
	i = 0;
	j = 1;
	if (str[i] == c || str[ft_strlen(str) - 1] == c)
	{
		j = 0;
		if (str[ft_strlen(str) - 1] != c)
			j = 1;
		i++;
	}
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c)
			j++;
		i++;
	}
	if (j == i)
		return (0);
	return (j);
}

static int	ft_strlendb(char **s, int length)
{
	int	i;
	int	x;
	int	n;
	int	sp;

	i = 0;
	n = 1;
	sp = 0;
	while (n < length)
	{
		x = 0;
		while (s[n][x])
		{
			if (s[n][x + 1] == 0)
				sp++;
			x++;
		}
		n++;
		i += x;
	}
	return (i + sp);
}

static int	ft_substr(char const *s, int *tabl, char *str, t_vars *vars)
{
	char			c;
	unsigned int	i;
	int				tab;

	i = 0;
	tab = 0;
	c = ' ';
	error_isnt_int((char *)s, tabl, str, vars);
	while (s[i] && s[i] != c)
	{
		if (s[i] == '-' || s[i] == '+')
			i++;
		tab = tab * 10 + (s[i] - '0');
		i++;
	}
	if (s[0] == '-')
		return (tab * -1);
	return (tab);
}

int	*conversion_char_to_int_array(char const *s, char c, int *length, t_vars *vars)
{
	int	i;
	int	x;
	int	*tab;

	i = 0;
	x = 0;
	if (!s)
		return (0);
	*length = ft_charcount(s, c);
	tab = malloc(*length * sizeof(int));
	if (tab == 0)
		return (0);
	while (s[i])
	{
		if (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			tab[x++] = ft_substr(&s[i], tab, (char *)s, vars);
		while (s[i] && s[i] != c)
			i++;
	}
	return (tab);
}

char	*ft_strjoin(char **s, int nbList, t_vars *vars)
{
	char	*tab;
	int		i;
	int		j;
	int		x;

	error_no_number(s, nbList, vars);
	tab = malloc((ft_strlendb(s, nbList) + 1) * sizeof(char));
	i = 0;
	j = 1;
	if (tab == 0)
		return (0);
	while (j < nbList)
	{
		tab[i++] = ' ';
		x = 0;
		while (s[j][x])
		{
			tab[i] = s[j][x];
			i++;
			x++;
		}
		j++;
	}
	tab[i] = 0;
	return (tab);
}

int	*ft_fill(int *tab, int length);
int	*ft_switch(int *sort, int j);

/*
* Make a function to find the closest number lower than n.
*

static int	r_or_rr(t_vars *vars, int n)
{
	int	i;
	int	j;
	int	m;
	int	temp;

	i = 0;
	j = 0;
	m = 0;
	while (i < vars->len_a)
	{
		if (n > vars->pa[i])
		{
			j = i;
			break ;
		}
		i++;
	}
	while (i > 0)
	{
		if (n > vars->pa[i])
		{
			m = i;
			break ;
		}
		i--;
	}
	temp = m - vars->len_a - 1;
	if (temp < j)
		return (1);
	else
		return (0);
}

*
**/

int	nb_inf(t_vars *vars, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->len_a)
	{
		if (n > vars->pa[i])
			j++;
		i++;
	}
	return (j);
}

void	ft_split_initb(t_vars *vars)
{
	int			midpoint;
	int			nb;
	int			i;

	i = 0;
	midpoint = sort_bubble(vars->pa, vars->len_a);
	nb = nb_inf(vars, midpoint);
	while (i < 25 && i < nb)
	{
		if (vars->pa[0] < midpoint)
		{
			vars->pb = ft_push(vars->pb, &vars->len_b, vars->pa[0], 'b');
			vars->pa = ft_push_balance(vars->pa, &vars->len_a);
			i++;
		}
		else if (vars->pa[0] >= midpoint && vars->len_a > 1)
			vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
		// else if (vars->pa[0] >= midpoint && vars->len_a > 1
		// 	&& r_or_rr(vars, midpoint) == 1)
		// 	vars->pa = ft_reverse_rotate(vars->pa, vars->len_a, 'a');
		if (nb_inf(vars, midpoint) == 0)
			break ;
	}
}

/*

int	*ft_split_inita(t_vars *vars)
{
	int	i;
	int	midpoint;

	i = 0;
	midpoint = sort_bubble(vars->pb, vars->len_b);
	if (midpoint == 0)
		return ((int *)vars->pa);
	while (i < vars->len_b)
	{
		if (vars->pb[i] < midpoint)
		{
			vars->pa = ft_push(vars->pa, vars->len_a, vars->pb[0], 'b');
			vars->pb = ft_push_balance(vars->pb, vars->len_b);
		}
		else if ((i + 1) < vars->len_b)
			vars->pb = ft_rotate(vars->pb, vars->len_b, 'b');
		else
		{
			vars->pa = ft_push(vars->pa, vars->len_a, vars->pb[0], 'b');
			vars->pb = ft_push_balance(vars->pb, vars->len_b);
		}
		if (!(vars->pb[i] > midpoint))
			i++;
	}
	return ((int *)vars->pa);
}

*/

//Trieur et midpoint maker

int	sort_bubble(int *tab, int length)
{
	int	*sort;
	int	mid;
	int	i;
	int	j;
	int	l;

	i = 0;
	if (length == 0)
		return (0);
	l = length;
	sort = ft_fill(tab, length);
	if (sort == 0)
		return (-1);
	while (i < length)
	{
		j = -1;
		while (j++ < l - 2)
		{
			if (sort[j] > sort[j + 1])
				sort = ft_switch(sort, j);
		}
		l--;
		i++;
	}
	if (length < 53)
		mid = sort[length / 2];
	else if (length < 103)
		mid = sort[length / 4];
	else if (length < 253)
		mid = sort[length / 10];
	else if (length > 252)
		mid = sort[length / 20];
	free(sort);
	return (mid);
}

int	*ft_switch(int *sort, int j)
{
	int	temp;

	temp = sort[j + 1];
	sort[j + 1] = sort[j];
	sort[j] = temp;
	return (sort);
}

int	*ft_fill(int *tab, int length)
{
	int	i;
	int	*res;

	res = malloc (length * sizeof(int));
	if (!res)
		return (0);
	i = 0;
	while (i < length)
	{
		res[i] = tab[i];
		i++;
	}
	return (res);
}

t_vars	*core(t_vars *vars)
{
	int	i;

	i = 0;
	vars->len_b = 0;
	vars->len_c = 0;
	vars->pb = NULL;
	vars->chunk = NULL;
	while (vars->len_a > 2 && crescent(vars->pa, vars->len_a) == 1)
	{
		vars->chunk = chunk_init(sort_bubble(vars->pa, vars->len_a), vars);
		if (!vars->chunk)
			exit(1);
		ft_split_initb(vars);
		i++;
	}
	if (vars->len_b > 0)
	{
		if (vars->len_a == 2 && vars->pa[0] > vars->pa[1])
			ft_swap(vars->pa, 'a');
		if (!(crescent(vars->pa, vars->len_a) == 0 && vars->len_b == 0))
			reverse_split(vars);
	}
	free(vars->pb);
	free(vars->chunk);
	return (vars);
}

void	ft_three(t_vars *vars)
{
	vars->np = normalisation(vars->pa, vars->len_a);
	if (vars->np[0] == 1 && vars->np[1] == 0)
		ft_swap(vars->pa, 'a');
	else if (vars->np[0] == 2 && vars->np[1] == 1)
	{
		vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
		ft_swap(vars->pa, 'a');
	}
	else if (vars->np[0] == 2 && vars->np[1] == 0)
		vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
	else if (vars->np[0] == 0 && vars->np[1] == 2)
	{
		ft_swap(vars->pa, 'a');
		vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
	}
	else if (vars->np[0] == 1 && vars->np[1] == 2)
		vars->pa = ft_reverse_rotate(vars->pa, vars->len_a, 'a');
	free(vars->np);
}

void	ft_five(t_vars *vars)
{
	while (vars->pa[0] != nb_min(vars->pa, vars->len_a))
		vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
	vars->pb = ft_push(vars->pb, &vars->len_b, vars->pa[0], 'b');
	vars->pa = ft_push_balance(vars->pa, &vars->len_a);
	while (vars->pa[0] != nb_max(vars->pa, vars->len_a))
		vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
	vars->pb = ft_push(vars->pb, &vars->len_b, vars->pa[0], 'b');
	vars->pa = ft_push_balance(vars->pa, &vars->len_a);
	ft_three(vars);
	vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
	vars->pb = ft_push_balance(vars->pb, &vars->len_b);
	vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
	vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
	vars->pb = ft_push_balance(vars->pb, &vars->len_b);
	free(vars->pb);
}

t_vars	*ft_sort_choice(t_vars *vars)
{
	if (vars->len_a == 2)
		ft_swap(vars->pa, 'a');
	if (vars->len_a == 3)
		ft_three(vars);
	if (vars->len_a == 4)
		ft_four(vars);
	if (vars->len_a == 5)
		ft_five(vars);
	else
		vars = core(vars);
	return (vars);
}

int	main(int ac, char **av)
{
	t_vars	*vars;
	char	*full_char;
	// int		i;

	if (ac == 1)
		exit(1);
	// i = 0;
	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		exit(1);
	full_char = ft_strjoin(av, ac, vars);
	vars->pa = conversion_char_to_int_array(full_char, ' ', &vars->len_a, vars);
	free(full_char);
	error_duplication(vars->pa, vars->len_a, vars);
	if (crescent(vars->pa, vars->len_a) == 1)
		vars = ft_sort_choice(vars);
	// if (crescent(vars->pa, vars->len_a) == 1)
	// 	vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
	// while (i < vars->len_a)
	// {
	// 	ft_printf("\n%d", vars->pa[i]);
	// 	i++;
	// }
	// ft_printf("\n\n%d", vars->len_a);
	// if (!(crescent(vars->pa, vars->len_a) == 0))
	// {
	// 	ft_swap(vars->pa, 'a');
	// 	vars->pa = ft_reverse_rotate(vars->pa, vars->len_a, 'a');
	// }
	free(vars->pa);
	free(vars);
	return (0);
}

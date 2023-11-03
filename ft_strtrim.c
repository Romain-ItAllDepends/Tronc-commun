/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:54:11 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/02 19:03:57 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen1(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen1(s1);
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strrchr(set, s1[j]))
		j--;
	j = j - i + 1;
	return(ft_substr(s1, i, j));
}

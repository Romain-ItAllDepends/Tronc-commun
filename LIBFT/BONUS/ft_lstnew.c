/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:56:59 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/08 18:45:34 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *newBlock = (t_list *)malloc(sizeof(t_list));

	if (newBlock == 0)
		return (0);
	newBlock->content = content;
	newBlock->next = NULL;
	return newBlock;
}

#include <stdio.h>

int	main(void)
{
	t_list	*tab;
	tab = ft_lstnew("J'aime les kinder bueno.");
	printf("%p\n", tab->content);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:53:59 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/24 02:50:04 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philosopher	*ft_lstnew_philo(void)
{
	t_philosopher	*list;

	list = (t_philosopher *)malloc(sizeof(t_philosopher));
	if (!list)
		return (NULL);
	list->next = NULL;
	return (list);
}

t_fork	*ft_lstnew_fork(void)
{
	t_fork	*list;

	list = (t_fork *)malloc(sizeof(t_fork));
	if (!list)
		return (NULL);
	list->next = NULL;
	return (list);
}

void	ft_lstclear_philo(t_philosopher **lst)
{
	t_philosopher	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	ft_lstclear_fork(t_fork **lst)
{
	t_fork	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	ft_lstadd_back_fork(t_fork **lst, t_fork *new)
{
	t_fork	*tmp;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

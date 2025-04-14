/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halife <halife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:14:19 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/14 13:36:12 by halife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min(t_list *lst)
{
	int	min;
	t_list		*tmp;

	tmp = lst;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_replace_index(t_list *lst, int val, int new)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->data == val)
			break ;
		tmp = tmp->next;
	}
	tmp->index = new;
}

void	ft_give_index(t_list *lst)
{
	int	i;
	int	min;
	int size;

	i = 0;
	size = ft_lstsize(lst);
	while (i < size)
	{
		min = ft_get_min(lst);
		ft_replace_index(lst, min, i);
		i++;
	}
}

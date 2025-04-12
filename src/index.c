/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:14:19 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/12 22:14:20 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_list *lst)
{
	t_list	*tmp;
	long	min;

	tmp = lst;
	min = LONG_MAX;
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
	int	min;
	int	i;

	i = -1;
	while (++i < ft_lstsize(lst))
	{
		min = ft_find_min(lst);
		ft_replace_index(lst, min, i);
	}
}

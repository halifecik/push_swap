/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halife <halife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:14:59 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/14 13:57:25 by halife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted_lst(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_sorted_rev(t_stack *tab)
{
	t_list	*tmp;

	tmp = tab->a;
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_validate_lst(t_list **lst, int count)
{
	if ((ft_lstsize(*lst) != count) || !ft_sorted_lst(lst))
		return (0);
	return (1);
}

t_list	*ft_list_min(t_list **lst)
{
	t_list	*tmp;
	t_list	*min;

	tmp = *lst;
	min = *lst;
	while (tmp)
	{
		if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*ft_list_max(t_list **lst)
{
	t_list	*tmp;
	t_list	*max;

	tmp = *lst;
	max = *lst;
	while (tmp)
	{
		if (tmp->data > max->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

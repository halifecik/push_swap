/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halife <halife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:14:09 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/13 12:13:03 by halife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_begin_sort(t_list **a, t_list **b, t_psh *push, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if ((*a)->index <= push->mid)
			ft_pb(a, b);
		else
		{
			if (ft_lstsize(*b) > 1 && (*b)->index < (push->mid / 2))
				ft_rot_op(a, b, 2);
			else
				ft_rot_op(a, b, 0);
		}
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->check++;
}

void	ft_get_next(t_list **a, t_list **b, t_psh *push)
{
	if (ft_lstsize(*b) > 0 && ((*b)->index == push->next))
		ft_pa(a, b);
	else if ((*a)->index == push->next)
	{
		(*a)->check = -1;
		ft_rot_op(a, b, 0);
		push->next++;
	}
	else if ((ft_lstsize(*b)) > 2 && ft_lstlast(*b)->index == push->next)
		ft_rev_op(a, b, 1);
	else if ((*a)->next->index == push->next)
		ft_swp_op(a, b, 0);
	else if ((ft_lstsize(*a)) > 1 && ((*a)->next->index == push->next)
		&& ((*b)->next->index == push->next + 1))
		ft_swp_op(a, b, 2);
	else
		return ;
	ft_get_next(a, b, push);
}

void	ft_quick_a(t_list **a, t_list **b, t_psh *push)
{
	int	i;

	i = -1;
	while (ft_lstsize(*b) && ++i < ft_lstsize(*b))
	{
		if ((*b)->index == push->next)
			ft_get_next(a, b, push);
		else if ((*b)->index >= push->mid)
		{
			(*b)->check = push->check;
			ft_pa(a, b);
		}
		else if ((*b)->index < push->mid)
			ft_rot_op(a, b, 1);
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->check++;
}

void	ft_quick_b(t_list **a, t_list **b, t_psh *push)
{
	int	current;

	current = (*a)->check;
	if ((*a)->check != 0)
	{
		while ((*a)->check == current)
		{
			if ((*a)->index != push->next)
				ft_pb(a, b);
			ft_get_next(a, b, push);
		}
	}
	else if ((*a)->check == 0)
	{
		while ((*a)->check != -1)
		{
			if ((*a)->index != push->next)
				ft_pb(a, b);
			ft_get_next(a, b, push);
		}
	}
	if (ft_lstsize(*b))
		push->max = (ft_lst_max(b))->index;
	push->mid = (push->max - push->next) / 2 + push->next;
}

void	ft_quick_sort(t_list **a, t_list **b, int count)
{
	t_psh	push;

	push.next = ft_lst_min(a)->index;
	push.max = ft_lst_max(a)->index;
	push.mid = push.max / 2 + push.next;
	push.check = 0;
	ft_begin_sort(a, b, &push, count);
	while (!ft_validate_lst(a, count))
	{
		if (!ft_lstsize(*b))
			ft_quick_b(a, b, &push);
		else
			ft_quick_a(a, b, &push);
	}
}

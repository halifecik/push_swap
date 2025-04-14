/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halife <halife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:14:09 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/14 13:35:16 by halife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_start_sort(t_list **a, t_list **b, t_pivot *pivot, int count)
{
	int b_size;
	int	i;


	i = 0;
	b_size = ft_lstsize(*b);
	while (i < count)
	{
		if ((*a)->index <= pivot->mid)
			ft_pb(a, b);
		else
		{
			if (b_size > 1 && (*b)->index < (pivot->mid / 2))
				ft_rr(a, b);
			else
				ft_ra(a);
		}
		i++;
	}
	pivot->max = pivot->mid;
	pivot->mid = (pivot->max - pivot->next) / 2 + pivot->next;
	pivot->check++;
}

void	ft_get_next(t_list **a, t_list **b, t_pivot *pivot)
{
	int b_size;

	b_size = ft_lstsize(*b);
	if (b_size > 0 && ((*b)->index == pivot->next))
		ft_pa(a, b);
	else if ((*a)->index == pivot->next)
	{
		(*a)->check = -1;
		ft_ra(a);
		pivot->next++;
	}
	else if (b_size > 2 && ft_lstlast(*b)->index == pivot->next)
		ft_reverse(a, b, 1);
	else if ((*a)->next->index == pivot->next)
		ft_sa(a);
	else if (ft_lstsize(*a) > 1 && ((*a)->next->index == pivot->next)
		&& ((*b)->next->index == pivot->next + 1))
		ft_ss(a, b);
	else
		return;
	ft_get_next(a, b, pivot);
}

void	ft_quick_a(t_list **a, t_list **b, t_pivot *pivot)
{
	int	b_size;
	int	i;

	i = 0;
	b_size = ft_lstsize(*b);
	while (ft_lstsize(*b) && i < b_size)
	{
		if ((*b)->index == pivot->next)
			ft_get_next(a, b, pivot);
		else if ((*b)->index >= pivot->mid)
		{
			(*b)->check = pivot->check;
			ft_pa(a, b);
		}
		else if ((*b)->index < pivot->mid)
			ft_rb(b);
		i++;
	}
	pivot->max = pivot->mid;
	pivot->mid = (pivot->max - pivot->next) / 2 + pivot->next;
	pivot->check++;
}

void	ft_quick_b(t_list **a, t_list **b, t_pivot *pivot)
{
	int	current;

	current = (*a)->check;
	if ((*a)->check != 0)
	{
		while ((*a)->check == current)
		{
			if ((*a)->index != pivot->next)
				ft_pb(a, b);
			ft_get_next(a, b, pivot);
		}
	}
	else if ((*a)->check == 0)
	{
		while ((*a)->check != -1)
		{
			if ((*a)->index != pivot->next)
				ft_pb(a, b);
			ft_get_next(a, b, pivot);
		}
	}
	if (ft_lstsize(*b))
		pivot->max = (ft_list_max(b))->index;
	pivot->mid = (pivot->max - pivot->next) / 2 + pivot->next;
}

void	ft_quick_sort(t_list **a, t_list **b, int count)
{
	t_pivot	pivot;

	pivot.next = ft_list_min(a)->index;
	pivot.max = ft_list_max(a)->index;
	pivot.mid = pivot.max / 2 + pivot.next;
	pivot.check = 0;
	ft_start_sort(a, b, &pivot, count);
	while (!(ft_validate_lst(a, count)))
	{
		if (ft_lstsize(*b) == 0)
			ft_quick_b(a, b, &pivot);
		else
			ft_quick_a(a, b, &pivot);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halife <halife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:14:30 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/14 13:52:55 by halife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **a, t_list **b)
{
	t_list	*second_b;

	if (!*b)
		return ;
	second_b = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = second_b;
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **a, t_list **b)
{
	t_list	*second_a;

	if (!*a)
		return ;
	second_a = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = second_a;
	write(1, "pb\n", 3);
}
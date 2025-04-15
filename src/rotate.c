/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:14:56 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/15 12:04:02 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_list **lst)
{
	t_list	*first;

	first = *lst;
	if (!(*lst) || !((*lst)->next))
		return ;
	*lst = first->next;
	first->next = NULL;
	ft_lstlast(*lst)->next = first;
}

void	ft_ra(t_list **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}

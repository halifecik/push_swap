/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:14:56 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/12 22:14:57 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rot(t_list **lst)
{
	t_list	*first;

	first = *lst;
	if (!lst || !*lst || !(*lst)->next)
		return ;
	*lst = first->next;
	first->next = NULL;
	ft_lstlast(*lst)->next = first;
}

void	ft_rot_op(t_list **a, t_list **b, int op)
{
	if (op == 0)
	{
		ft_rot(a);
		write(1, "ra\n", 3);
	}
	else if (op == 1)
	{
		ft_rot(b);
		write(1, "rb\n", 3);
	}
	else if (op == 2)
	{
		ft_rot(a);
		ft_rot(b);
		write(1, "rr\n", 3);
	}
}

static void	ft_rev(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*second_last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	last = ft_lstlast(*lst);
	second_last = *lst;
	while (second_last->next->next)
		second_last = second_last->next;
	second_last->next = NULL;
	last->next = tmp;
	*lst = last;
}

void	ft_rev_op(t_list **a, t_list **b, int op)
{
	if (op == 0)
	{
		ft_rev(a);
		write(1, "rra\n", 4);
	}
	else if (op == 1)
	{
		ft_rev(b);
		write(1, "rrb\n", 4);
	}
	else if (op == 2)
	{
		ft_rev(a);
		ft_rev(b);
		write(1, "rrr\n", 4);
	}
}

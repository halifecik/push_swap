#include "push_swap.h"

void	ft_begin_sort(t_list **a, t_list **b, t_psh *push, int count)
{
	int	i;

	i = -1;
	while (i++ < count)
		if ((*a)->index <= push->mid)
			ft_pb(a, b);
		else
		{
			if (ft_lstsize(*b) > 1 && (*b)->index < (push->mid / 2))
				ft_rot_op(a, b, 2);
			else
				ft_rot_op(a, b, 0);
		}
    push->max = push->mid;
    push->mid = (push->max - push->next) / 2 + push->next;
	push->check++;
}

void ft_get_next(t_list **a, t_list **b, t_psh *push)
{
    if(ft_lstsize(*b) > 0 && ((*b)->index == push->next))
}

void	find_next(t_list **a, t_list **b, t_psh *push)
{
	// If the top element of b is the next element in sorted order, push it to a
	if (ft_lstsize(*b) > 0 && ((*b)->index == push->next))
		pa(a, b);
	// If the top element of a is the next element, rotate it and mark it as sorted
	else if ((*a)->index == push->next)
	{
		(*a)->check = -1;
		ra(a);
		push->next++;
	}
	// If the last element of b is the next element, reverse rotate b
	else if ((ft_lstsize(*b)) > 2 && ft_lstlast(*b)->index == push->next)
		rrb(b);
	// If the second element of a is the next element, swap the top two elements of a
	else if ((*a)->next->index == push->next)
		sa(a);
	// If the top elements of both stacks are consecutive in sorted order, swap both
	else if ((ft_lstsize(*a)) > 1 && ((*a)->next->index == push->next)
		&& ((*b)->next->index == push->next + 1))
		ss(a, b);
	else
		return; // If no condition is met, exit the function
	find_next(a, b, push); // Recursively process the next element
}
#include "pushswap.h"

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

void	ft_pa(t_list **a, t_list **b)
{
	t_list	*second_b;

	if (!b || !*b)
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

	if (!a || !*a)
		return ;
	second_a = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = second_a;
	write(1, "pb\n", 3);
}

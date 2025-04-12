#include "push_swap.h"

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

static void	ft_swp(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	(*lst)->next = tmp;
}

void	ft_swp_op(t_list **a, t_list **b, int op)
{
	if (op == 0)
	{
		ft_swp(a);
		write(1, "sa\n", 3);
	}
	else if (op == 1)
	{
		ft_swp(b);
		write(1, "sb\n", 3);
	}
	else if (op == 2)
	{
		ft_swp(a);
		ft_swp(b);
		write(1, "ss\n", 3);
	}
}

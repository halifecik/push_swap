#include "push_swap.h"

static void	ft_swap(t_list **lst)
{
	t_list	*tmp;

	if (!(*lst) || !((*lst)->next))
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
}

void	ft_sa(t_list **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
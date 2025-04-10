#include "pushswap.h"

static void	ft_swp(t_list **lst)
{
	t_list	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	(*lst)->next = tmp;
}

static void	ft_rot(t_list **lst)
{
	t_list	*first;

	first = *lst;
	if (!*lst || !(*lst)->next)
		return ;
	*lst = first->next;
	first->next = NULL;
	ft_lstlast(*lst)->next = first;
}

void	ft_swp_op(t_list **a, t_list **b, int op)
{
	if (op = 0)
	{
		ft_swp(a);
		write(1, "sa\n", 3);
	}
	else if (op = 1)
	{
		ft_swp(b);
		write(1, "sb\n", 3);
	}
	else if (op = 2)
	{
		ft_swp(a);
		ft_swp(b);
		write(1, "ss\n", 3);
	}
}

void	ft_rot_op(t_list **a, t_list **b, int op)
{
	if (op = 0)
	{
		ft_rot(a);
		write(1, "ra\n", 3);
	}
	else if (op = 1)
	{
		ft_rot(b);
		write(1, "rb\n", 3);
	}
	else if (op = 2)
	{
		ft_rot(a);
		ft_rot(b);
		write(1, "rr\n", 3);
	}
}

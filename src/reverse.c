#include "push_swap.h"

static void	ft_reverse_rotate(t_list **lst)
{
	t_list	*second_last;
	t_list	*last;
	t_list	*tmp;

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

void	ft_reverse(t_list **a, t_list **b, int op)
{
	if(!a || !*a || !b || !*b)
		return ;
	if (op == 0)
	{
		ft_reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	else if (op == 1)
	{
		ft_reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
	else if (op == 2)
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
		write(1, "rrr\n", 4);
	}
}
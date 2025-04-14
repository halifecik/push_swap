#include "push_swap.h"

void	ft_sort_three(t_stack *lst)
{
	t_list	*last;

	if (ft_sorted_lst(&lst->a))
		return ;
	last = ft_lstlast(lst->a);
	if (ft_sorted_rev(lst))
	{
		ft_sa(&lst->a);
		ft_reverse(&lst->a, &lst->b, 0);
	}
	else if (lst->a->data < last->data && lst->a->next->data < last->data)
		ft_sa(&lst->a);
	else if (lst->a->data > last->data && lst->a->next->data < last->data)
		ft_ra(&lst->a);
	else if (lst->a->data < last->data && lst->a->next->data > last->data)
	{
		ft_sa(&lst->a);
		ft_ra(&lst->a);
	}
	else if (lst->a->data > last->data && lst->a->next->data > last->data)
		ft_reverse(&lst->a, &lst->b, 0);
}

void	ft_sort_five(t_stack	*lst)
{
	int	size;

	size = ft_lstsize(lst->a);
	while (size--)
	{
		if (lst->a->index == 0 || lst->a->index == 1)
			ft_pb(&lst->a, &lst->b);
		else
			ft_ra(&lst->a);
	}
	ft_sort_three(lst);
	ft_pa(&lst->a, &lst->b);
	ft_pa(&lst->a, &lst->b);
	if (lst->a->data > lst->a->next->data)
		ft_sa(&lst->a);
}

void	ft_handle_sort(t_stack *lst)
{
	int	size;

	size = ft_lstsize(lst->a);
	if (ft_sorted_lst(&lst->a))
		return ;
	if (size == 2)
	{
		if (lst->a->data > lst->a->next->data)
			ft_sa(&lst->a);
	}
	else if (size == 3)
		ft_sort_three(lst);
	else if (size == 5)
		ft_sort_five(lst);
	else
		ft_quick_sort(&lst->a, &lst->b, ft_lstsize(lst->a));
}
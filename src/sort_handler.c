#include "push_swap.h"

void	ft_sort_three(t_swp *lst)
{
	t_list	*last;

	if (ft_is_sorted(&lst->a))
		return ;
	last = ft_lstlast(lst->a);
	if (ft_rev_sorted(lst))
	{
		ft_swp_op(&lst->a, &lst->b, 0);
		ft_rev_op(&lst->a, &lst->b, 0);
	}
	else if (lst->a->data < last->data && lst->a->next->data < last->data)
		ft_swp_op(&lst->a, &lst->b, 0);
	else if (lst->a->data > last->data && lst->a->next->data < last->data)
		ft_rot_op(&lst->a, &lst->b, 0);
	else if (lst->a->data < last->data && lst->a->next->data > last->data)
	{
		ft_swp_op(&lst->a, &lst->b, 0);
		ft_rot_op(&lst->a, &lst->b, 0);
	}
	else if (lst->a->data > last->data && lst->a->next->data > last->data)
		ft_rev_op(&lst->a, &lst->b, 0);
}

void	ft_sort_five(t_swp *lst)
{
	int	len;

	len = ft_lstsize(lst->a);
	while (len--)
	{
		if (lst->a->index == 0 || lst->a->index == 1)
			ft_pb(&lst->a, &lst->b);
		else
			ft_rot_op(&lst->a, &lst->b, 0);
	}
	ft_sort_three(lst);
	ft_pa(&lst->a, &lst->b);
	ft_pa(&lst->a, &lst->b);
	if (lst->a->data > lst->a->next->data)
		ft_swp_op(&lst->a, &lst->b, 0);
}

void	ft_handle_sort(t_swp *lst)
{
	int	len;

	len = ft_lstsize(lst->a);
	if (ft_is_sorted(&lst->a))
		return ;
	if (len == 2)
		ft_swp_op(&lst->a, &lst->b, 0);
	else if (len == 3)
		ft_sort_three(lst);
	else if (len == 5)
		ft_sort_five(lst);
	else
		ft_quick_sort(&lst->a, &lst->b, len);
}

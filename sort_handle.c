#include "push_swap.h"

void	ft_sort_three(t_swp *lst)
{
    t_list  *first;
    t_list  *second;
	t_list	*last;

	if (ft_is_sorted(lst->a))
		return ;
    first = lst->a->data;
    second = lst->a->next->data;
	last = ft_lstlast(lst)->data;
	if (ft_rev_sorted(lst))
	{
		ft_swp_op(&lst->a, &lst->b, 0);
		ft_rev_op(&lst->a, &lst->b, 0);
	}
	else if (first < last && second < last)
		ft_swp_op(&lst->a, &lst->b, 0);
    else if (first > last && second < last)
        ft_rot_op(&lst->a, &lst->b, 0);
    else if (first < last && second > last)
    {
        ft_swp_op(&lst->a, &lst->b, 0);
        ft_rot_op(&lst->a, &lst->b, 0);
    }
    else if (first > last && second > last)
        ft_rev_op(&lst->a, &lst->b, 0);
}

void ft_sort_five(t_swp *lst)
{
    
}
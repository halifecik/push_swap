#include "pushswap.h"

void	ft_free_lst(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_free_tab(t_swp *tab)
{
	if (!tab)
		return ;
	ft_free_lst(&(tab)->a);
	ft_free_lst(&(tab)->b);
	free(tab);
}

void	ft_free_arg(char **arg)
{
	int i;

    i = -1;
    while(arg[++i])
        free(arg[i]);
    free(arg);
}


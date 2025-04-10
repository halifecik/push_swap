#include "utils.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*node;

	if (!*lst || !lst)
		return ;
	node = *lst;
	while (node)
	{
		node = (*lst)->next;
		(*lst)->data = 0;
		free(*lst);
		*lst = node;
	}
}

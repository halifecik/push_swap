#include "utils.h"

t_list	*ft_lstnew(int content, int index)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = content;
	node->index = index;
	node->next = NULL;
	return (node);
}

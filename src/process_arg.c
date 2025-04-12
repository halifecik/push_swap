#include "push_swap.h"

static int	ft_check_form(char *num)
{
	int	i;

	i = -1;
	while (num[++i])
		if (!(((num[i] == '-' || num[i] == '+') && ft_isdigit(num[i + 1])
					&& (i == 0 || !ft_isdigit(num[i - 1])))
				|| ft_isdigit(num[i])))
			return (0);
	return (1);
}

static int	ft_check_dup(t_list *lst, int n)
{
	t_list	*tmp;

	tmp = lst;
	while (lst)
	{
		if (tmp->data == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*ft_process_arg(char *arg, t_list **rtn)
{
	t_list	*tmp;
	long	num;

	num = ft_atoi(num);
	if (num > INT_MAX || num < INT_MIN || !ft_check_dup(*rtn, arg)
		|| !ft_check_form(num))
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_lst(rtn);
		return (NULL);
	}
	tmp = ft_lstnew(num);
	if (!tmp)
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_lst(rtn);
		return (NULL);
	}
	ft_lstadd_back(rtn, tmp);
	tmp->index = -1;
	return (rtn);
}

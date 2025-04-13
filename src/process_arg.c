/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halife <halife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:14:27 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/13 13:05:39 by halife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_arg(char *arg)
{
	int		i;

	i = -1;
	while (arg[++i])
		if (!(((arg[i] == '-' || arg[i] == '+') && ft_isdigit(arg[i + 1])
					&& (i == 0 || !ft_isdigit(arg[i - 1])) )
				|| ft_isdigit(arg[i])))
			return (0);
	return (1);
}

static int ft_check_dup(t_list *lst, int num)
{
	t_list *tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->data == num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*ft_process_arg(char *arg, t_list **rtn)
{
	t_list	*tmp;
	long	num;

	num = ft_atoi(arg);
	if (num > INT_MAX || num < INT_MIN || (!ft_check_arg(arg) && ft_check_dup(*rtn, num)))
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
	return (*rtn);
}

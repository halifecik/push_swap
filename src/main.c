/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halife <halife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:14:22 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/13 12:59:01 by halife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_initialize_lst(int argc, char **arg)
{
	int		i;
	t_list	*rtn;

	i = 1;
	if (argc == 2)
		i = 0;
	rtn = NULL;
	while (arg[i])
	{
		if (!ft_process_arg(arg[i], &rtn))
			return (NULL);
		i++;
	}
	return (rtn);
}

static t_swp	*ft_initialize_tab(void)
{
	t_swp	*tab;

	tab = malloc(sizeof(t_swp));
	if (!tab)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	tab->a = NULL;
	tab->b = NULL;
	return (tab);
}

static int	ft_setup_lst(t_swp *lst, char **arg, int argc)
{
	lst->a = ft_initialize_lst(argc, arg);
	if (argc == 2)
		ft_free_arg(arg);
	if (!lst->a)
	{
		ft_free_tab(lst);
		return (0);
	}
	lst->b = NULL;
	lst->a_size = ft_lstsize(lst->a);
	lst->b_size = ft_lstsize(lst->b);
	ft_give_index(lst->a);
	return (1);
}

static char	**ft_format_arg(int argc, char **argv)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (argv);
}

int	main(int argc, char **argv)
{
	t_swp	*tab;
	char	**arguments;

	if (argc == 1)
		return (0);
	tab = ft_initialize_tab();
	if (!tab)
		return (-1);
	arguments = ft_format_arg(argc, argv);
	if (!arguments)
	{
		ft_free_tab(tab);
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (!ft_setup_lst(tab, arguments, argc))
		return (-1);
	ft_handle_sort(tab);
	ft_free_tab(tab);
	return (0);
}

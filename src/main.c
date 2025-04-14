/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halife <halife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:14:22 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/14 16:18:34 by halife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_initialize_list(int argc, char **argv)
{
	t_list	*rtn;  
	int		i;

	i = 1;
	if (argc == 2)
		i = 0;
	rtn = NULL;
	while (argv[i])
	{
		if (!ft_process_arg(argv[i], &rtn))
			return (NULL);
		i++;
	}
	return (rtn);
}

static t_stack	*ft_initialize_tab(void)
{
	t_stack	*tab;

	tab = malloc(sizeof(t_stack));
	if (!tab)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	tab->a = NULL;
	tab->b = NULL;
	return (tab);
}

static int	ft_setup_list(t_stack *tab, int argc, char **argv)
{
	tab->a = ft_initialize_list(argc, argv);
	if (argc == 2)
		ft_free_arg(argv);
	if (!tab->a)
	{
		ft_free_tab(tab);
		return (0);
	}
	tab->b = NULL;
	tab->size_a = ft_lstsize(tab->a);
	tab->size_b = ft_lstsize(tab->b);
	ft_give_index(tab->a);
	return (1);
}

static char	**ft_seperate_arg(int argc, char **argv)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (argv);
}

int	main(int argc, char **argv)
{
	t_stack	*tab;
	char	**arguments;

	if (argc == 1)
		return (0);
	tab = ft_initialize_tab();
	if (!tab)
		return (-1);
	arguments = ft_seperate_arg(argc, argv);
	if (!arguments)
	{
		ft_free_tab(tab);
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (!ft_setup_list(tab, argc, arguments))
		return (-1);
	ft_handle_sort(tab);
	ft_free_tab(tab);
	return (0);
}
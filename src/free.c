/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halife <halife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:14:13 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/14 13:35:50 by halife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free_lst(t_list **lst)
{
    t_list *tmp;

    if (!lst || !*lst)
        return;
    while (*lst)
    {
        tmp = (*lst)->next;
        free(*lst);
        *lst = tmp;
    }
    *lst = NULL;
}

void ft_free_tab(t_stack *tab)
{
    if (!tab)
        return;
    ft_free_lst(&(tab->a));
    ft_free_lst(&(tab->b));
    free(tab);
}

void ft_free_arg(char **arg)
{
    int i;

    i = -1;
    if (!arg || !*arg)
        return;
    while (arg[++i])
        free(arg[i]);
    free(arg);
}
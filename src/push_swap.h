/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halife <halife@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:14:50 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/14 13:53:59 by halife           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../utils/utils.h"
# include <limits.h>

typedef struct s_pivot
{
	int		next;
	int		max;
	int		mid;
	int		check;
}			t_pivot;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		size_b;
}			t_stack;

void		ft_free_lst(t_list **lst);
void		ft_free_tab(t_stack *tab);
void		ft_free_arg(char **arg);

int			ft_get_min(t_list *lst);
void		ft_replace_index(t_list *lst, int val, int new);
void		ft_give_index(t_list *lst);

t_list		*ft_process_arg(char *arg, t_list **res);

void		ft_pa(t_list **a, t_list **b);
void		ft_pb(t_list **a, t_list **b);

void		ft_sa(t_list **a);
void		ft_sb(t_list **b);
void		ft_ss(t_list **a, t_list **b);

void		ft_ra(t_list **a);
void		ft_rb(t_list **b);
void		ft_rr(t_list **a, t_list **b);
void		ft_reverse(t_list **a, t_list **b, int op);

t_list		*ft_list_min(t_list **lst);
t_list		*ft_list_max(t_list **lst);
int			ft_sorted_lst(t_list **lst);
int			ft_sorted_rev(t_stack *tab);
int			ft_validate_lst(t_list **lst, int count);

void	ft_sort_five(t_stack *lst);
void	ft_sort_three(t_stack *lst);
void	ft_handle_sort(t_stack *lst);

void	ft_start_sort(t_list **a, t_list **b, t_pivot *pivot, int count);
void	ft_get_next(t_list **a, t_list **b, t_pivot *pivot);
void	ft_quick_a(t_list **a, t_list **b, t_pivot *pivot);
void	ft_quick_b(t_list **a, t_list **b, t_pivot *pivot);
void	ft_quick_sort(t_list **a, t_list **b, int count);

#endif
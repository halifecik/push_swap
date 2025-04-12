/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:14:50 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/12 22:14:51 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../utils/utils.h"
# include <limits.h>

typedef struct s_psh
{
	int		next;
	int		max;
	int		mid;
	int		check;
}			t_psh;

typedef struct s_swp
{
	t_list	*a;
	t_list	*b;
	int		a_size;
	int		b_size;
}			t_swp;

void		ft_quick_a(t_list **a, t_list **b, t_psh *push);
void		ft_quick_b(t_list **a, t_list **b, t_psh *push);
void		ft_quick_sort(t_list **a, t_list **b, int count);
void		ft_get_next(t_list **a, t_list **b, t_psh *push);
void		ft_begin_sort(t_list **a, t_list **b, t_psh *push, int count);

void		ft_free_tab(t_swp *tab);
void		ft_free_arg(char **arg);
void		ft_free_lst(t_list **lst);

int			ft_find_min(t_list *lst);
void		ft_give_index(t_list *lst);
void		ft_replace_index(t_list *lst, int val, int new);

t_list		*ft_process_arg(char *arg, t_list **rtn);

void		ft_pa(t_list **a, t_list **b);
void		ft_pb(t_list **a, t_list **b);
void		ft_swp_op(t_list **a, t_list **b, int op);

void		ft_rot_op(t_list **a, t_list **b, int op);
void		ft_rev_op(t_list **a, t_list **b, int op);

int			ft_rev_sorted(t_swp *lst);
t_list		*ft_lst_min(t_list **lst);
t_list		*ft_lst_max(t_list **lst);
int			ft_is_sorted(t_list **lst);
int			ft_validate_lst(t_list **lst, int count);

void		ft_sort_five(t_swp *lst);
void		ft_sort_three(t_swp *lst);
void		ft_handle_sort(t_swp *lst);

#endif
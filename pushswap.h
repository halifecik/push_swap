#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "includes/utils.h"

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

void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **a, t_list **b);
void	ft_swp_op(t_list **a, t_list **b, int op);
void	ft_rot_op(t_list **a, t_list **b, int op);
void	ft_rev_op(t_list **a, t_list **b, int op);

#endif
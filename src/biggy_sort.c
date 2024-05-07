/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggy_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 23:46:51 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:27:57 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_best_elems(t_list **stack_a, t_list **stack_b)
{
	int	list_size;
	int	count;
	int	a;
	int	b;
	int	tmp;

	list_size = ft_list_size(*stack_a);
	count = 0;
	a = 1;
	while (a <= list_size)
	{
		b = ft_seek_elem_b(stack_a, stack_b, a);
		tmp = ft_count_op(*stack_a, *stack_b, a, b);
		if (count == 0 || tmp < count)
		{
			count = tmp;
			ft_reset_best(stack_a, stack_b);
			ft_setup_best(stack_a, stack_b, a, b);
		}
		a++;
	}
}

void	ft_setup(t_list **stack_a, t_list **stack_b, int pos_a, int pos_b)
{
	int	a_down;
	int	b_down;
	int	nb_op;
	int	tmp;

	a_down = ft_list_size(*stack_a) - pos_a + 1;
	b_down = ft_list_size(*stack_b) - pos_b + 1;
	nb_op = ft_count_up_down(pos_a - 1, pos_b - 1);
	ft_setup_up(*stack_a, *stack_b, pos_a - 1, pos_b - 1);
	tmp = ft_count_up_down(a_down, b_down);
	if (tmp < nb_op)
	{
		nb_op = tmp;
		ft_setup_down(*stack_a, *stack_b, a_down, b_down);
	}
	tmp = ft_count_all(pos_a - 1, pos_b - 1, a_down, b_down);
	if (tmp < nb_op)
		ft_setup_all(*stack_a, *stack_b, a_down, b_down);
}

void	ft_do_instructions(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;

	a = ft_best_to_elem(*stack_a);
	b = ft_best_to_elem(*stack_b);
	ft_setup(stack_a, stack_b, ft_pos(*stack_a), ft_pos(*stack_b));
	ft_double_up(stack_a, stack_b, a, b);
	ft_double_down(stack_a, stack_b, a, b);
	ft_do_up_down(stack_a, stack_b, a, b);
	do_pb(stack_a, stack_b);
}

void	ft_fill_stack(t_list **stack_a, t_list **stack_b)
{
	int		lst_size;
	int		tmp;
	int		tab[MIDDY];
	t_list	*elem;

	elem = NULL;
	tmp = 0;
	ft_fill_tab(*stack_a, tab, MIDDY);
	lst_size = ft_list_size(*stack_b);
	if (ft_ismax(*stack_a, (*stack_b)->value))
	{
		do_pa(stack_b, stack_a);
		lst_size--;
	}
	while (lst_size-- > 0)
	{
		elem = *stack_a;
		tmp = ft_seek_couple(tab, elem->value, (*stack_b)->value);
		if (tmp != (*stack_a)->value)
			ft_move_best(stack_a, tmp);
		do_pa(stack_b, stack_a);
	}
}

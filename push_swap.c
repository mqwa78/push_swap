/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:07:16 by mamahtal          #+#    #+#             */
/*   Updated: 2024/03/28 01:07:55 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tiny(t_list **stack, int min, int max, int last)
{
	if ((*stack)->value == min)
	{
		do_sa(stack);
		do_ra(stack);
	}
	else if ((*stack)->value == max)
	{
		if (last == min)
		{
			do_sa(stack);
			do_rra(stack);
		}
		else
			do_ra(stack);
	}
	else
	{
		if (last == min)
			do_rra(stack);
		else
			do_sa(stack);
	}
}

void	ft_tiny_sort(t_list **stack)
{
	int	min;
	int	max;
	int	last;

	if (!stack || !(*stack))
		return ;
	min = ft_get_min(*stack);
	max = ft_get_max(*stack);
	last = ft_get_value(*stack, 3);
	if (!ft_lst_is_sort(*stack))
		ft_tiny(stack, min, max, last);
}

void	ft_middy_sort(t_list **stack_a, t_list **stack_b)
{
	int	pos;
	int	min;

	pos = ft_get_position(*stack_a, ft_get_min(*stack_a));
	if (pos < 3)
	{
		while (--pos)
			do_ra(stack_a);
	}
	else if (pos >= 3)
	{
		while (pos++ <= 4)
			do_rra(stack_a);
	}
	do_pb(stack_a, stack_b);
	ft_tiny_sort(stack_a);
	do_pa(stack_a, stack_b);
}

void	ft_biggy_sort(t_list **stack_a, t_list **stack_b)
{
	int	list_size;

	do_pb(stack_a, stack_b);
	do_pb(stack_a, stack_b);
	list_size = ft_list_size(*stack_a);
	while (list_size > 3)
	{
		ft_best_elems(stack_a, stack_b);
		ft_do_instructions(stack_a, stack_b);
		ft_reset_values(stack_a, stack_b);
		list_size--;
	}
	ft_tiny_sort(stack_a);
	ft_fill_stack(stack_a, stack_b);
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_list_size(*stack_a);
	if (size < 2)
		return ;
	if (size == 2)
		do_sa(stack_a);
	else if (size == 3)
		ft_tiny_sort(stack_a);
	else if (size == 4)
		ft_middy_sort(stack_a, stack_b);
	else if (size > 4)
		ft_biggy_sort(stack_a, stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:07:16 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:29:22 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_middy_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	pos;
	int	tmp;

	tmp = size;
	while (size > 3)
	{
		pos = ft_get_position(*stack_a, ft_get_min(*stack_a));
		if (pos < (ft_list_size(*stack_a) / 2) + 1)
		{
			while (--pos)
				do_ra(stack_a);
		}
		else
		{
			while (pos++ <= ft_list_size(*stack_a))
				do_rra(stack_a);
		}
		do_pb(stack_a, stack_b);
		size--;
	}
	ft_tiny_sort(stack_a);
	while (tmp-- > 3)
		do_pa(stack_b, stack_a);
}

void	ft_biggy_sort(t_list **stack_a, t_list **stack_b)
{
	int	list_size;

	do_pb(stack_a, stack_b);
	do_pb(stack_a, stack_b);
	list_size = ft_list_size(*stack_a);
	while (list_size > MIDDY)
	{
		ft_best_elems(stack_a, stack_b);
		ft_do_instructions(stack_a, stack_b);
		ft_reset_best(stack_a, stack_b);
		list_size--;
	}
	ft_middy_sort(stack_a, stack_b, list_size);
	ft_sort_stack(stack_b);
	ft_fill_stack(stack_a, stack_b);
	while (!ft_lst_is_sort(*stack_a))
		do_rra(stack_a);
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
	else if (size <= 11)
		ft_middy_sort(stack_a, stack_b, size);
	else if (size > 11)
		ft_biggy_sort(stack_a, stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 04:59:28 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:29:01 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_best_to_elem(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->best)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	ft_pos(t_list *stack)
{
	int	pos;

	if (!stack)
		return (0);
	pos = 1;
	while (stack)
	{
		if (stack->best)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}

void	ft_sort_stack(t_list **stack)
{
	int	max;
	int	pos;

	max = ft_get_max(*stack);
	pos = ft_get_position(*stack, max);
	if (pos < ft_list_size(*stack))
	{
		while (--pos)
			do_rb(stack);
	}
	else
	{
		while (pos++ <= ft_list_size(*stack))
			do_rrb(stack);
	}
}

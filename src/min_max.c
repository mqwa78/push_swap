/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:38:09 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:29:15 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_min(t_list *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	ft_get_max(t_list *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

t_bool	ft_ismin(t_list *stack, int value)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->value < value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_bool	ft_ismax(t_list *stack, int value)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->value > value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

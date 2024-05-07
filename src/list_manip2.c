/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:15:28 by mqwa              #+#    #+#             */
/*   Updated: 2024/05/07 00:28:56 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	ft_isdoublon(t_list **stack, int value)
{
	t_list	*current;

	current = *stack;
	if (!current)
		return (1);
	while (current)
	{
		if (current->value == value)
			return (0);
		current = current->next;
	}
	return (1);
}

t_bool	ft_lst_is_sort(t_list *stack)
{
	t_list	*current;
	int		compare;

	current = stack;
	if (!current || !current->next)
		return (1);
	compare = current->value;
	current = current->next;
	while (current)
	{
		if (current->value < compare)
			return (0);
		compare = current->value;
		current = current->next;
	}
	return (1);
}

int	ft_get_value(t_list *stack, int pos)
{
	int	value;

	if (!stack)
		return (0);
	while (--pos)
		stack = stack->next;
	value = stack->value;
	return (value);
}

int	ft_get_position(t_list *stack, int value)
{
	int	pos;

	if (!stack)
		return (0);
	pos = 1;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}

t_list	*ft_get_elem(t_list *stack, int pos)
{
	t_list	*elem;

	elem = NULL;
	if (!stack)
		return (elem);
	while (--pos)
		stack = stack->next;
	elem = stack;
	return (elem);
}

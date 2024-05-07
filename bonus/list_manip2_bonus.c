/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:00:26 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 01:00:38 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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

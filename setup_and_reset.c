/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_and_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 04:51:40 by mamahtal          #+#    #+#             */
/*   Updated: 2024/03/28 05:09:26 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reset_best(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	if (!*stack_a || !*stack_b)
		return ;
	current = *stack_a;
	while (current)
	{
		current->best = 0;
		current = current->next;
	}
	current = *stack_b;
	while (current)
	{
		current->best = 0;
		current = current->next;
	}
}

void	ft_setup(t_list **stack_a, t_list **stack_b, int a, int b)
{
	t_list	*elem_a;
	t_list	*elem_b;

	elem_a = ft_get_elem(*stack_a, a);
	elem_b = ft_get_elem(*stack_b, b);
	elem_a->best = 1;
	elem_b->best = 1;
}

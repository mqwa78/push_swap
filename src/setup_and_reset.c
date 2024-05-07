/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_and_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 04:51:40 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:29:41 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_setup_best(t_list **stack_a, t_list **stack_b, int a, int b)
{
	t_list	*elem_a;
	t_list	*elem_b;

	elem_a = ft_get_elem(*stack_a, a);
	elem_b = ft_get_elem(*stack_b, b);
	elem_a->best = 1;
	elem_b->best = 1;
}

void	ft_reset_all_var(t_list *elem_a, t_list *elem_b)
{
	elem_a->do_up = 0;
	elem_a->do_down = 0;
	elem_a->double_up = 0;
	elem_a->double_down = 0;
	elem_b->do_up = 0;
	elem_b->do_down = 0;
	elem_b->double_up = 0;
	elem_b->double_down = 0;
}

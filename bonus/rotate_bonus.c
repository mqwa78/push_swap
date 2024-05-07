/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:12:17 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 01:12:54 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_list_rotate(t_list **stack)
{
	t_list	*end;
	t_list	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	end = ft_last_elem(*stack);
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = NULL;
	end->next = tmp;
}

void	do_ra(t_list **stack_a)
{
	ft_list_rotate(stack_a);
}

void	do_rb(t_list **stack_b)
{
	ft_list_rotate(stack_b);
}

void	do_rr(t_list **stack_a, t_list **stack_b)
{
	ft_list_rotate(stack_a);
	ft_list_rotate(stack_b);
}

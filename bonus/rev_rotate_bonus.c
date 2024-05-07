/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 01:13:50 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 01:14:16 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_rev_rotate(t_list **stack)
{
	t_list	*end;
	t_list	*pre_end;
	t_list	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	end = ft_last_elem(*stack);
	pre_end = ft_before_last_elem(*stack);
	tmp = (*stack);
	(*stack) = end;
	(*stack)->next = tmp;
	pre_end->next = NULL;
}

void	do_rra(t_list **stack_a)
{
	ft_rev_rotate(stack_a);
}

void	do_rrb(t_list **stack_b)
{
	ft_rev_rotate(stack_b);
}

void	do_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
}

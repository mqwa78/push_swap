/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:31:19 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:29:31 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	reverse_rotate :
	Decale tous les elements de la liste vers le bas.
	Le dernier element devient le premier.
*/

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
	write(1, "rra\n", 4);
}

void	do_rrb(t_list **stack_b)
{
	ft_rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	do_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}

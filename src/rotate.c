/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:17:20 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:29:36 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	ft_list_rotate :
	Decale d une position vers le haut tous les elements de la pile.
	Le premier element devient le dernier.
*/

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
	write(1, "ra\n", 3);
}

void	do_rb(t_list **stack_b)
{
	ft_list_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	do_rr(t_list **stack_a, t_list **stack_b)
{
	ft_list_rotate(stack_a);
	ft_list_rotate(stack_b);
	write(1, "rr\n", 3);
}

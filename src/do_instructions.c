/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:33:45 by mamahtal          #+#    #+#             */
/*   Updated: 2024/05/07 00:28:22 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_double_up(t_list **stack_a, t_list **stack_b, t_list *a, t_list *b)
{
	if (!(a->double_up) && !(b->double_up))
		return ;
	while (a->double_up > 0 || b->double_up > 0)
	{
		do_rr(stack_a, stack_b);
		a->double_up--;
		b->double_up--;
	}
}

void	ft_double_down(t_list **stack_a, t_list **stack_b, t_list *a, t_list *b)
{
	if (!(a->double_down) && !(b->double_down))
		return ;
	while (a->double_down > 0 || b->double_down > 0)
	{
		do_rrr(stack_a, stack_b);
		a->double_down--;
		b->double_down--;
	}
}

void	ft_do_up_down(t_list **stack_a, t_list **stack_b, t_list *a, t_list *b)
{
	while (a->do_up > 0 || b->do_up > 0)
	{
		if (a->do_up)
		{
			do_ra(stack_a);
			a->do_up--;
		}
		else if (b->do_up--)
			do_rb(stack_b);
	}
	while (a->do_down > 0 || b->do_down > 0)
	{
		if (a->do_down)
		{
			do_rra(stack_a);
			a->do_down--;
		}
		else if (b->do_down--)
			do_rrb(stack_b);
	}
}
